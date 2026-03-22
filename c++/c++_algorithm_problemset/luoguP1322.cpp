#include <bits/stdc++.h>
using namespace std;

string s;
int pos;

void skipSpaces() {
    while (pos < (int)s.size() && s[pos] == ' ') pos++;
}

string readWord() {
    string word;
    while (pos < (int)s.size() && s[pos] != ' ' && s[pos] != '[' && s[pos] != ']') {
        word += s[pos++];
    }
    return word;
}

int readNum() {
    int n = 0;
    while (pos < (int)s.size() && isdigit(s[pos])) {
        n = n * 10 + (s[pos++] - '0');
    }
    return n;
}

int parseBlock() {
    int val = 0;
    while (pos < (int)s.size() && s[pos] != ']') {
        skipSpaces();
        if (pos >= (int)s.size() || s[pos] == ']') break;

        string cmd = readWord();
        skipSpaces();

        if (cmd == "FD") {
            val += readNum();
        } else if (cmd == "BK") {
            val -= readNum();
        } else if (cmd == "REPEAT") {
            int n = readNum();
            skipSpaces();
            if (pos < (int)s.size() && s[pos] == '[') pos++; // skip '['
            int blockVal = parseBlock();
            if (pos < (int)s.size() && s[pos] == ']') pos++; // skip ']'
            val += n * blockVal;
        }
        skipSpaces();
    }
    return val;
}

int main() {
    getline(cin, s);
    pos = 0;
    cout << abs(parseBlock()) << endl;
    return 0;
}