#include <iostream>
#include <string>
using namespace std;
int main(){
    int q;
    string s;//初始文档
    string str;
    cin >> q >> s;
    int a,b;
    while(q--){
        int choice = 0;
        cin >> choice;
        switch(choice){
            case 1:
                cin >> str;
                s+= str;
                cout << s <<endl;
                break;
            case 2:
                cin >> a >>b;
                s = s.substr(a,b);
                cout << s <<endl;
                break;
            case 3:
                cin >> a;
                cin >> str;
                cout << s.insert(a,str)<<endl;
                break;
            case 4: 
                cin >> str;
                size_t n = s.find(str);
                if(n == string::npos) cout << -1 <<endl;
                else cout << n <<endl;
                break;
        }
    }
    return 0;
}    
    