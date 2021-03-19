Mac系统由于系统自带python2，而现在大多数地方需要使用python3，所以在安装django的时候，使用pip3安装第三方包比较方便

但实际安装的位置和在运行python3时import所访问的位置不同导致发生

`ModuleNotFoundError: No module named ‘django'`的情况

所以只能手动把所需的一些文件手动移动到python3的import所访问的位置，其文件不一定只有一个，可随时查看出错信息把相应的文件移动。

asgiref                       
asgiref-3.3.1.dist-info

django

Django-3.1.7.dist-info

pytz
pytz-2021.1.dist-info

sqlparse
sqlparse-0.4.1.dist-info