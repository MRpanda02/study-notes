import random
'''
堆排序，时间复杂度为nlogn
'''

#向下调整函数实现
def sift(low,high,li):
    '''
    :param low: 堆的根结点位置
    :param high: 堆的最右一个元素的位置
    :param li: 列表
    :return:
    '''
    i = low
    j = 2 * i + 1
    tmp = li[low]
    while j <= high:
        if j + 1 <= high and li[j] < li[j + 1]:
            j = j + 1
        if tmp < li[j]:
            li[i] = li[j]
            i = j
            j = 2 * i + 1
        else:
            li[i] = tmp
            break
    else:
        li[i] = tmp

def heap_sort(li,low,high):
    n = high
    #建堆
    for i in range(n // 2 - 1, -1, -1):
        sift(i, n-1, li)
    #出数
    for i in range(n-1, -1, -1):
        li[0], li[i] = li[i], li[0]
        sift(0, i-1, li)


if __name__ == '__main__':
    list = [random.randint(0,10000) for i in range(1000)]
    print(list)
    heap_sort(list,0,len(list))
    print(list)
