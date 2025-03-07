// #include <iostream>
// #include <string>
// #include <cctype>
// using namespace std;
// int main(){
//     int cnt = 0;
//     string s;
//     getline(cin,s);
//     for(int i = 0;i<s.size();i++){
//         if(!isspace(s[i])){
//             cnt ++;
//         }
//     }
//     cout << cnt <<endl;
//     return 0;
// }
#include <iostream>
#include <string>
using namespace std;
int main(){
    int cnt = 0;
    string s;
    while(cin >> s){
        cnt += s.size();
    } 
    cout << cnt << endl;
    return 0;
}