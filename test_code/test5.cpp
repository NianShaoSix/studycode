#include <iostream>
#include <iomanip>
using namespace std;
typedef struct{
    int i,j;//非零元的行下标和列下标
    int e;
}Triple;//三元组
typedef struct {
    Triple data[12500+1];//非零元三元组表，date[0]未用
    int cpot[12500+1];//各列第一个非零元的位置表
    int rpos[12500+1];//各行第一个非零元的位置表
    int num[12500+1];//每行非零元素的个数
    int mu,nu,tu;//矩阵的行数、列数和非零元个数
}RTSMatrix;//行逻辑链接顺序表

void printMatrix(RTSMatrix matrix);
void printMenu();
int FastTransposeSMtrix(RTSMatrix M,RTSMatrix &T);
void initTwoMtrixs(RTSMatrix &a,RTSMatrix &b);
int MultSMatrix(RTSMatrix M, RTSMatrix N,RTSMatrix &Q);
int AddMatrix(RTSMatrix a,RTSMatrix b,RTSMatrix &sum);


int main(){
    bool flag=true;
    while(flag){printMenu();
    cout<<"请输入你需要的行列式操作"<<endl;
    int choice=0;
    cin>>choice;
    switch(choice){
        case 1:{//矩阵的转置
            RTSMatrix a;
            cout<<"请输入原矩阵的行数、列数、非零元素个数"<<endl;
            cin>>a.mu>>a.nu>>a.tu;
            cout<<"请输入原矩阵的非零元素的行下标、列下标和数值"<<endl;
            for(int k=1;k<=a.tu;k++){
            cin>>a.data[k].i>>a.data[k].j>>a.data[k].e;
            }
            cout<<"原矩阵为："<<endl;
            printMatrix(a);
            RTSMatrix b;
            FastTransposeSMtrix(a,b);
            cout<<"转置后的矩阵为:"<<endl;
            printMatrix(b);
            break;
        }
        case 2:{//两个矩阵的加法
            RTSMatrix a,b;//声明两个稀疏矩阵
            RTSMatrix sum;
            initTwoMtrixs(a,b);
            AddMatrix(a,b,sum);
            break;
        }
            
         case 3:  {
            RTSMatrix a,b;
            initTwoMtrixs(a,b);
            RTSMatrix c;
            MultSMatrix(a,b,c);
            cout<<"两个矩阵相乘后的结果为："<<endl;
            printMatrix(c);
            break;
            }
            case 4: flag=false;break;
        }
        
    }
}
void printMatrix(RTSMatrix matrix){
    int count=1;
    for(int row=1;row<=matrix.mu;++row){
        for(int col=1;col<=matrix.nu;++col){
            if(row==matrix.data[count].i&&col==matrix.data[count].j) 
            {
                cout<<setw(3)<<matrix.data[count].e;
                count++;
           }
           else cout<<setw(3)<<0;
        }
        cout<<endl;
    }
} //打印矩阵式

int FastTransposeSMtrix(RTSMatrix M,RTSMatrix &T){
    T.mu=M.nu;T.nu=M.mu;T.tu=M.tu;
    if(T.tu){
        for(int col=1;col<=M.nu;++col) T.num[col]=0;
        for(int t=1;t<=M.tu;++t) ++T.num[M.data[t].j];//求M中每一行含非零元素个数 
        T.cpot[1]=1;
        //求第col列中第一个非零元在b.data中的序号
        for(int col=2;col<=M.nu;++col) T.cpot[col]=T.cpot[col-1]+T.num[col-1];
        for(int p=1;p<=M.tu;++p){
            int col=0;int q=0;
            col=M.data[p].j;q=T.cpot[col];
            T.data[q].i=M.data[p].j; T.data[q].j=M.data[p].i;
            T.data[q].e=M.data[p].e; ++T.cpot[col];
        }
    }
   return 1;
}//快速转置算法

void printMenu(){
    cout<<"-------行列式操作-------"<<endl;
    cout<<"-----1.行列式转置-----"<<endl;
    cout<<"-----2.两个行列式的加法"<<endl;
    cout<<"-----3.两个行列式的乘法"<<endl;
    cout<<"-----4.退出程序-------"<<endl;
}

