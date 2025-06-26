#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    char s1[100] = "abcdefg";
    string s2 = "abcdef";
    cout << sizeof(s1)/sizeof(char)<<endl;
    int len = strlen(s1);
    cout << strlen(s1) << endl;
    cout << s2.size() << endl;
    cout << s2.length()<<endl;
    return 0;
}