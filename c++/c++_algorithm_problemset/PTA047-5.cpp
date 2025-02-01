#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
typedef struct meeting{
	int begin;
	int end;	
}meeting;
bool compareMeetings(meeting &a,meeting &b){
	return a.end<b.end;
}
int main(){
	int N;
	cin>>N;
	int count[N];
	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		vector<meeting> meetings(n);
		for(int j=0;j<n;j++){
			cin>>meetings[j].begin>>meetings[j].end;
		}
		sort(meetings.begin(),meetings.end(),compareMeetings);
		int last=meetings[0].end;
		 count[i]=1;
		for(int l=1;l<n;l++){
			if(meetings[l].begin>=last){
				last=meetings[l].end;
				
				count[i]++;
			}
			
		}
		
	}
	for(int k=0;k<N;k++){
			cout<<count[k]<<endl;
		}
	return 0;
}
