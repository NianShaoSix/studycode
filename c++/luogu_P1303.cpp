#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a1[2002],b1[2002];
	int a[2002],b[2002];int c[4004];int len;
	cin>>a1>>b1;
	int lena=strlen(a1);
	int lenb=strlen(b1);
	for(int i=1;i<=lena;i++){
		a[i]=a1[lena-i]-'0';
	}
	for(int i=1;i<=lenb;i++){
		b[i]=b1[lenb-i]-'0';
	}
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			c[i+j-1]+=a[i]*b[j];
		}
	}
	for(int i=1;i<=lena+lenb;i++){
		if(c[i]>9){
		
		c[i+1]+=c[i]/10;
		c[i]=c[i]%10;
		}
	
	}
	len=lena+lenb;
    while(c[len]==0&&len>1)len--;
    for(int i=len;i>=1;i--)cout<<c[i];
	
}
