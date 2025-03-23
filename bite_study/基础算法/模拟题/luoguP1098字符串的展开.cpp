#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int p1,p2,p3,n;
string s,ret;
void add(char a,char b){
	string t;
	for(char i = a + 1;i < b; i++){
		//处理p1 
		char c = i;
		if(p1 == 2&&islower(a)){
			 c = i - 32;
		}
		else if(p1 == 3){
			 c = '*';
		}
		//处理p2
		for(int j = 0;j < p2;j++){
			t+=c;
		} 
	}
	if(p3 == 2){
		reverse(t.begin(),t.end());
	}
	ret +=t;			
}
int main(){
	cin >> p1 >> p2 >> p3;
	cin >> s;
	n = s.size();
	
	for(int i = 0;i < n;i++){
		char ch = s[i];
		if(s[i]!='-'||i == 0||i == n - 1){
			ret += ch;
		}
		else{
			char left = s[i-1],right = s[i+1];
			//判断是否展开
			if((isdigit(left)&&isdigit(right)&&right>left)||(islower(left)&&islower(right)&&right>left)) {
				//展开
				add(left,right); 
			}
			else ret+=ch;
		}
	}
	cout << ret;
	return 0;
}
