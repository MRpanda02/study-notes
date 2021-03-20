



WEB后端开发：提供服务

\>静态文件服务

\>API接口设计

\>数据库设计

\>缓存，异步任务，云服务...

待复习：

1. 进程携程线程

2. server环境
3. 三次握手

# 1. WSGI

根据规范，将web服务端分成两部分，`server`和`application`。

`server`只负责和客户端进行协议的交互和调用所需数据的函数。负责提供高效的处理HTTP请求的环境！！

运用线程池，采用多线程的方式。推荐gunicom,uwsgi框架。

`application`是逻辑函数，负责处理数据和提供数据。



# 2. django中创建app

可通过执行`python3 manage.py startapp name`

创建一个目录名为name，对应一个名为name的app



# 3. 实现url路由功能

功能复杂时，将路由表分级

```python
##总表##
from django.contrib import admin
from django.urls import path,include

urlpatterns = [
    path('admin/', admin.site.urls),
    
    path('sales/',include('sales.urls_sales_part')),				
    #如果以sales/开头，在sales.urls_sales_part文件里的路由列表找
]
##2级表##

from django.urls import path, include

from sales.views import *

urlpatterns = [

    path('orders/', listorders()),			#在2级表要把上一级表所示别的部分去掉
]
```



4. # 在Django中mysql

## 4.1 配置

一. 在setting中设置

```
DATABASES ={
'default': {
'ENGINE': 'django.db.backends.mysql',　　# 数据库引擎
'NAME': 'django',　　　　　　　　　　　　　　# 你要存储数据的库名，事先要创建之
'USER': 'django',　　　　　　　　　　　　　　# 数据库用户名
'PASSWORD': 'django@123',　　　　　　　　　# 密码
'HOST': 'localhost',　　　　　　　　　　　　# 主机
'PORT': '3306',　　　　　　　　　　　　　　 # 数据库使用的端口
	}
}
```

二.在python环境下安装pymysql: `pip3 install pymysql`

三. 在项目文件夹下的__init__.py添加如下代码：

```python
import pymysql
pymysql.install_as_MySQLdb()
```

四.执行数据库迁移命令：

```python
python3 manage.py makemigrations	#制作mysql数据库表的脚本
python3 manage.py migarte        	#为改动创建迁移记录（实质上创建了数据库表）
```

## 4.2 定义数据库表（ORM）

数据库 `表定义和表记录之间的关系`就像`类和实例`之间的关系，django就让开发者通过==类==和==实例==的操作来对应==数据库表==和==记录==的操作。

Django里面， 数据库表的操作，包括表的定义、表中数据的增删改查，都可以通过**Model** 类型的对象进行的。

通常，在Django中

- 定义一张数据库的表 就是定义一个继承自 django.db.models.Model 的类
- 定义该表中的字段（列）， 就是定义该类里面的一些属性
- 类的方法就是对该表中数据的处理方法，包括 数据的增删改查

这种 通过 对象 操作数据库 的方法 被称之为 ORM （object relational mapping）

定义方法：

数据库表的定义，一般是放在app目录中的models.py里面的。

```python
from django.db import models

class Customer(models.Model):		#继承自django.db.models.Model，就是用来定义数据库表的
  	#为三个字段
    name = models.CharField(max_length=200)

    phonenumber = models.CharField(max_length=200)

    address = models.CharField(max_length=200)
```

