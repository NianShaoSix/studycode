//https://ac.nowcoder.com/acm/problem/235558
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int binary_search(int x, int y)
{
    // 大于等于 x 的最小元素
    int left = 1, right = n;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(a[mid] >= x) right = mid;
        else left = mid + 1;
    }
    if(a[left] < x) return 0;
    int tmp = left;
    
    // 小于等于 y 的最大元素
    left = 1, right = n;
    while(left < right)
    {
        int mid = (left + right + 1) / 2;
        if(a[mid] <= y) left = mid;
        else right = mid - 1;
    }
    if(a[left] > y) return 0;
    
    return left - tmp + 1;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int Q; cin >> Q;
    while(Q--)
    {
        int x, y; cin >> x >> y;
        cout << binary_search(x, y) << endl;
    }
    
    return 0;
}