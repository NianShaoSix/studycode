//srand(time(0))种下一个随机数种子
//rand()获得一个随机数
//rand()%(right - left + 1) + left 
//在[left,right]这个区间内，随机选择一个树
#include <iostream>
#include <ctime>

using namespace std;
const int N = 1e5+10;
int n;
int arr[N];

//优化一：随机选择基准元素(用来解决数组本就有序)
int get_random(int left,int right){
    return arr[rand()%(right - left) + left];
}
//优化二:
void quick_sort(int left,int right){
    if(left >= right) return ;
    //1.选择一个基准元素
    int p = get_random(left,right);

    //2.数组分三块 -->荷兰国旗问题
    int l = left - 1,i = left, r = right + 1;
    while(i < r){
        if(arr[i] < p) swap(arr[++l],arr[i++]);
        else if(arr[i] == p) i++;
        else swap(arr[i],arr[--r]);
    }
    quick_sort(left,l);
    quick_sort(r,right);
}
int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i]; 
    }
    srand(time(0));
    quick_sort(1,n);
    for(int i = 1;i <= n;i++){
        cout << arr[i] <<" ";
    }
    return 0;
} 