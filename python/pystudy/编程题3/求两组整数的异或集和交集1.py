arr1 = [int(i) for i in (input().strip()).split()]
arr2 = [int(j) for j in (input().strip()).split()]

arr3 =list(set(arr1)&set(arr2)) 
arr4 =list(set(arr1)|set(arr2))
arr4 = list(set(arr4) - set(arr3))
arr3.sort(reverse = True)
arr4.sort(reverse = True)

for i in arr4:
    print(i,end = ' ')
print()
if len(arr3) == 0:
    print()
else :
    for j in arr3:
        print(j,end = ' ')
