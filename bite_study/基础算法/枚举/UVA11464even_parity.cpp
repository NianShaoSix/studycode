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
	int ret = 0x3f3f3f3f;//��¼��С�ĸı���� 
	//ö�ٵ�һ�е�����״̬ 
	for(int st = 0;st <(1<<n);st++){
		memcpy(t,a,sizeof a);
		int change = st;
		int cnt = 0;//0->1�ĸ���
		bool flag = true;
		
		for(int i = 1;i<=n;i++){
			//���change�Ƿ�Ϸ�
			int c = check(t[i],change);
			if(c==-1){
				flag = false;
				break;
			} 
			cnt +=c;//�ۼӴ���
			//��ǰ�е�����״̬
			t[i] = change;
			//������һ�е�״̬
			change = t[i-1]^(t[i]>>1)^(t[i]<<1);
			//�������λǰһλ����1��Ӱ��
			change &=(1<<n)-1;
		}
		if(flag) ret =min(ret,cnt);	 
	}
	if(ret==0x3f3f3f3f) return -1;
	else return ret;
}

int main(){
	int T;cin >> T;
	//�������� �Զ����ƴ洢 
	for(int i = 1;i <= T;i++){
		//������������������� 
		memset(a,0,sizeof a);
		 cin >> n;
		for(int j = 1;j <=n;j++){//����Խ����� 
			for(int l = 0;l < n;l++){
				int x;cin >> x;
				if(x) a[j]|=1<<l;
			}
		}
		printf("Case %d: %d\n",i,solve());
	}
	return 0;
}
