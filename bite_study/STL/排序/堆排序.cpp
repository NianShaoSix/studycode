#include <iostream>
using namespace std;
const int N = 1e5+10;
int n;
int arr[N];
void down(int parent,int len){
    int child = parent * 2;
    while(child <= len){
        if(child + 1<=len && arr[child + 1]>arr[child]) child++;
        
        if(arr[parent]>=arr[child]) return;
        swap(arr[parent],arr[child]);
        parent = child;
        child = parent * 2;
    }
}
void heap_sort(){
    //1.建堆
    for(int i = n/2;i >= 1;i--){
        down(i,n);//向下调整
    }
    //2.排序
    for(int i = n;i > 1;i--){//取出最后一个元素
        swap(arr[1],arr[i]);
        down(1,i-1);
    }
}
int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i]; 
    }
    
    heap_sort();
    for(int i = 1;i <= n;i++){
        cout << arr[i] <<" ";
    }
    return 0;
}