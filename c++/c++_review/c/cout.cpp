// #include <iostream>
// #include <iomanip>
// using namespace std;
// int main() {
//     //int a = 123;
//     //cout << setw(10) << setfill('*') << a << endl;
//     //return 0;
//     //double pi = 3.14182653589793;
//     //cout << pi << endl;
//     //cout << fixed << pi << endl;
//     //cout << scientific << pi << endl;
//     //cout << fixed << setprecision(8) << pi << endl;
//     //int n = 255;
//     //cout << n << endl;
//     //cout << dec << n << endl;//十进制
//     //cout << hex << n << endl;//十六进制
//     //cout << oct << n <<endl;//八进制
//     int a = 123;
//     cout << a << endl;
//     cout << setw(10) << a << endl;
//     cout << setw(10) << left << a << endl;
//     return 0;
// }
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello";
    str += " ";  // 追加一个空格
    str += "World";  // 追加另一个字符串
    str += '!';  // 追加一个字符

    std::cout << str << std::endl;  // 输出: "Hello World!"
    return 0;
}