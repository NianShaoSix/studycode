#include <iostream>
#include <vector>//没办法去重
#include <unordered_map>
#include <set>
using namespace std;
unordered_map<string,set<int>> mp;
int n;
int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        int len;
        scanf("%d",&len);
        while(len--){
            string word;
            cin >> word;
            mp[word].insert(i);
        }
    }
    int a;
    scanf("%d",&a);
    while(a--){
        string word2;
        cin >> word2;
        if(!mp.count(word2)){
           puts(""); 
           continue;
        }
        for(auto e:mp[word2]){
            cout << e << " ";
        }
        puts(""); 
    }
    return 0;
}