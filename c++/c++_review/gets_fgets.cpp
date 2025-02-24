#include <iostream>
using namespace std;
int main() {
    //1.gets fgets
    //char arr[20];
    //gets(arr);
    //cout << arr << endl;
    //fgets(arr, 20, stdin);//stdin标准输入流-->键盘
    //fegts也是读取一行，但是可以指定读取的字符数，不会超出范围
    //fgets(arr, 20, stdin)读取一行，最多读取20个字符，包括换行符，最后一个字符是'\0'
    //即只能从外界输入19个字符，最后一个位置留给'\0'
    //如果输入的字符数超过20，fgets会读取20个字符，剩下的字符会留在输入缓冲区
    //fgets会读取换行符，但是不会丢弃换行符，所以fgets读取的字符串最后一个字符是换行符
    //fgets会检查数组越界，不会造成缓冲区溢出

    //gets会读取一行，直到遇到换行符，但是不会读取换行符，gets会把换行符替换为'\0'
    //gets不会检查数组越界，容易造成缓冲区溢出

    //cout << arr <<endl;

    //scanf函数读取带空格的字符串
    //char arr2[20];
    //2.scanf

    //scanf("%[^\n]s", arr2);
    //%[^\n]表示读取除换行符外的所有字符
    //scanf("%[^\n]s", arr2)读取一行，直到遇到换行符，但是不会读取换行符，scanf会把换行符替换为'\0'
    //cout << arr2 <<endl;
    //3.getchar
    char arr3[20];
    int i = 0;
    char ch = 0;
    while((ch = getchar()) != '\n') {
        arr3[i++] = ch;
    }
    arr3[i] = '\0';
    cout << arr3 << endl;
    return 0;
}