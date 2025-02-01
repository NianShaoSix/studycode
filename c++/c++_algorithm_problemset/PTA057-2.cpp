#include<iostream>
using namespace std;

// 函数声明
long long cl(int n);

int main() {
    int n;
    cin >> n;
    cout << cl(n) << endl;
    return 0;
}

// 函数定义
long long cl(int n) {
    if (n == 0) return 2; // 第0个月有2对兔子（初始一对大兔子和额外引入的一对）
    if (n == 1) return 3; // 第1个月有3对兔子（初始一对大兔子和它们生的一对小兔子，以及额外引入的一对大兔子）

    long long dp[n+1];
    dp[0] = 2; // 第0个月有2对兔子
    dp[1] = 3; // 第1个月有3对兔子

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2]; // 从第2个月开始，每对兔子的数量是前两个月兔子数量的总和
    }
    return dp[n];
}
