#include<iostream>
using namespace std;
struct nairong{
	int number;
	int price;
};
int main(){
	int n,m;
	cin>>n>>m;
	int sum,allprice;
	struct nairong nr[m];
	for(int i=0;i<m;i++){
		cin>>nr[i].price>>nr[i].number;
	}
	int len=sizeof(nr)/sizeof(nr[0]);
    for(int i=0;i<len;i++){
        for(int j=0;j<n-i-1;j++){
            if(nr[j].price>nr[j+1].price){
                struct nairong temp=nr[j];
                nr[j]=nr[j+1];
                nr[j+1]=temp;
            }
        }
    }
    int i=0;
    while(n>0){
        if(n>=nr[i].number){
        	n-=nr[i].number;
        	allprice+=nr[i].number*nr[i].price;
        	i++;
		}
		else {
			allprice+=nr[i].number*nr[i].price;
			i++;
			n=0;
		}
    }
    cout<<allprice;
}
