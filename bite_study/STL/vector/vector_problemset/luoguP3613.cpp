#include <iostream>
#include <vector>
using namespace std;
const int  N = 1e5+10;
int n,q;


int main() {
    vector<int>vec[N];//创建n个动态数组
    cin >> n >> q;
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int a,b,c;
            cin >> a >> b >>c;
            if(vec[a].size()<=b)//数组大小未知
            vec[a].resize(b+1);//不够就扩容
             
            vec[a][b]=c;
        }
        if(x==2){
            int a,b;
            cin >> a >> b;
            cout << vec[a][b];
            puts("");
        }
    }
    return 0;
}
 /*void moveZeroes(vector<int>& nums) {
     for(int i=0,current=-1;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[++current]);
        }
     }
     
    }*/