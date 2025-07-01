//https://www.luogu.com.cn/problem/P1048
#include<iostream>
using namespace std;

int T,M;
const int  N = 110;
int f[N][N],t[N],v[N];
//
int mian()
{
    cin >> T >>M;
    for(int  i = 1;i <= M;++i)
    {
        cin >> t[i]>>v[i];
    }

    for(int i = 1; i <= M;++i)
    {
        for(int j = 1;j <= T;++j)
        {
            f[i][j] = f[i+1][j];
            if(j >= t[i]){
                f[i][j] = max(f[i][j],f[i-1][j]+v[i]);
            }
        }
    }
    cout << f[M][T]<<endl;
    return 0;
}