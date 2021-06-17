import random
def insert_sort(li):
    for i in range(0,len(li)):
        tmp = li[i]
        j = i - 1
        while j >= 0 and tmp < li[j]:
            li[j+1] = li[j]
            j -= 1
        li[j+1] = tmp


if __name__ == '__main__':
    list = [random.randint(0,10000) for i in range(1000)]
    print(list)
    insert_sort(list)
    print(list)