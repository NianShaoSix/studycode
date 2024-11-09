#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef struct xuanpiao{
	char ch;
	int number;
}xp;
bool compareByNumber(xp& a,xp& b){
	return a.number>b.number;
}
int main(){
	xp xuans[4];	
	xuans[0].ch='A';xuans[1].ch='B';xuans[2].ch='C';xuans[3].ch='D';
	xuans[0].number=xuans[1].number=xuans[2].number=xuans[3].number=0;
	int n;
	cin>>n;
	char arr[n];
	srand(1000);
	for(int i=0;i<n;i++){
		arr[i]='A'+rand()%4;
	}
	int a=0,b=0,c=0,d=0;
	for(int i=0;i<n;i++){
		if(arr[i]=='A'){
			xuans[0].number++;
		}
		if(arr[i]=='B'){
			xuans[1].number++;
		}
		if(arr[i]=='C'){
			xuans[2].number++;
		}
		if(arr[i]=='D')
		xuans[3].number++;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
	sort(xuans,xuans+4,compareByNumber);
	cout<<endl;
	for(int i=0;i<4;i++){
		cout<<xuans[i].ch<<":"<<xuans[i].number<<' ';
	}
	
	
	return 0;
}
