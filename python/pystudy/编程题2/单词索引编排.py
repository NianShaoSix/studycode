import re

def main():
    # 读取原始文本并转为小写
    with open('in.txt', 'r', encoding='utf-8') as f:
        content = f.read().lower()

    # 用正则提取所有连续的字母单词（只要字母）
    words = re.findall(r'[a-z]+', content)

    # 去重并排序
    unique_words = sorted(set(words))

    # 写入 out.txt，每个单词一行
    with open('out.txt', 'w', encoding='utf-8') as f:
        for word in unique_words:
            f.write(word + '\n')

if __name__ == '__main__':
    main()
