#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{
	int begin;
	int end;
}meeting;
bool comparemeeting(const meeting &a,const meeting &b){
	return a.end<b.end;
}
int main(){
	int n;
	cin>>n;
	vector<meeting> meetings(n);
	for(int i=0;i<n;i++){
		cin>>meetings[i].begin>>meetings[i].end;
	}
	sort(meetings.begin(),meetings.end(),comparemeeting);
	int lasttime=meetings[0].end;
	int meetingnum=1;
	for(int i=1;i<n;i++){
		if(meetings[i].begin>=lasttime)
		{	
			lasttime=meetings[i].end;
			meetingnum++;
		}
	}
	cout<< meetingnum<<endl;
	return 0;
}
