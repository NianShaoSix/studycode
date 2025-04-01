#include <iostream>
#include <unordered_map>

using namespace std;
int n;
unordered_map<string,int> student;

int main(){
    cin >> n;
    while(n--){
        int op,score;string name;
        cin >> op;
        if(op == 1){
            cin >> name;
            cin >> score;
            // student.insert({name,score});
            student[name] = score;
            cout <<"OK"<<'\n';
        }
        else if(op == 2){
            cin >> name;
            if(!student.count(name)){
                cout <<"Not found"<<'\n';
            }
            else{
                cout <<student[name]<<'\n';
            }
        }
        else if(op == 3){
            cin >> name;
            if(!student.count(name)){
                cout <<"Not found"<<'\n';
            }
            else{
                student.erase(name);
                cout <<"Deleted successfully"<<"\n";
            }
        }
        else{
            cout <<student.size()<<"\n";
        }
    }
    return 0;
}