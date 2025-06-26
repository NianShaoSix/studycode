import re
import sys

def extract_words(text):
    # 使用正则表达式提取由连续字母组成的单词
    words = re.findall(r'\b[a-zA-Z]+\b', text)
    # 转换为小写
    words = [word.lower() for word in words]
    return words

def main():
    # 读取所有输入行，直到用户输入结束（Ctrl+Z）
    text = sys.stdin.read()
    # 提取单词
    words = extract_words(text)
    # 去重并排序
    unique_words = sorted(set(words))
    # 输出每个单词，每个单词单独占一行
    for word in unique_words:
        print(word)

if __name__ == "__main__":
    main()