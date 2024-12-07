#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	 int n,c,res=0;
	 cin>> n >> c;
	 int arr[n];
	 for(int i=0;i<n;i++){
	 	cin>> arr[i];
	 }
	 sort(arr,arr+n);
	 for(int i=0;i<n;i++){
	 	for(int j=i+1;j<n;j++){
	 		if(arr[j]-arr[i]==c){
	 			res++;
			 }
		 } 
	 }
	 cout<< res << endl;
	 return 0;
}
