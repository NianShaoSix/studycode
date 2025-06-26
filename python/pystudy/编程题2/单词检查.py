import re

def main():
    # 读取 index.txt 获取合法单词集合
    with open('index.txt', 'r', encoding='utf-8') as f:
        valid_words = set(line.strip() for line in f)

    # 读取 in.txt 提取单词并转换为小写
    with open('in.txt', 'r', encoding='utf-8') as f:
        content = f.read().lower()

    # 正则提取单词（纯字母组成）
    words = re.findall(r'\b[a-z]+\b', content)

    # 找出错误单词（不在 valid_words 中）
    errors = [word for word in words if word not in valid_words]

    # 排序后写入 error.txt，每个词一行，保留重复
    errors.sort()
    with open('error.txt', 'w', encoding='utf-8') as f:
        for word in errors:
            f.write(word + '\n')

if __name__ == '__main__':
    main()
