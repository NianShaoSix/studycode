map = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
parrent = input().strip()
text = input().strip()
lenp = len(parrent)
lent = len(text)
ret = []
for i in range(lent):
    if text[i] in map:
        e = map[(map.find(text[i])+ map.find(parrent[i%lenp]))%26]
        ret.append(e)
    else :
        ret.append(text[i])
    i+=1
for x in ret:
    print(x,end='')
