# 1. 列表

32位机器上，一个整数占4个字节，一个地址占四个字节

64位机器上，一个地址占八个字节（相当于地址变多了）

>  python的列表和C语言的数组由两点不同：
>
> ​		1.数组元素类型要相同
>
> ​		2.数组长度固定
>
> ​				两个不同点的原因相同：
>
> ​				在C语言直接在数组里表示了数据类型，而在Python中列表中存储的事数据类型的地址，所以不限元素类型和长度



# 2. 栈

概念：栈(stack)是一个数据集合，可以理解为只能在一端进行插入或删除操作的列表。

特点：后进先出LIFO(last-in,first-out)



# 3. 队列

概念：队列(Queue)是一个数据集合，仅允许在列表的一端进行插入，另一段进行删除。

特点：先进先出FIFO(first-in,first-out)

### 队列的实现方式：环形队列

环形队列：

- 当对尾指针front == Maxsize + 1时，在前进一个位置就自动到0
- 队首指针前进1:front = (front + 1) % Maxsize
- 队尾指针前进1:rear = (rear + 1) % MaxSize
- 队空条件:rear == front
- 队满条件:(rear + 1) % MaxSize == front



双向队列：

两端都可以进队或出队的队列(dequeue)



# 4. 链表

概念：链表是由一系列节点组成的元素集合。每个节点包含两部分，数据域item和指向下一个节点的指针next。通过节点之间的相互连接，最终串联成一个链表。

![Node](data structure.assets/OneSideNode.png)

创建列表：

- 头插法
- 尾插法

### 链表节点的插入

```python
p.next = curNode.next
curnode.next = p
```

![](data structure.assets/InsertInLinklist.png)

### 链表节点的删除

```python
p = curNode.next
curNode.next = curNode.next.next
del p
```

![](data structure.assets/DeleteLinklist.png)

## 双链表

> 双链表的每个节点有两个指针：一个指向后一个节点，另一个指向前一个节点。

```python
class Node(object):
    def __init__(self,item):
        self.item = item
        self.next = None
        self.prior = None
```

![](data structure.assets/双链表.png)

### 双链表节点的插入

```python
p.next = curNode.next
curnode.next.prior = p
p.prior = curNode
curNode.next = p
```

![](data structure.assets/双链表插入.png)

### 双链表节点的删除

```python
curNode.next = curNode.next.next
curNode.next.prior = curNode
del p
```

![](data structure.assets/双链表的删除.png)

#### 总结：

- 链表在插入和删除的操作上明显快于顺序表
- 链表的内存可以更灵活的分配
- 试利用链表重新实现栈和队列
- 链表这种链式存储的数据结构对树和图的结构有很大的启发性