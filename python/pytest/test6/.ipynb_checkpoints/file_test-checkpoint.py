import os
#找到对应工作路径
os.chdir(r"d:/studycode/python/pytest/test6")
#打开文件
file = open("nature.txt",'r')
#读取文本内容
text = file.read()

#统计文本中出现频率最高的10个单词
#文本预处理
def getText(text):
    "将文本中所有大写字母转换成小写字母"
    text = text.lower()
    "将标点符号转换成空格"
    for ch in ",.;?-:\'":
        text = text.replace(ch," ")
    return text

#统计词频函数，topen表示取频率最高的单词个数
def wordFreq(text,topn):
    '将文本分词'
    words = text.split()
    counts = {}
    for word in words:
        counts[word] = counts.get(word,0) + 1
    # '定义集合存放时需要去除的无意义的单词'
    # excludes = {'the','and','to','of','a','is','it','this','that','with','from','its','us','in'}
    # for word in excludes:
    #     if word in counts:
    #         del(counts[word])

    '在字典转换为列表，以方便排序'
    items = list(counts.items())
    items.sort(key = lambda x:x[1], reverse = True)
    return items[:topn]

#统计结果
text = getText(text)
file2 = open("out.txt",'w')
for word,freq in wordFreq(text,10):
    file2.write("{:<10}{:>}\n".format(word,freq))

file.close()
file2.close()