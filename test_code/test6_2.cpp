#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // 定义循环队列的最大容量

// 循环队列的结构体定义
typedef struct {
    int array[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// 初始化循环队列
void initQueue(CircularQueue* Q) {
    Q->front = Q->rear = 0;
}

// 检查队列是否已满
bool isFull(CircularQueue* Q) {
    return (Q->rear + 1) % MAX_SIZE == Q->front;
}

// 检查队列是否为空
bool isEmpty(CircularQueue* Q) {
    return Q->front == Q->rear;
}

// 入队操作
bool enqueue(CircularQueue* Q, int value) {
    if (isFull(Q)) {
        return false; // 队列已满，无法入队
    }
    Q->array[Q->rear] = value;
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    return true;
}

// 出队操作
bool dequeue(CircularQueue* Q, int* value) {
    if (isEmpty(Q)) {
        return false; // 队列为空，无法出队
    }
    *value = Q->array[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE;
    return true;
}

// 打印队列中的元素
void printQueue(CircularQueue* Q) {
    int i = Q->front;
    while (i != Q->rear) {
        printf("%d ", Q->array[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue Q;
    initQueue(&Q);
    printf("将1入队\n");
    enqueue(&Q, 1);
    printQueue(&Q); // 打印队列
    printf("将2入队\n");
    enqueue(&Q, 2);
    printQueue(&Q); // 打印队列
    printf("将3入队\n");
    enqueue(&Q, 3);
    printQueue(&Q); // 打印队列

    int value;
    if (dequeue(&Q, &value)) {
        printf("出队: %d\n", value);
    }
    printQueue(&Q); // 再次打印队列

    return 0;
}