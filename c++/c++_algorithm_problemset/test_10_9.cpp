#include<iostream>
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10 //线性表存储空间的分配增量 
using namespace std;

// 自定义数据类型ElemType
typedef int ElemType;

// 线性表结构定义
typedef struct {
    ElemType *elem; // 存储空间基址
    int length; // 当前长度
    int listsize; // 当前分配的存储容量（以sizeof(ElemType)为单位）
} SqList;

// 函数声明
int InitList_Sq(SqList &L);
int ListInsert_Sq(SqList &L, int i, int e);
int ListDelete_Sq(SqList &L, int i, int &e);

int main() {
    SqList L; // 声明一个线性表
    InitList_Sq(L); // 初始化线性表L
    for (int i = 1; i <= 10; ++i) ListInsert_Sq(L, i, i); // 在表尾依次插入1~10
    cout<<"插入后的线性表为：";
    for (int i = 1; i <= L.length; ++i) cout << L.elem[i - 1] << ' '; // 输出1~10
    cout << endl;
    int e;
    ListDelete_Sq(L, 5, e); // 删除第5个元素
    cout<<"删除的元素为："<<e<<endl; // 输出被删除的元素的值
    cout << "删除后的线性表为：";
    for (int i = 1; i <= L.length; ++i) cout << L.elem[i - 1] << ' '; // 输出删除后的表
    cout << endl;
    return 0;
}

// 初始化线性表
int InitList_Sq(SqList &L) {
    L.elem = new ElemType[LIST_INIT_SIZE];
    if (!L.elem) return -1; // 存储分配失败
    L.length = 0; // 空表长度为0
    L.listsize = LIST_INIT_SIZE; // 初始存储容量
    return 0; // 初始化成功
}

// 插入元素
int ListInsert_Sq(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) return -1; // 插入位置不合法
    if (L.length >= L.listsize) { // 当前存储空间已满，增加分配
        ElemType *newbase = new ElemType[L.listsize + LISTINCREMENT];
        if (!newbase) return -1; // 存储分配失败
        for (int j = 0; j < L.length; ++j) newbase[j] = L.elem[j];
        delete[] L.elem;// 释放原存储空间
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    for (int j = L.length - 1; j >= i - 1; --j) L.elem[j + 1] = L.elem[j];
    L.elem[i - 1] = e;
    ++L.length;
    return 0; // 插入成功
}

// 删除元素
int ListDelete_Sq(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length) return -1; // 删除位置不合法
    e = L.elem[i - 1];
    for (int j = i; j < L.length; ++j) L.elem[j - 1] = L.elem[j];
    --L.length;
    return 0; // 删除成功
}

