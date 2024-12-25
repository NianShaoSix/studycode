#include<iostream>
#include<cstring>
using namespace std;

#define MAXSTRLEN 10
typedef unsigned char SString[MAXSTRLEN+1]; // 0号单元格存放串的长度

// 串联结
int Concat(SString &T, SString &S1, SString &S2) {
    if (S1[0] + S2[0] <= MAXSTRLEN) { // 未截断
        T[0] = S1[0] + S2[0];
        for (int i = 1; i <= S1[0]; i++) {
            T[i] = S1[i];
        }
        for (int j = 1; j <= S2[0]; j++) {
            T[S1[0] + j] = S2[j];
        }
    } else if (S1[0] < MAXSTRLEN) {
        T[0] = MAXSTRLEN;
        for (int i = 1; i <= S1[0]; i++) {
            T[i] = S1[i];
        }
        for (int j = 1; j <= MAXSTRLEN - S1[0]; j++) {
            T[S1[0] + j] = S2[j];
        }
    } else {
        T[0] = MAXSTRLEN;
        for (int i = 1; i <= MAXSTRLEN; i++) {
            T[i] = S1[i];
        }
    }
    return 0;
}

int main() {
    SString T;
    SString S1, S2;
    int len1, len2;

    cout << "请输入第一个字符串长度： " << endl;
    cin >> len1;

    if (len1 > MAXSTRLEN) {
        cout << "第一个字符串长度输入错误" << endl;
        return -1;
    } else {
        S1[0] = len1;
        cout << "输入第一个字符串内容： " << endl;
        for (int i = 1; i <= S1[0]; i++) {
            cin >> S1[i];
        }
    }

    cout << "请输入第二个字符串长度： " << endl;
    cin >> len2;

    if (len2 > MAXSTRLEN) {
        cout << "第二个字符串长度输入错误" << endl;
        return -1;
    } else {
        S2[0] = len2;
        cout << "输入第二个字符串内容： " << endl;
        for (int i = 1; i <= S2[0]; i++) {
            cin >> S2[i];
        }
    }

    Concat(T, S1, S2);

    cout << "拼接后的字符串为： ";
    for (int i = 1; i <= T[0]; i++) {
        cout << T[i];
    }
    cout << endl;

    return 0;
}