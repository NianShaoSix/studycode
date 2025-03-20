#include <iostream>
using namespace std;
const int N = 1e5+10;
int n;
int arr[N];
int tmp[N];//辅助归并排序时，合并两个数组
void merge_sort(int left,int right){
    if(left >= right) return; 
    int mid = (left + right) >> 1;
    //1.先让左右区间有序
    //2.让左右区间有序
    merge_sort(left,mid);
    merge_sort(mid + 1,right);
    //3.合并两个有序数组
    int cur1 = left,cur = left,cur2 = mid + 1;
    while(cur1 <= mid&&cur2 <= right){
        if(arr[cur1]<arr[cur2]){
            tmp[cur++] = arr[cur1++];
        }
        else tmp[cur++] = arr[cur2++];
    }
    while(cur1<=mid){
        tmp[cur++] = arr[cur1++]; 
    }
    while(cur2 <= right){
        tmp[cur++] = arr[cur2++];
    }
    for(int j = left; j <= right; j++){
        arr[j] = tmp[j];
    }
}


int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i]; 
    }

    merge_sort(1,n);

    for(int i = 1;i <= n;i++){
        cout << arr[i] <<" ";
    }
    return 0;
}