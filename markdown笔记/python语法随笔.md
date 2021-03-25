# python语法随笔

1. 字符串输出（

```python
print('%s'%'hello world')  #字符串输出
hello world

print('%20s'%'hello world')   #右对齐，取20位，不够则补位
          hello world
    
print('%-20s'%'hello world')   #左对齐，取20位，不够则补位
hello world

print('%.2s'%'hello world')   #取2位
he

print('%10.2s'%'hello world')   #右对齐，取2位
       he

print('%-10.2s'%'hello world')   #左对齐，取2位
he
```

format用法

```python
1 >>> print('{} {}'.format('hello','world'))  # 不带字段
 2 hello world
 3 >>> print('{0} {1}'.format('hello','world'))  # 带数字编号
 4 hello world
 5 >>> print('{0} {1} {0}'.format('hello','world'))  # 打乱顺序
 6 hello world hello
 7 >>> print('{1} {1} {0}'.format('hello','world'))
 8 world world hello
 9 >>> print('{a} {tom} {a}'.format(tom='hello',a='world'))  # 带关键字
10 world hello world
```

列表和字典

```python
>>> coord = (3, 5)
>>> 'X: {0[0]};  Y: {0[1]}'.format(coord)
'X: 3;  Y: 5'
>>> a = {'a': 'test_a', 'b': 'test_b'}
>>> 'X: {0[a]};  Y: {0[b]}'.format(a)
'X: test_a;  Y: test_b'
```



> （1）< （默认）左对齐、> 右对齐、^ 中间对齐、= （只用于数字）在小数点后进行补齐
> （2）取位数“{:4s}”、"{:.2f}"等

```python
>>> print('{} and {}'.format('hello','world'))  # 默认左对齐
hello and world
>>> print('{:10s} and {:>10s}'.format('hello','world'))  # 取10位左对齐，取10位右对齐
hello      and      world
>>> print('{:^10s} and {:^10s}'.format('hello','world'))  # 取10位中间对齐
  hello    and   world   
>>> print('{} is {:.2f}'.format(1.123,1.123))  # 取2位小数
1.123 is 1.12
>>> print('{0} is {0:>10.2f}'.format(1.123))  # 取2位小数，右对齐，取10位
1.123 is       1.12

>>> '{:<30}'.format('left aligned')  # 左对齐
'left aligned                  '
>>> '{:>30}'.format('right aligned')  # 右对齐
'                 right aligned'
>>> '{:^30}'.format('centered')  # 中间对齐
'           centered           '
>>> '{:*^30}'.format('centered')  # 使用“*”填充
'***********centered***********'
>>>'{:0=30}'.format(11)  # 还有“=”只能应用于数字，这种方法可用“>”代替
'000000000000000000000000000011'
```



## 格式转换

'b' - 二进制。将数字以2为基数进行输出。

'c' - 字符。在打印之前将整数转换成对应的Unicode字符串。

'd' - 十进制整数。将数字以10为基数进行输出。

'o' - 八进制。将数字以8为基数进行输出。

'x' - 十六进制。将数字以16为基数进行输出，9以上的位数用小写字母。

'e' - 幂符号。用科学计数法打印数字。用'e'表示幂。

'g' - 一般格式。将数值以fixed-point格式输出。当数值特别大的时候，用幂形式打印。

'n' - 数字。当值为整数时和'd'相同，值为浮点数时和'g'相同。不同的是它会根据区域设置插入数字分隔符。

'%' - 百分数。将数值乘以100然后以fixed-point('f')格式打印，值后面会有一个百分号。

```python
1 >>> print('{0:b}'.format(3))
 2 11
 3 >>> print('{:c}'.format(20))
 4 
 5 >>> print('{:d}'.format(20))
 6 20
 7 >>> print('{:o}'.format(20))
 8 24
 9 >>> print('{:x}'.format(20))
10 14
11 >>> print('{:e}'.format(20))
12 2.000000e+01
13 >>> print('{:g}'.format(20.1))
14 20.1
15 >>> print('{:f}'.format(20))
16 20.000000
17 >>> print('{:n}'.format(20))
18 20
19 >>> print('{:%}'.format(20))
20 2000.000000%
```

### 2. str.join(序列) 

把序列中的元素以str字符连接起来

3. ### 命名空间

4. Eval()

#  5.yield用法

> https://blog.csdn.net/mieleizhi0522/article/details/82142856

```python
def foo():
    print("starting...")
    while True:
        res = yield 4
        print("res:",res)
g = foo()
print(next(g))
print("*"*20)
print(next(g))
```

代码输出

```python
starting...
4
********************
res: None
4
```

**解释代码运行顺序，相当于代码单步调试：**

1.程序开始执行以后，因为foo函数中有yield关键字，所以foo函数并不会真的执行，而是先得到一个生成器g(相当于一个对象)

2.直到调用next方法，foo函数正式开始执行，先执行foo函数中的print方法，然后进入while循环

3.程序遇到yield关键字，然后把yield想想成return,return了一个4之后，程序停止，并没有执行赋值给res操作，此时next(g)语句执行完成，所以输出的前两行（第一个是while上面的print的结果,第二个是return出的结果）是执行print(next(g))的结果，

4.程序执行print("*"*20)，输出20个*

5.又开始执行下面的print(next(g)),这个时候和上面那个差不多，不过不同的是，这个时候是从刚才那个next程序停止的地方开始执行的，也就是要执行res的赋值操作，这时候要注意，这个时候赋值操作的右边是没有值的（因为刚才那个是return出去了，并没有给赋值操作的左边传参数），所以这个时候res赋值是None,所以接着下面的输出就是res:None,

6.程序会继续在while里执行，又一次碰到yield,这个时候同样return 出4，然后程序停止，print函数输出的4就是这次return出的4.

# 6. python内置函数 next()用法

> https://blog.csdn.net/happyuu/article/details/80279720

