#include <iostream>
#include  <cstring>
using namespace std;

const int N = 25;
int a[N],t[N];
int n;

int check(int x,int y){
	int res = 0;
	for(int i = 0;i < n;i++){
		if(((x>>i)&1)==0&&((y>>i)&1)==1) res++;
		if(((x>>i)&1)==1&&((y>>i)&1)==0) return -1;
	}
	return res;
}

int solve(){
	int ret = 0x3f3f3f3f;//记录最小的改变次数 
	//枚举第一行的最终状态 
	for(int st = 0;st <(1<<n);st++){
		memcpy(t,a,sizeof a);
		int change = st;
		int cnt = 0;//0->1的个数
		bool flag = true;
		
		for(int i = 1;i<=n;i++){
			//检查change是否合法
			int c = check(t[i],change);
			if(c==-1){
				flag = false;
				break;
			} 
			cnt +=c;//累加次数
			//当前行的最终状态
			t[i] = change;
			//计算下一行的状态
			change = t[i-1]^(t[i]>>1)^(t[i]<<1);
			//消除最高位前一位出现1的影响
			change &=(1<<n)-1;
		}
		if(flag) ret =min(ret,cnt);	 
	}
	if(ret==0x3f3f3f3f) return -1;
	else return ret;
}

int main(){
	int T;cin >> T;
	//读入数据 以二进制存储 
	for(int i = 1;i <= T;i++){
		//多组数据输入清空数据 
		memset(a,0,sizeof a);
		 cin >> n;
		for(int j = 1;j <=n;j++){//避免越界访问 
			for(int l = 0;l < n;l++){
				int x;cin >> x;
				if(x) a[j]|=1<<l;
			}
		}
		printf("Case %d: %d\n",i,solve());
	}
	return 0;
}
