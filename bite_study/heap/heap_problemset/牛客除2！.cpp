#include <iostream>
#include <queue>
using namespace std;
long long n,k;
const int N = 1e9;
priority_queue<long long>heap;
int main(){
    cin >> n >> k;
    long long res = 0;
    while(n--){
        long long x;
        cin >> x;
        if(x%2!=0)
        res+=x;
        else
        heap.push(x);
    }
    while(k--&&heap.size()){
            long long t = heap.top()/2;
            heap.pop();
            if(t%2!=0) res+=t;
            else
            heap.push(t/2);
    }
    while(heap.size()){
        res+=heap.top();
        heap.pop();
    }
    cout << res <<endl;
    return 0;
}