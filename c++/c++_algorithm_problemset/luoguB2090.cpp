#include <iostream>
using namespace std;
int N;
int age;
int cnt1,cnt2,cnt3,cnt4;
int main(){
    cin >> N;
    int n=N;
    while(n--){
        cin >> age;
        if(age >= 0 && age <= 18){
            cnt1++;
        } 
        if(age >= 19 && age<=35){
            cnt2++;
        }
        if(age >=36 && age <= 60){
            cnt3++;
        }
        if(age >= 61){
            cnt4++;
        }
    }
    printf("%.2f%%\n",cnt1*1.0/N*100);
    printf("%.2f%%\n",cnt2*1.0/N*100);
    printf("%.2f%%\n",cnt3*1.0/N*100);
    printf("%.2f%%\n",cnt4*1.0/N*100);
    return 0;
}