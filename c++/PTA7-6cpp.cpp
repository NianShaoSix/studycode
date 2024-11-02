#include <iostream>
#include <cstring>
using namespace std;

struct xingxi {
    char id[20];
    char qq[12];
    char gender[2];
    int grade;
    char rank[10];
};

void xiugai(char qq[], xingxi a[], int n, char xiugaixiang[], int choice) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].qq, qq) == 0) {
            switch (choice) {
                case 1: strcpy(a[i].id, xiugaixiang); break;
                case 2: strcpy(a[i].gender, xiugaixiang); break;
                case 3: a[i].grade = atoi(xiugaixiang); break;
                case 4: strcpy(a[i].rank, xiugaixiang); break;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    xingxi a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].qq >> a[i].gender >> a[i].grade >> a[i].rank;
    }
    for (int j = 0; j < m; j++) {
        char qq[12]; int choice; char xiugaixiang[10];
        cin >> qq >> choice >> xiugaixiang;
        xiugai(qq, a, n, xiugaixiang, choice);
    }
    for (int l = 0; l < n; l++) {
        cout << '[' << l + 1 << ']' << ':' << a[l].id << '-' << a[l].qq <<'-' << a[l].gender << '-' <<a[l].grade <<'-' << a[l].rank << endl;
    }
    return 0;
}
/*#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 学长/学姐的信息结构
struct Student {
    string nickname;
    string qq;
    char gender;
    int level;
    string title;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Student> students(n);

    // 读取初始信息
    for (int i = 0; i < n; ++i) {
        cin >> students[i].nickname >> students[i].qq >> students[i].gender
            >> students[i].level >> students[i].title;
    }

    // 处理信息变更
    for (int i = 0; i < m; ++i) {
        string qq;
        int type;
        string newInfo;
        cin >> qq >> type >> newInfo;

        // 找到对应的学生并更新信息
        for (Student &s : students) {
            if (s.qq == qq) {
                switch (type) {
                    case 1: s.nickname = newInfo; break;
                    case 2: s.gender = newInfo[0]; break;
                    case 3: s.level = stoi(newInfo); break;
                    case 4: s.title = newInfo; break;
                }
            }
        }
    }

    // 输出修改后的信息
    for (int i = 0; i < n; ++i) {
        cout << "[" << (i + 1) << "]:" << students[i].nickname
             << "-" << students[i].qq << "-" << students[i].gender
             << "-" << students[i].level << "-" << students[i].title << endl;
    }

    return 0;
}*/