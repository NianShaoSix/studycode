//枚举对象对算法的影响 
//1.----------------枚举月日--------------------.1 
//#include <iostream>
//using namespace std;
//int x,y;
//int day[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
//int ret;
//int main(){
//	cin >> x >>y;
//	//枚举月日的组合 
//	for(int i = 1;i <= 12; i++){
//		for(int j = 1;j <= day[i];j++){
//			int k = j%10*1000 + j/10*100 + i%10*10 + i/10;
//			int num = k*10000 + i * 100 + j;
//			if(x<=num&&num<=y) ret++;
//		}
//	} 
//	cout << ret;
//	return 0;
//}


//2.-----------------枚举年份----------------------.2 
