#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct{
    char name[15];
    double beg;
    double end;
}subject;
bool compareSubject(const subject &a,const subject &b){
    return a.end<b.end;
}
int main(){
    int n;
    cin>> n;
    vector<subject> subjects(n);
    for(int i=0;i<n;i++){
        cin>>subjects[i].name>>subjects[i].beg>>subjects[i].end;
    }
    sort(subjects.begin(),subjects.end(),compareSubject);
    int maxnub=1;
    double lastend=subjects[0].end;
    for(int i=1;i<n;i++){
        if(subjects[i].beg>=lastend){
            lastend=subjects[i].end;
            maxnub++;
        }
    }
    cout<<maxnub;
}
