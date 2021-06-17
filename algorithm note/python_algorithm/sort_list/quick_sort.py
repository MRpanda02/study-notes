import random

def partition(li, left, right):

    tmp = li[left]
    while left < right:
        while left < right and li[right] >= li[left]:
            right -= 1
        li[right] = li[left]
        while left < right and li[left] <= li[right]:
            left += 1
        li[left] = li[right]
    li[left] = tmp
    return left

def quick_sort(li, left, right):

    mid = partition(li, left, right)
    quick_sort(li, left, mid - 1)
    quick_sort(li, mid + 1, right)

if __name__ == '__main__':

    list = [random.randint(0,10000) for i in range(1000)]
    print(list)
    quick_sort(list, 0, len(list)-1)
    print(list)
