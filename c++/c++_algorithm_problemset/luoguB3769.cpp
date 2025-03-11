#include <iostream>
#include <cstring>
using namespace std;
int l1,r1,l2,r2;
int main(){
    string s,t;
    cin >> s >> t;
    int q;
    cin >> q;
    while(q--){
        
        cin >> l1 >> r1 >> l2 >> r2;
        if(s.substr(l1-1,r1-l1)<t.substr(l2-1,r2-l2)){
            cout <<"yifusuyi"<<endl;
        }
        else if(s.substr(l1-1,r1-l1)>t.substr(l2-1,r2-l2)){
            cout << "erfusuer"<<endl;
        }
        else cout << "ovo"<<endl;
    }
    return 0;
}