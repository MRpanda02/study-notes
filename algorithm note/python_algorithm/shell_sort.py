#希尔算法           根据gap的不同时间复杂度不同
#gap = (N/2^k)时 时间复杂度为 nlogn    比heap_sort(堆排序)稍慢一些

import random
def insert_sort_shell(li, gap):
    for i in range(gap,len(li)):
        j = i - gap
        tmp = li[i]
        while j >= 0 and li[j] > tmp:
            li[j + gap] = li[j]
            j -= gap
        li[j + gap] = tmp

def shell_sort(li):
    d = len(li) // 2
    while d >= 1:
        insert_sort_shell(li, d)
        d = d // 2

if __name__ == '__main__':

    list = [random.randint(0,10000) for i in range(1000)]
    print(list)
    shell_sort(list)
    print(list)
    print("shell_sort")