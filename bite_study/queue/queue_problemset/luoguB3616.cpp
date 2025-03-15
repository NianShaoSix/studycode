#include <iostream>
#include <queue>
using namespace std;


int main(){
    queue<int> q;
    int n = 0;
    cin >> n;
    while(n--){
        int c = 0;
        cin >> c;
        if(c == 1){
            int x = 0;
            cin >> x;
            q.push(x);
        }
        else if(c == 2){
            if(q.size()){
                q.pop();
            }
            else cout <<"ERR_CANNOT_POP"<<endl;
        }
        else if(c == 3){
            if(q.size()){
                cout <<q.front()<<endl;
            }
            else{
                cout <<"ERR_CANNOT_QUERY"<<endl;
            }
        }
        else cout <<q.size()<<endl;
    }

    return 0;
}