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