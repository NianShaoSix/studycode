n = int(input())
list1 = list(input().split(' '))
list2 = [int(i) for i in list1]
ma = max(list2)
mi = min(list2)
print(ma,mi)