#include <bits/stdc++.h>
using namespace std;
int arr[7][7];
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,1,-1};
void dfs(int i, int j) {
    if (i<1||i>6||j<1||j>6||arr[i][j]!=0) return ;
    arr[i][j] = 0;//涂色
    
}
int main() {

}