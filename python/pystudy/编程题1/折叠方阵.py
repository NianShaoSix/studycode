start,n = (int(i) for i in input().split())
list1 = [[0*n for _ in range(n+1)]*n for _ in range(n+1)]
now = start
for i in range(1,n+1):
    list1[1][i] = now
    now+=1
    a = 2
    while(a <=i):
        list1[a][i] = now
        now+=1
        a+=1
    a-= 1
    b = i - 1
    while(b >= 1):
        list1[a][b] = now
        now+=1
        b-=1
for i in range(1,n+1):
    for j in range(1,n+1):
        print("{:>4d}".format(list1[i][j]),end = '')
    print()
    
        