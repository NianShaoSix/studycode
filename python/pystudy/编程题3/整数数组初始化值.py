import re

s = input().strip()

# 增强的正则表达式，处理多行和复杂空格情况
pattern = r'^\s*int\s+\w+\s*\[\s*(\d+)\s*\]\s*(?:=\s*{\s*((?:[^{}]*|\n)*?)\s*}\s*)?;\s*$'
match = re.fullmatch(pattern, s, flags=re.DOTALL)

if not match:
    print("N")
    exit()

n = int(match.group(1))
init_part = match.group(2)

result = []
if init_part is not None:
    # 提取所有有效数字（处理多行/空格/空元素）
    elements = []
    parts = re.split(r'[,\n]+', init_part)
    for p in parts:
        stripped = p.strip()
        if stripped:
            try:
                elements.append(int(stripped))
            except:
                pass  # 题目保证输入合法，此异常仅用于容错
    
    # 补足到数组长度
    elements += [0] * (n - len(elements))
    result = elements[:n]  # 严格限制长度
else:
    result = ['N'] * n

print(' '.join(map(str, result)) + ' ')