| 字段对象类型                          | 数据库字段                                                   |
| ------------------------------------- | ------------------------------------------------------------ |
| AutoField                             | 根据ID自增长.如果没在别的字段上指定主键,Django就会自动添加主键字段. |
| CharField                             | 字符串字段,对小字符串和大字符串都适用.对于更大的文本,应该使用TextField,必须传入参数:max_length,作用于数据库层级和Django的数据验证层级. |
| DateField                             | 该字段利用Python的datatime.data实例来表示日期                    auto_now=True每次保存对象时,Django都会自动将该字段的值设置为当前时间.一般用来表示"最后修改"时间.                                    auto_now_add=True第一次创建对象时,Django将改字段的值设置为当前时间,一般用来表示对象创建时间.                                                                    当auto_now或者auto_now_add设置为True时,字段会有editable=True和blank=True的设定. |
| DateTimeField                         | 该字段利用datetime.datetime实例表示日期和时间.该字段所接受的参数和DateField一样. |
| URLField                              | 保存 URL 的 CharField .                                                                          和所有 CharField 子类一样，URLField 接受可选的 max_length 参数，该参数默认值是200. |
| IntegerField                          | 正数字段                                                     |
| FloatField                            | 该字段在 Python 中使用float 实例来表示一个浮点数             |
| DecimalField                          | （max_digits=None，decimal_places=None[, **options]）             用decimal实例表示固定精度的十进制数的字段，有两个必须参数，max_digits数字允许的最大位数，decimal_places小数的最大位数。django后台用表示该字段， 通常用来表示金额 |
| EmailField([maxlength=75, **options]) | 带有email合法性检测的一个CharField                           |
| BigIntegerField                       | 64位的整型数值 (-2^63) – (2^63-1)                            |

## 4.3 真正创建数据库表

要告诉Django关注该model所属的app,在项目的配置文件`settings.py`中

```python
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',

    # 加入下面这行
    'common.apps.CommonConfig',
]

class CommonConfig(AppConfig):
    name = 'common'
```

CommonConfig 是 common/apps.py 文件中定义的一个应用配置的类

关注app成功后，在项目根目录下执行命令

```python
python3 manage.py makemigrations common
#功能：告诉django，去产生相应的app里面的dodels.py的更新脚本，这个脚本就是相应要进行的数据库操作代码（作用相当于git add)
python3 manage.py migrate
#真正去数据库创建表(作用相当于git commit)
```

5. # Django Admin 管理数据

Django提供了一个管理员操作界面可以方便的 添加、修改、删除你定义的 model 表数据。

首先，需要创建一个超级管理员账号。

```
python3 manage.py createsuperuser
Username (leave blank to use 'byhy'): 
Email address: 
Password:
Password (again):
Superuser created successfully.
```

然后需要修改应用里面的管理员配置文件 common/admin.py，注册我们定义的model类。这样Django才会知道

```
from django.contrib import admin

from .models import Customer

admin.site.register(Customer)
```

上面的界面 Django 内置的给管理员使用的。只是实现了一些通用的功能，而且界面语言偏英语的。

在实际的工作项目中， 还是需要自己开发前端界面给他们使用。



6. # 读区数据库数据

## 6.1 查询所有记录 

当访问sales/customers/时，要返回customer表的所有记录

要在文件sales/views.py中，定义函数：

```python
#导入 Customer 对象定义
from  common.models import Customer

def listcustomers(request):
    # 返回一个 QuerySet 对象 ，包含所有的表记录
    # 每条表记录都是是一个dict对象，
    # key 是字段名，value 是 字段值
    # objects是models.Model父类中的方法属性
    qs = Customer.objects.values()

    # 定义返回字符串
    retStr = ''
    for customer in  qs:
        for name,value in customer.items():
            retStr += f'{name} : {value} | '

        # <br> 表示换行
        retStr += '<br>'

    return HttpResponse(retStr)
```

同时把该函数放到url路由配置里面即可

## 6.2 过滤条件

比如，当用户在浏览器输入 `/sales/customers/?phonenumber=13000000001` ，要求返回电话号码为 13000000001 客户记录

可以通过filter方法加入过滤条件，修改view里面的代码，如下所示

