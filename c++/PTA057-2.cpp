#include<iostream>
using namespace std;

// ��������
long long cl(int n);

int main() {
    int n;
    cin >> n;
    cout << cl(n) << endl;
    return 0;
}

// ��������
long long cl(int n) {
    if (n == 0) return 2; // ��0������2�����ӣ���ʼһ�Դ����ӺͶ��������һ�ԣ�
    if (n == 1) return 3; // ��1������3�����ӣ���ʼһ�Դ����Ӻ���������һ��С���ӣ��Լ����������һ�Դ����ӣ�

    long long dp[n+1];
    dp[0] = 2; // ��0������2������
    dp[1] = 3; // ��1������3������

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2]; // �ӵ�2���¿�ʼ��ÿ�����ӵ�������ǰ�����������������ܺ�
    }
    return dp[n];
}
