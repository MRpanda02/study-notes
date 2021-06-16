# 基数排序算法
# 根据一串数组的个位数，十位数，百位数...分别依次桶排序实现排序
# 基数排序时间复杂度为 kn k = log(10, n)  k表示最大的位数，所以最大值的位数越大，基数排序的时间复杂度相对变大
# 快速排序时间复杂度为 nlogn logn=log(2, n)
import random
def radix_sort(li):
    max_num = max(li)
    it = 0
    while 10 ** it <= max_num:
        buckets = [[] for _ in range(10)]
        for val in li:
            digit = (val // 10 ** it) % 10
            buckets[digit].append(val)
        list_num =[]
        li.clear()
        for buc in buckets:
            li.extend(buc)
        it += 1

if __name__ == '__main__':
    list = [_ for _ in range(10000)]
    random.shuffle(list)
    print(list)
    radix_sort(list)
    print(list)
    print("radix sort")