void initTwoMtrixs(RTSMatrix &a,RTSMatrix &b){
    cout<<"请输入a矩阵的行数、列数和非零元个数"<<endl;
    cin>>a.mu>>a.nu>>a.tu;
    cout<<"请输入a矩阵的非零元素的行下标、列下标和数值"<<endl;
    for(int k=1;k<=a.tu;k++){
        cin>>a.data[k].i>>a.data[k].j>>a.data[k].e;
    }
     cout<<"请输入b矩阵的行数、列数和非零元个数"<<endl;
    cin>>b.mu>>b.nu>>b.tu;
    cout<<"请输入b矩阵的非零元素的行下标、列下标和数值"<<endl;
    for(int k=1;k<=b.tu;k++){
        cin>>b.data[k].i>>b.data[k].j>>b.data[k].e;
        }

    for(int i=1;i<=a.mu;i++) a.rpos[i]=0;
    for(int k=1;k<=a.tu;k++){
        if(a.rpos[a.data[k].i]==0) a.rpos[a.data[k].i]=k;
    }
    for(int i=1;i<=b.mu;i++) b.rpos[i]=0;
    for(int k=1;k<=b.tu;k++){
        if(b.rpos[b.data[k].i]==0) b.rpos[b.data[k].i]=k;
    }
    
    cout<<"矩阵a为:"<<endl;
    printMatrix(a);
    cout<<"矩阵b为:"<<endl;
    printMatrix(b);
}

int MultSMatrix(RTSMatrix M, RTSMatrix N,RTSMatrix &Q){
    //求矩阵乘积Q=M*N,采用行逻辑链接存储方式
    if(M.nu != N.mu) return -1;
    Q.mu = M.mu;Q.nu = N.nu;Q.tu = 0;
    if(M.tu * N.tu != 0){//Q是非零矩阵
        int arow = 0,brow = 0,tp = 0;
        int ctemp[M.mu+1]={0};
        for(arow = 1;arow <= M.mu;++arow){
            for(int t = 1;t <= Q.nu;++t) ctemp[t] = 0;
            Q.rpos[arow] = Q.tu + 1;
            if(arow < M.mu) tp = M.rpos[arow + 1];
            else tp = M.tu + 1;
            for(int p = M.rpos[arow];p < tp;++p){
                int brow = M.data[p].j;
                int t = N.rpos[brow];
                if(brow < N.mu) tp = N.rpos[brow + 1];
                else tp = N.tu + 1;
                for(int q = t;q < tp;++q){
                    int ccol = N.data[q].j;
                    ctemp[ccol] += M.data[p].e * N.data[q].e;
                }
            }
            for(int t = 1;t <= Q.nu;++t){
                if(ctemp[t]){
                    if(++Q.tu > 12500) return 0;
                    Q.data[Q.tu].i = arow;
                    Q.data[Q.tu].j = t;
                    Q.data[Q.tu].e = ctemp[t];
                }
            }
        }
        return 1;
    }
}

int AddMatrix(RTSMatrix a,RTSMatrix b,RTSMatrix &sum){
    if(a.mu==b.mu&&a.nu==b.nu){
                sum.mu=a.mu;
                sum.nu=a.nu;
                int arr1[a.mu][a.nu];
                int arr2[b.mu][b.nu];
                int arr3[sum.mu][sum.nu];
                int count=1;
                for(int i=0;i<a.mu;i++){
                    for(int j=0;j<a.nu;j++){
                        if(a.data[count].i==(i+1)&&a.data[count].j==(j+1)){
                            arr1[i][j]=a.data[count].e;
                            count++;
                        }
                        else arr1[i][j]=0;
                    }
                }
                    int count2=1;
                 for(int i=0;i<b.mu;i++){
                    for(int j=0;j<b.nu;j++){
                        if(b.data[count2].i==(i+1)&&b.data[count2].j==(j+1)){
                            arr2[i][j]=b.data[count2].e;
                            count2++;
                        }
                        else arr2[i][j]=0;
                    }
                }
                for(int i=0;i<sum.mu;i++){
                    for(int j=0;j<sum.nu;j++){
                        arr3[i][j]=arr1[i][j]+arr2[i][j];
                    }
                }      
                 //两行列式相加
                 cout<<"两个矩阵相加后的结果为："<< endl;
                 for(int i=0;i<sum.mu;i++){
                    for(int j=0;j<sum.nu;j++){
                        cout << setw(3) << arr3[i][j];
                    }
                    cout<< endl;
                 }
                
            }
            else cout<<"a,b两个矩阵不是同类型矩阵无法相加"<<endl;
            
        }

