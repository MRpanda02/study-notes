
class Node:
    def __init__(self, item):
        self.item = item
        self.next = None


# 头插法
def Create_linklist_head(li):
    head = Node(li[0])
    for element in li[1:]:
        node = Node(element)
        node.next = head
        head = node
    return head

# 尾插法
def Create_linklist_tail(li):
    head = Node(li[0])
    tail = head
    for element in li[1:]:
        node = Node(element)
        tail.next = node
        tail = node
    return head
def print_linklist(li):
    while li:
        print(li.item,end=',')
        li = li.next
if __name__ == '__main__':
    list = [1,2,3,4,5]
    lk = Create_linklist_tail(list)
    print_linklist(lk)
