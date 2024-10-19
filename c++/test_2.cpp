#include<iostream>
using namespace std;

int main(){
    char arr[100];
    cin >> arr;
    int count = 0; // 用于统计单词数量
    bool isWord = false; // 用于标记是否处于单词内部

    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] != ' ' && !isWord){ // 如果当前字符不是空格且之前不是单词内部
            count++; // 单词数量加1
            isWord = true; // 现在处于单词内部
        }else if(arr[i] == ' '){
            isWord = false; // 如果当前字符是空格，标记为非单词内部
        }
    }
    cout << count << endl; // 输出单词数量
    return 0;
}