a,b = input().strip().split()
a = int(a)
b = int(b)
arr = []
for i in range(16):
    arr.append((a>>i) & 1)

d = 0
cnt = 1
for i in range(b,b+16):
    j = i%16
    d = d + arr[j]*cnt
    cnt = cnt * 2
print(d)