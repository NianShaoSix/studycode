#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
	double k;
	cin>>k;
	int n;
	cin>>n;
	 vector<double> arr(n); 
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	double res=0; 
	double current=arr[0];
	for(int i=1;i<n;i++){
		if(current+k<arr[i]){
			res=(arr[i]-current-k)/2.0;
			current=(current+arr[i])/2.0;
		}
		else{
			current=arr[i];
		}
	}
	cout<<fixed<<setprecision(3)<<res<<endl;
}
