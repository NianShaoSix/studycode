#include <iostream>
#include <cstring>
using namespace std;
int arr[128];
char s[1110];
int flag = 0;
int main(){
    cin >> s;
    int len = strlen(s);
    for(int i = 0;i < len;i++){
        arr[(int)s[i]]++;
    }
    for(int i = 0;i<len;i++){
        if(arr[(int)s[i]] == 1) {
            cout << s[i] <<endl;
            flag = 1;
            break;
        }
    }
    if(!flag) cout << "no" << endl;
    return 0;
}
// #include <iostream>
// #include <cstring>
// using namespace std;
// char arr[1110];
// int flag = 0;//标记是否出现过只出现一次的字符
// int main(){
//     cin >> arr;
//     int len = strlen(arr);
//     //暴力
//     int cnt = 0;int i = 0;
//     for(;i < len;i++){
//         cnt = 0;
//         for(int j = 0;j < len;j++){
//             if(arr[i]==arr[j]) cnt++;
//         }
//         if(cnt==1){cout << arr[i] <<endl;flag=1;break;}
//     }
//     if(!flag) cout <<"no" <<endl;
//     return 0;
// }

