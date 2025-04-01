//动态顺序表
#include <iostream>
#include <cstring>
#include <vector>

const int N = 10;
using namespace std;

struct node
{
    int a,b;
    string s;
};

void print(vector<int>&a){
    //for(int i=0;i<a.size();i++){
     //   cout << a[i] <<' ';
   // }
   // puts("");
    //for(auto it= a.begin();it!=a.end();it++){
      // cout << *it << ' ';
   // }
    //puts("");
    //使用语法糖-范围for
    for(auto x:a){
       cout << x <<" ";
    }
    puts("");
}

int main() {
    //1. 创建vector
    vector<int> a1;//创建了一个名为a1的可变长数组
                    //里面都是int类型的数据
    vector<int> a2(N);//创建一个大小为10的数组
    vector<int> a3(N,2);//创建一个大小为10的可变长数组
                        //里面所有元素的值都为2
    vector<int> a4={1,2,3,4,5};//类似数组
    
    //<>里面可以存放任何数据类型，体现了模板的作用和强大
    //这样vector可以存放任何我们见过的数据类型，甚至是STL本身
    vector<string> a5;
    vector<node> a6;
    vector<vector<int>>a7;//创建了一个二位的可变长数组

    vector<int>a8[N];//创建了一个大小为N的vector数组
    //int a[N];
    //print(a2);
   // print(a3);
    //if(a1.empty()) cout<<"空"<<"\n";
    // else cout<<"非空"<<"\n";
    //for(int i=0;i<10;i++){
    //    a2.push_back(i);
    //     print(a2);
    //}
   
    //while(!a2.empty()){
    //    a2.pop_back();
    //     print(a2);
    // }
    //cout<<a2.front();
    //puts("");
    //cout<<a2.back();

    //resize
    vector<int> aa(5,1);
    print(aa);
    aa.resize(10);
    print(aa);
    aa.resize(3);
    print(aa);
    //clear
    cout << aa.size()<<"\n";
    aa.clear();
    cout<<aa.size();
    return 0;
}