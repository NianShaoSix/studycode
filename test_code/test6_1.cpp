#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// 在链表的第i个位置插入新节点
void insertNode(Node** head, int i, int x) {
    Node* newNode = createNode(x);
    if (i == 1) {
        // 插入到头部
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        int pos = 1;
        // 寻找第i-1个节点
        while (temp != NULL && pos < i - 1) {
            temp = temp->next;
            pos++;
        }
        if (temp == NULL && pos < i - 1) {
            printf("插入位置错误\n");
            free(newNode);
        } else {
            // 插入节点
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// 打印链表
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// 主函数
int main() {
    Node* head = NULL;
    // 插入元素
    printf("在第1个位置插入9\n");
    insertNode(&head, 1,9 );
    printList(head);
    printf("在第2个位置插入99\n");
    insertNode(&head, 2, 99);
    printList(head);
    printf("在第3个位置插入999\n");
    insertNode(&head, 3, 999);
    printList(head);
    printf("在第1个位置插入9999\n");
    insertNode(&head, 1, 9999); // 这将把5插入到头部，链表变为9999 -> 9 -> 99 -> 999
    printList(head);

    // 释放链表内存
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}