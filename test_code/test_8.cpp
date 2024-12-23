#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// 冒泡排序
void bubbleSort(std::vector<int>& arr, int& swapCount) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                ++swapCount;
            }
        }
    }
}

// 直接插入排序
void insertionSort(std::vector<int>& arr, int& swapCount) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            ++swapCount;
        }
        arr[j + 1] = key;
    }
}

// 简单选择排序
void selectionSort(std::vector<int>& arr, int& swapCount) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
            ++swapCount;
        }
    }
}

// 快速排序的划分函数
int partition(std::vector<int>& arr, int low, int high, int& swapCount) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            ++swapCount;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    ++swapCount;
    return i + 1;
}

// 快速排序
void quickSort(std::vector<int>& arr, int low, int high, int& swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);
        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

// 希尔排序
void shellSort(std::vector<int>& arr, int& swapCount) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                ++swapCount;
            }
            arr[j] = temp;
        }
    }
}

// 堆排序的辅助函数：调整堆
void heapify(std::vector<int>& arr, int n, int i, int& swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        ++swapCount;
        heapify(arr, n, largest, swapCount);
    }
}

// 堆排序
void heapSort(std::vector<int>& arr, int& swapCount) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i, swapCount);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        ++swapCount;
        heapify(arr, i, 0, swapCount);
    }
}

// 生成随机数组
std::vector<int> generateRandomArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000; // 生成0到999之间的随机数
    }
    return arr;
}

// 比较关键字比较次数和关键字移动次数（这里简单计数交换次数作为移动次数）
void compareSortAlgorithms() {
    const int size = 100;
    const int numTests = 6;
    std::vector<int> arr(size);
    int bubbleSwapCount, insertionSwapCount, selectionSwapCount, quickSwapCount, shellSwapCount, heapSwapCount;

    for (int test = 0; test < numTests; ++test) {
        arr = generateRandomArray(size);
        bubbleSwapCount = insertionSwapCount = selectionSwapCount = quickSwapCount = shellSwapCount = heapSwapCount = 0;

        // 冒泡排序
        std::vector<int> bubbleArr = arr;
        bubbleSort(bubbleArr, bubbleSwapCount);

        // 直接插入排序
        std::vector<int> insertionArr = arr;
        insertionSort(insertionArr, insertionSwapCount);

        // 简单选择排序
        std::vector<int> selectionArr = arr;
        selectionSort(selectionArr, selectionSwapCount);

        // 快速排序
        std::vector<int> quickArr = arr;
        quickSort(quickArr, 0, size - 1, quickSwapCount);

        // 希尔排序
        std::vector<int> shellArr = arr;
        shellSort(shellArr, shellSwapCount);

        // 堆排序
        std::vector<int> heapArr = arr;
        heapSort(heapArr, heapSwapCount);

        std::cout << "Test " << (test + 1) << ":\n";
        std::cout << "冒泡排序: 交换次数 = " << bubbleSwapCount << "\n";
        std::cout << "直接插入排序: 交换次数 = " << insertionSwapCount << "\n";
        std::cout << "简单选择排序: 交换次数 = " << selectionSwapCount << "\n";
        std::cout << "快速排序: 交换次数 = " << quickSwapCount << "\n";
        std::cout << "希尔排序: 交换次数 = " << shellSwapCount << "\n";
        std::cout << "堆排序: 交换次数 = " << heapSwapCount << "\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    compareSortAlgorithms();
    return 0;
}