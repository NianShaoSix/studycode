# n = input()
# list1 = [int(i) for i in input().strip().split()]
# print(max(list1),min(list1),sep=' ')

# a,b = input().strip().split()
# a = int(a)
# b = int(b)
s = {1,2,3,4,5}
k = {4,4,4,4,4}

for i in s.intersection(k):
    print(i,end = ' ')