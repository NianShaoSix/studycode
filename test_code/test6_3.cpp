#include <stdio.h>
void findMaxAndIndex(int arr[], int size, int *maxValue, int *maxIndex) {
    *maxValue = arr[0];
    *maxIndex = 0;

    // 遍历数组，从第二个元素开始
    for (int i = 1; i < size; i++) {
        // 如果找到更大的元素，更新最大值及其索引
        if (arr[i] > *maxValue) {
            *maxValue = arr[i];
            *maxIndex = i;
        }
    }
}

int main() {
    int arr[] = {5, 3, 2, 8, 4, 7, 6}; // 示例数组
    int size = sizeof(arr) / sizeof(arr[0]); // 计算数组大小
    printf("示例数组为：[");
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
    printf("]\n");
    int maxValue; // 存储最大值
    int maxIndex; // 存储最大值的索引

    findMaxAndIndex(arr, size, &maxValue, &maxIndex); // 查找最大值及其索引

    printf("最大值是：%d，索引是：%d\n", maxValue, maxIndex); // 输出结果

    return 0;
}