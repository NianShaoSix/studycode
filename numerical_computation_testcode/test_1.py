import matplotlib.pyplot as plt

#定义原函数
def f(x):
    return 1/(1 + 25*x**2) 

#生成等距节点
def generate_nodes(n):
    return [-1 + 2*i/n for i in range(n + 1)]

#拉格朗日插值
def lagrange_interp(x, nodes, y_nodes):
    result = 0.0
    for i in range(len(nodes)):
        term = y_nodes[i]
        for j in range(len(nodes)):
            if j!=i:
                term*=(x-nodes[j])/(nodes[i]-nodes[j])
        result+=term
    return result
