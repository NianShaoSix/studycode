#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
const LL INF = 1e10+10;

int n;
set<LL> mp;
int main(){
    cin >> n;
    mp.insert(-INF);
    mp.insert(INF);
    while(n--){
        int c;
        cin >> c;
        if(c == 1){
            LL x;
            cin >> x;
            if(mp.count(x)) cout<<"Already Exist"<<endl;
            else mp.insert(x);
        }
        else{
            int x;
            cin >> x;
            if(mp.size()!=2){
                auto t = mp.lower_bound(x);
                auto temp = t;
                temp--;
                if(abs(x-*temp)<=abs(x-*t)&&abs(x-*temp)<1e10){
                    cout <<*temp<<endl;
                    mp.erase(*temp);
                }
                else 
                {
                    cout << *t << endl;
                    mp.erase(*t);
                }
                
            }
            else cout <<"Empty"<<endl;
        }
    }

    return 0;
}