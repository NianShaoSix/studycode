
def gcd(x,y):
    while y!=0:
        x,y = y,x%y
    return x
a = input()
a,b = a.split('.')

a = int(a)
lenb = len(b)
b = int(b)
c = 1
for i in range(lenb):
    c=c*10
g = gcd(c,b)
print(a,b//g,c//g)
