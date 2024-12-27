/*#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int k,d,m,f,q;
int  a[100010],b[100010],c[100010],e[100010];
double s[100010];
int choose[4];int cnt[1000]={0};//记录选到哪个人
//分别为守门员 后卫 中场 前锋
bool compare(int  &x,int &y){
    return x>y;
}
int main() {
    cin >> k >> d >> m >> f;
    for(int i=1;i<=k;i++) {
        cin >> a[i];
    }
    sort(a+1,a+k+1,compare);
    for(int i=1;i<=d;i++) {
        cin >> b[i];
    }
    sort(b+1,b+d+1,compare);
    for(int i=1;i<=m;i++) {
        cin >> c[i];
    }
    sort(c+1,c+m+1,compare);
    for(int i=1;i<=f;i++) {
        cin >> e[i];
    }
    sort(e+1,e+f,compare);
    cin>>q;
    for(int j=1;j<=q;j++){
        for(int i=1;i<=3;i++){
            cin>>choose[i];//输入阵型
        }
        s[j]=a[j];//要一个守门员
        //要后卫
        for(int i = 1;i<=choose[1];i++){
            s[j]+=b[cnt[1]+i];
        }
        cnt[1]+=choose[1];
        //要中场
        for(int i=1;i<=choose[2];i++){
             s[j]+=c[cnt[2]+i];
        }
        cnt[2]+=choose[2];
        //要前锋
        for(int i=1;i<=choose[3];i++){
              s[j]+=e[cnt[3]+i];
        }
        cnt[3]+=choose[3];
         cout << fixed <<setprecision(2)<< s[j]/11;
        puts("");
}
        return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],d[100005];
int k,g,f,m,q;
double tbh;
bool cmp(int a,int b){//从大至少排序
    return a>b;
}
int main(){
    cin>>k>>g>>f>>m;
    for(int i=1;i<=k;i++)
       cin>>a[i];
    for(int i=1;i<=g;i++)
       cin>>b[i];
    for(int i=1;i<=f;i++)
       cin>>c[i];
    for(int i=1;i<=m;i++) //往死里输入
       cin>>d[i];
    sort(a+1,a+k+1,cmp);
    sort(b+1,b+g+1,cmp);
    sort(c+1,c+f+1,cmp);
    sort(d+1,d+m+1,cmp);//往死里排序
    cin>>q;
    int l,z,y;
    int x=1,r=1,w=1,h=1;
    int sss;
    while(q--){
    	cin>>l>>z>>y;
    	tbh=0;
    	tbh+=a[x];//守门员
    	x++;//序号++
    	for(int i=r;i<r+l;i++)
    	   tbh+=b[i];//后卫
    	r+=l;
    	for(int i=w;i<w+z;i++)
    	   tbh+=c[i];//中场
    	w+=z;
    	for(int i=h;i<h+y;i++)
    	   tbh+=d[i];//前锋
    	h+=y;
    	printf("%.2f\n",tbh/11);//一共十一人
    }
    return 0;
}