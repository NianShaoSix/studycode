pattern = input().strip().lower()
text = input().strip()
text_lower = text.lower()
ret = []
lenp = len(pattern)
lent = len(text)
i = 0
while i < lent:
    if text_lower[i:i+lenp] == pattern:
       i = i + lenp
    else :
        ret.append(text[i])
        i+=1
for j in ret:
    print(j,end='')