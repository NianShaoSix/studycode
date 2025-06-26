#include <iostream>
#include <string>
using namespace std;
// int main(){
//     string s = "abcdef";
//     string::iterator it1 = s.begin();
//     string::iterator it2 = s.end();
//     cout << it2 - it1 << endl;
//     return 0;
// }
// int main(){
//     string s;int len;
//     getline(cin,s);
//     cout << s.size() <<endl;
//     cout << s <<endl;
//     getline(cin,s,'q');
//     cout << s << endl;
//     cout << s.size() << endl;
//     return 0;
// }
int main(){
    string s = "hello world";
    size_t n = s.find("bit");
    if(n == string::npos){
        cout << "meizhaodao" << endl;
        cout << n<<endl;
        cout << string::npos<<endl;
    }
    else cout << "zhaodaole,weizhiwei: "<< n <<endl;
    return 0;
}