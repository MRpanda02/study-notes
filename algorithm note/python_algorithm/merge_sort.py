# 归并排序算法   时间复杂度：nlogn
# 快速排序：极端情况下排序效率低(n^2)
# 归并排序：需要额外的内存开销
# 堆排序：在快的排序算法中相对较慢
import random

def merge(li, low, mid, high):
    i = low
    j = mid + 1
    ltmp = []
    while i <= mid and j <= high:
        if li[i] < li[j]:
            ltmp.append(li[i])
            i += 1
        else:
            ltmp.append(li[j])
            j += 1
    while i <= mid:
        ltmp.append(li[i])
        i += 1
    while j <= high:
        ltmp.append(li[j])
        j += 1
    li[low:high+1] = ltmp

def merge_sort(li, low, high):
    if low < high:
        mid = (low + high) // 2
        merge_sort(li, low, mid)
        merge_sort(li, mid + 1, high)
        merge(li, low, mid, high)

if __name__ == '__main__':
    list = [random.randint(0,10000) for i in range(1000)]
    merge_sort(list, 0, len(list) - 1)
    print(list)