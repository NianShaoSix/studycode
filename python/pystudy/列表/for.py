# for num in range(10,20):
#     for i in range(2,num):
#         j = num/i
#         print('%d是一个合数'%num)
#         break
#     else: print('%d是一个质数'%num)

## 打印九九乘法表
# for i in range(1,10):
#     for j in range(1,i+1):
#         print('{}x{}={}'.format(i,j,i*j),end = '\t')
#     print()

##判断是是否为闰年
# year = int(input('请输入一个年份:'))

# if year % 400 == 0 or year % 4 == 0 and year & 100!= 0:
#     print('%d是闰年'%year)
# else:
#     print('%d不是闰年'%year)
# for i in range(2000,2026):
#     if i%4==0 and i%100!=0 or i%400==0:
#         print(i,end = ' ')
# n = int(input())
# m = int(input())
# a = []
# for i in range(n):
#     a[i] = int(input())
# ma = max(a)
# mi = min(a)
# for i in range(n):
#     if a[i] > m:
#         a[i] = ma
#     elif a[i] < m:
#         a[i] = mi
# for i in a:
#     print(i,end= ' ')
# list1 = input()
# arr= list1.split(' ')
# for i in arr:
#     print(i,end = ' ')
list1 = input()
# list2 = input()
# n,m = list1.split(' ')
# n = int(n)
# m = int(m)

# list3 = list2.split(' ')

# list4 = []
# for i in range(n):
#     x = int(list3[i])
#     list4.append(x)
# ma = max(list4)
# mi = min(list4)
# for i in range(int(n)):
#     if list4[i] > m:
#         list4[i] = ma
#     elif list4[i] < m:
#         list4[i] = mi
# for i in list4:
#     print(i,end=' ')
k = float(input())

if k > 212:
    print("Temperature is too high!")
else: 
    c = k -273.15
    f = c * 1.8 + 32
    print(c,f)