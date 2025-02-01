#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
	
	int n,c;
	cin>>n>>c;
	vector<int>nums(n);
	unordered_map<int,int>countMap;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		countMap[nums[i]]++;
	}
	int res=0;
	for(int num: nums){
		if(countMap.find(num-c)!=countMap.end()){
			res +=countMap[num-c];
		}
		if(num-c==num){
			res--;
		}
	}
	cout<<res<<endl;
}
