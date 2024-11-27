#include <iostream>
#include <iomanip>
using namespace std;

struct Triple {
    int i, j, e;
};

typedef struct {
    Triple data[12500+1]; // 非零元三元组表，data[0]未用
    int cpot[12500+1]; // 各列第一个非零元的位置表
    int rpos[12500+1]; // 各行第一个非零元的位置表
    int num[12500+1]; // 每行非零元素的个数
    int mu, nu, tu; // 矩阵的行数、列数和非零元个数
} RTSMatrix; // 行逻辑链接顺序表

void printMatrix(RTSMatrix matrix);
void printMenu();
int FastTransposeSMtrix(RTSMatrix M, RTSMatrix &T);
void initTwoMtrixs(RTSMatrix &a, RTSMatrix &b);
int MultSMatrix(RTSMatrix M, RTSMatrix N, RTSMatrix &Q);

int main() {
    printMenu();
    cout << "请输入你需要的行列式操作" << endl;
    int choice = 0;
    cin >> choice;
    switch (choice) {
        case 1: { // 矩阵的转置
            RTSMatrix a;
            cout << "请输入原矩阵的行数、列数、非零元素个数" << endl;
            cin >> a.mu >> a.nu >> a.tu;
            cout << "请输入原矩阵的非零元素的行下标、列下标和数值" << endl;
            for (int k = 1; k <= a.tu; k++) {
                cin >> a.data[k].i >> a.data[k].j >> a.data[k].e;
            }
            cout << "原矩阵为：" << endl;
            printMatrix(a);
            RTSMatrix b;
            FastTransposeSMtrix(a, b);
            cout << "转置后的矩阵为:" << endl;
            printMatrix(b);
            break;
        }
        case 2: { // 两个矩阵的加法
            RTSMatrix a, b; // 声明两个稀疏矩阵
            RTSMatrix sum;
            initTwoMtrixs(a, b);
            // 矩阵加法的实现
            break;
        }
        case 3: { // 矩阵的乘法
            RTSMatrix a, b;
            initTwoMtrixs(a, b);
            RTSMatrix c;
            MultSMatrix(a, b, c);
            cout << "两个矩阵相乘后的结果为：" << endl;
            printMatrix(c);
            break;
        }
    }
    return 0;
}

void printMatrix(RTSMatrix matrix) {
    int count = 1;
    for (int row = 1; row <= matrix.mu; ++row) {
        for (int col = 1; col <= matrix.nu; ++col) {
            if (count <= matrix.tu && row == matrix.data[count].i && col == matrix.data[count].j) {
                cout << setw(3) << matrix.data[count].e;
                count++;
            } else {
                cout << setw(3) << 0;
            }
        }
        cout << endl;
    }
}

int FastTransposeSMtrix(RTSMatrix M, RTSMatrix &T) {
    // 快速转置稀疏矩阵
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if (T.tu) {
        int num[M.nu + 1] = {0};
        int cpot[M.nu + 1] = {0};
        for (int t = 1; t <= M.tu; ++t) {
            ++num[M.data[t].j];
        }
        cpot[1] = 1;
        for (int col = 2; col <= M.nu; ++col) {
            cpot[col] = cpot[col - 1] + num[col - 1];
        }
        for (int p = 1; p <= M.tu; ++p) {
            int col = M.data[p].j;
            int q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        }
    }
    return 0;
}

int MultSMatrix(RTSMatrix M, RTSMatrix N, RTSMatrix &Q) {
    // 求矩阵乘积 Q = M * N，采用行逻辑链接存储方式
    if (M.nu != N.mu) return -1;
    Q.mu = M.mu;
    Q.nu = N.nu;
    Q.tu = 0;
    if (M.tu * N.tu != 0) { // Q 是非零矩阵
        int arow = 0, tp = 0;
        int ctemp[Q.nu + 1];
        for (arow = 1; arow <= M.mu; ++arow) {
            for (int t = 1; t <= Q.nu; ++t) ctemp[t] = 0;
            Q.rpos[arow] = Q.tu + 1;
            if (arow < M.mu) tp = M.rpos[arow + 1];
            else tp = M.tu + 1;
            for (int p = M.rpos[arow]; p < tp; ++p) {
                int brow = M.data[p].j;
                int t = N.rpos[brow];
                int tp2;
                if (brow < N.mu) tp2 = N.rpos[brow + 1];
                else tp2 = N.tu + 1;
                for (int q = t; q < tp2; ++q) {
                    int ccol = N.data[q].j;
                    ctemp[ccol] += M.data[p].e * N.data[q].e;
                }
            }
            for (int t = 1; t <= Q.nu; ++t) {
                if (ctemp[t]) {
                    if (++Q.tu > 12500) return 0;
                    Q.data[Q.tu].i = arow;
                    Q.data[Q.tu].j = t;
                    Q.data[Q.tu].e = ctemp[t];
                }
            }
        }
    }
    return 0;
}

void printMenu() {
    cout << "1. 矩阵的转置" << endl;
    cout << "2. 两个矩阵的加法" << endl;
    cout << "3. 矩阵的乘法" << endl;
}

void initTwoMtrixs(RTSMatrix &a, RTSMatrix &b) {
    cout << "请输入a矩阵的行数、列数和非零元个数" << endl;
    cin >> a.mu >> a.nu >> a.tu;
    cout << "请输入a矩阵的非零元素的行下标、列下标和数值" << endl;
    for (int k = 1; k <= a.tu; k++) {
        cin >> a.data[k].i >> a.data[k].j >> a.data[k].e;
    }
    // 初始化 a 矩阵的 rpos
    for (int i = 1; i <= a.mu; i++) {
        a.rpos[i] = 0;
    }
    for (int k = 1; k <= a.tu; k++) {
        if (a.rpos[a.data[k].i] == 0) {
            a.rpos[a.data[k].i] = k;
        }
    }

    cout << "请输入b矩阵的行数、列数和非零元个数" << endl;
    cin >> b.mu >> b.nu >> b.tu;
    cout << "请输入b矩阵的非零元素的行下标、列下标和数值" << endl;
    for (int k = 1; k <= b.tu; k++) {
        cin >> b.data[k].i >> b.data[k].j >> b.data[k].e;
    }
    // 初始化 b 矩阵的 rpos
    for (int i = 1; i <= b.mu; i++) {
        b.rpos[i] = 0;
    }
    for (int k = 1; k <= b.tu; k++) {
        if (b.rpos[b.data[k].i] == 0) {
            b.rpos[b.data[k].i] = k;
        }
    }

    cout << "矩阵a为:" << endl;
    printMatrix(a);
    cout << "矩阵b为:" << endl;
    printMatrix(b);
}