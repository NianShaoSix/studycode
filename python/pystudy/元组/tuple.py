# 元组学习
# 元组和列表非常相似，但是元组一旦初始化就不能修改。
# 可以通过索引得到元素
# 元组不可变是使代码更安全 建议能用tuple代替list就尽量用tuple 
# 不可变指的是元组内的元素指向不变，如果元素是列表，列表元素也可以改变

#元组的创建
# tuple1 = ('xdd',20,'grade2')
# tuple2 = '123','lisi',12
# # print(tuple1)
# # print(tuple2)
# tuple3 = ()
# tuple4 = (123,)
# print(type(tuple4))
# print(tuple3)
# print(tuple4)
import torch
print(torch.cuda.is_available())  # 如果返回 True，说明 CUDA 可用
