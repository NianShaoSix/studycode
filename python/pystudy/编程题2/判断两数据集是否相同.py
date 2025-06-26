m = int(input())
list1 = input()
n = int(input())
list2 = input()
list1 = set((list1.split()))
list2 = set(list2.split())
m = len(list1)
n = len(list2)
list1 = sorted((int(i) for i in list1))
list2 = sorted((int(i) for i in list2))

if m!=n:
    print(0)
else:
    for i,j in zip(list1,list2):
        if i == j:
            continue
        else:
            print(0)
            break
    else: print(1)
for i in list1:
    print(i,end=' ')