```python
def listcustomers(request):
    #request包含了请求的数据信息
    # 返回一个 QuerySet 对象 ，包含所有的表记录
    qs = Customer.objects.values()

    # 检查url中是否有参数phonenumber
    # 获取querystring(url)里面的phonenumber参数
    # 如果没有phonenumber则返回None
    # 如果有，则返回phonenumber=后面的参数
    ph =  request.GET.get('phonenumber',None)

    # 如果有，添加过滤条件
    # 相当于select * from common_customers where phonenumber=......
    # 此时的phonenumber是数据库表的属性名
    if ph:
        qs = qs.filter(phonenumber=ph)

    # 定义返回字符串
    retStr = ''
    for customer in  qs:
        for name,value in customer.items():
            retStr += f'{name} : {value} | '
        # <br> 表示换行
        retStr += '<br>'

    return HttpResponse(retStr)
```

Django 框架在 url 路由匹配到函数后， 调用函数时，会传入 一个 HttpRequest 对象给参数变量 request，该对象里面 包含了请求的数据信息

HTTP 的 Get 请求url里面的参数(术语叫 querystring 里面的参数), 可以通过 HttpRequest对象的 GET 属性获取。这是一个类似dict的对象

> 多个参数之间用&相隔

# 7. 前后端分离的架构

可以使用Python直接构建出HTML字符串的内容，用一个变量html_template存储html模板，然后代码中生成html里面需要插入的表格记录的内容，这个内容是htnl片段，也就是html表格的每行。

最后填入到html_template模版里面，就产生了完成的HTML字符串，最后返回该html文档字符串即可。

```python
# 先定义好HTML模板
html_template ='''
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>
table {
    border-collapse: collapse;
}
th, td {
    padding: 8px;
    text-align: left;
    border-bottom: 1px solid #ddd;
}
</style>
</head>
    <body>
        <table>
        <tr>
        <th>id</th>
        <th>姓名</th>
        <th>电话号码</th>
        <th>地址</th>
        </tr>
        
        %s
        
        
        </table>
    </body>
</html>
'''

def listcustomers(request):
    # 返回一个 QuerySet 对象 ，包含所有的表记录
    qs = Customer.objects.values()

    # 检查url中是否有参数phonenumber
    ph =  request.GET.get('phonenumber',None)

    # 如果有，添加过滤条件
    if ph:
        qs = qs.filter(phonenumber=ph)

    # 生成html模板中要插入的html片段内容
    tableContent = ''
    for customer in  qs:
        tableContent += '<tr>'

        for name,value in customer.items():
            tableContent += f'<td>{value}</td>'

        tableContent += '</tr>'

    return HttpResponse(html_template%tableContent)
```



## 7.1 使用模板

上述方式，在稍微复杂的情况下后端的代码处理会非常麻烦，不好维护。

很多后端框架提供了一种模版技术，可以在html中嵌入编程语言代码片段，用模版引擎(一个专门处理HTML模板的库)来动态生成HTML代码

使用Django的模板引擎

```python
# 先定义好HTML模板
html_template ='''
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>
table {
    border-collapse: collapse;
}
th, td {
    padding: 8px;
    text-align: left;
    border-bottom: 1px solid #ddd;
}
</style>
</head>
    <body>
        <table>
        <tr>
        <th>id</th>
        <th>姓名</th>
        <th>电话号码</th>
        <th>地址</th>
        </tr>

        {% for customer in customers %}
            <tr>

            {% for name, value in customer.items %}            
                <td>{{ value }}</td>            
            {% endfor %}
            
            </tr>
        {% endfor %}
                
        </table>
    </body>
</html>
'''

from django.template import engines
django_engine = engines['django']
template = django_engine.from_string(html_template)

def listcustomers(request):
    # 返回一个 QuerySet 对象 ，包含所有的表记录
    qs = Customer.objects.values()

    # 检查url中是否有参数phonenumber
    ph =  request.GET.get('phonenumber',None)

    # 如果有，添加过滤条件
    if ph:
        qs = qs.filter(phonenumber=ph)

    # 传入渲染模板需要的参数
    rendered = template.render({'customers':qs})

    return HttpResponse(rendered)
```

对比Python直接产生HTML，使用模板引擎的好处，就是产生HTML的代码更简单方便了

可以直接把药生成的HTML片段写在HTML模板里

然后传入渲染模板所需要的参数就可以了

# 8. 对资源的增删改查处理

