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

 
