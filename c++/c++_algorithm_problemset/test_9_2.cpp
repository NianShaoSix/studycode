#include<iostream>
#include<string>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;//单链表类型定义

//初始化单链表
int InitList(LinkList &L){
    L=new LNode; //分配一个头结点
    L->next=NULL;//建立一个带头结点的单链表
}

//创建单链表
int CreateList_L(LinkList &L, int n){
    //逆位序输入n个元素的值，建立带头结点的单链线性表L
    L=new LNode;
    L->next=NULL;//先建立一个带头结点的单链表
    
    for(int i=n;i>0;i--){
        LNode *p=new LNode;//生成新结点
        cin>>p->data;//输入元素值
        p->next=L->next;//插入到表头
        L->next=p;//插入到表头
    }
}

//单链表的插入
int ListInsert_L(LinkList &L,int i, int e){
    //在带头结点的单链线性表L中第i个位置之前插入元素e
    LNode *p=L;
    int j=0;
    while(p&&j<i-1){
        p=p->next;
        ++j;
    }
    if(!p||j>i-1){ return -1;}//插入位置小于1或大于表长
    LNode *s=new LNode;//生成新结点
    s->data=e;
    s->next=p->next;
    p->next=s;
    return 0;
}

//单链表的删除
int ListDelete_L(LinkList &L,int i,int e){
    //在带头结点的单链线性表L中删除第i个位置元素e
    LNode *p=L;
    int j=0;
    while(p&&j<i-2){
        p=p->next; j++;
    }
    if(!p||j>i-1){//删除位置不合理
        return -1;
    }
    LNode *s=p->next;
    s->data=e;
    p->next=p->next->next;
    delete(s);
    return 0;
}

int main(){
    LinkList L;//声明一个单链表
    InitList(L);//初始化单链表
    CreateList_L(L,5);//创建单链表
    cout<<"创建的单链表为："<<endl;
    for(LNode *p=L->next;p!=NULL;p=p->next){
        cout<<p->data<<" ";
    }
    cout<<endl;
    ListInsert_L(L,3,4);//在第三个位置插入元素4
    cout<<"插入后的单链表为："<<endl;
    for(LNode *p=L->next;p!=NULL;p=p->next){
        cout<<p->data<<" ";
    }
    cout<<endl;
    ListDelete_L(L,3,4);//删除第三个位置的元素
    cout<<"删除后的单链表为："<<endl;
    for(LNode *p=L->next;p!=NULL;p=p->next){
        cout<<p->data<<" ";
    }

    return 0;
}