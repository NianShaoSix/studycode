/*#include<iostream>
#include<queue>

using namespace std;

queue<int> q;//队列模拟内存情况
int m,n,ans;
bool inq[1010];//判断单词是否在内存中

int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(inq[x])continue;//能够在内存中查找就跳过
		else
		{
        	//如果内存满了，最早进入内存的那个单词出列
			if(q.size()>=m)
			{
				inq[q.front()]=false;
				q.pop();
			}
            //把外存的结果加入内存以便下次查找
			q.push(x);
			inq[x]=true;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}*/

#include <iostream>
#include <queue>
using namespace std;
bool vis[1010];//判断单词是否在内
queue<int> q;//队列
int m,n,res;
int main() {
    cin >> m >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(vis[x]) continue;
        else {
            if(q.size()>=m){
                vis[q.front()]=false;
                q.pop();
            }
            q.push(x);
            vis[x]=true;
        }
        res++;
    }
    cout <<res;
    return 0;
}




















