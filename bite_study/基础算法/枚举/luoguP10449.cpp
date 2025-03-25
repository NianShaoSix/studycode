#include <iostream>
#include <cstring>

using namespace std;

const int N = 10;

int n = 5;
int a[N]; // 用二进制表示，来存储灯的状态
int t[N]; // 备份 a 数组

// 计算 x 的二进制表示中一共有多少个 1
int calc(int x)
{   
    int cnt = 0;
    while(x)
    {
        cnt++;
        x &= x - 1;
    }
    return cnt;
}

int main()
{
    int T; cin >> T;

    while(T--)
    {
        // 多组测试时，一定要注意清空之前的数据
        memset(a, 0, sizeof a);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                char ch; cin >> ch;
                // 存成相反的
                if(ch == '0') a[i] |= 1 << j;
            }
        }

        int ret = 0x3f3f3f3f; // 统计所有合法的按法中的最小值
        // 枚举第一行所有的按法
        for(int st = 0; st < (1 << n); st++)
        {
            memcpy(t, a, sizeof a);
            int push = st; // 当前行的按法
            int cnt = 0; // 统计当前按法下一共按了多少次

            // 依次计算后续行的结果以及按法
            for(int i = 0; i < n; i++)
            {
                cnt += calc(push);
                // 修改当前行被按的结果
                t[i] = t[i] ^ push ^ (push << 1) ^ (push >> 1);
                t[i] &= (1 << n) - 1; // 清空影响
                // 修改下一行的状态
                t[i + 1] ^= push;
                // 下一行的按法
                push = t[i];
            }

            if(t[n - 1] == 0) ret = min(ret, cnt);
        }

        if(ret > 6) cout << -1 << endl;
        else cout << ret << endl;
    }


    return 0;
}