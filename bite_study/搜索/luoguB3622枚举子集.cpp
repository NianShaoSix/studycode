//https://www.luogu.com.cn/problem/B3622
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string path;
int n;

void dfs(int pos){
    if(pos > n){
        cout << path << endl;
        return ;
    }

    path+='N';
    dfs(pos+1);
    path.pop_back();

    path+='Y';
    dfs(pos+1);
    path.pop_back();
}


int main(){
    cin >> n;
    dfs(1);

    return 0;
}