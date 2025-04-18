import csv

# 创建通讯录
dicTXL = {'小新': [13913000001, 18191220001],
          '小亮': [13913000002, 181191220002],
          '小刚': [13913000003, 18191220003]}
# 隔壁宿舍舍长通讯录
dicOther = {'大刘': [1391400001, 18191230001],
            '大王': [13914000002, 18191230002],
            '大张': [13914000003, 18191230003]}

# 合并通讯录
dicTXL.update(dicOther)
# 微信通讯录
dicWX = {'小新': 'xx9907',
         '小刚': 'gang1004',
         '大王': 'jack_w',
         '大刘': 'liu666'}
for k, v in dicTXL.items():
    if k in dicWX:
        dicTXL[k].append(dicWX[k])
    else:
        dicTXL[k].append(str(dicTXL[k][0]))
print('更改前的通讯录为：')
print(dicTXL)
print('更改后的通讯录为：')
# 将大王的手机号更改为13914000004
dicTXL['大王'][0] = 13914000004
print(dicTXL)

# 创建“通讯录.csv”文件
with open('通讯录.csv', 'w', newline='', encoding='utf-8') as csvfile:
    writer = csv.writer(csvfile)
    # 写入表头
    writer.writerow(['姓名', '手机号', 'QQ号', '微信号'])
    # 写入通讯录数据
    for name, info in dicTXL.items():
        writer.writerow([name, info[0], info[1], info[2]])

# 查询大王的手机号、QQ号和微信号
name = '大王'
if name in dicTXL:
    print(f"{name}同学的手机号为：{dicTXL[name][0]}")
    print(f"{name}同学的QQ号为：{dicTXL[name][1]}")
    print(f"{name}同学的微信号为：{dicTXL[name][2]}")
else:
    print('没有该同学的联系方式')