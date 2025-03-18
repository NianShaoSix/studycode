#include <iostream>
#include <queue>
using namespace std;
const int N = 1e9 + 10;
int n,m,k;
priority_queue<int> heap;
int main(){
    cin >> n >> m >>k;
    while(n--){
        int x;
        cin >> x;
        heap.push(x);
        if(heap.size()>k){
            heap.pop();
        }
    }
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int y;
            cin >> y;
            heap.push(y);
            if(heap.size()>k){
                heap.pop();
            }
        }
        else{
            if(heap.size()<k){
                cout <<-1<<endl;
            }
            else cout <<heap.top()<<endl;
        }
    }
    return 0;
}