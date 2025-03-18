// #include <iostream>
// #include <queue>
// using namespace std;
// int n,op;
// priority_queue<int,vector<int>,greater<int>> heap;

// int main(){
//     cin >> n;
//     while(n--){
//         cin >> op;
//         if(op == 1){
//             int x;
//             cin >> x;
//             heap.push(x);
//         }
//          if(op == 2){
//             cout << heap.top() <<endl;
//         }
//         if(op == 3) heap.pop();
//     }


//     return 0;
// }
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int id,heap[N];
int n,op;


int  top(){
    if(!id) return 0; 
    return heap[1];
}
void up(int child){
    if(child == 1) return ;
    int parent = child / 2;
    while(heap[child] < heap[parent] && parent >= 1){
        swap(heap[parent],heap[child]);
        child = parent;
        parent = child/2;
    }
}

void down(int parent){
    int child = parent / 2;
    while(child <= id){
        if(child + 1 <= id && heap[child + 1] <heap[child]) child++;
        if(heap[child] >= heap[parent]) return;

        swap(heap[child],heap[parent]);
        child = parent;
        parent = 2 * child;
    }
}
// int size(){
//     return id;
// }
void pop(){
    if(!id) return ;
    swap(heap[1],heap[id]);
    id--;
    down(1);
}

void push(int x){
    heap[++id] = x;
    up(n);
}

int main(){
    cin >> n;
    while(n--){
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            push(x);
        }
        if(op==2){
            cout << top() << endl;
        }
        if(op == 3){
            pop();
        }
    }
    return 0;
}