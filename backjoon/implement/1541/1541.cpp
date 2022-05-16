// 22.05.16. 잃어버린 괄호
#include <iostream>
#include <string>
using namespace std;

string s;
int answer;

int main() {
    cin >> s;
    
    answer = 0;

    string n;
    bool flag = false;
    int op = 1;

    for(int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || i == s.size()) {
            answer += stoi(n) * op;

            op = (flag || s[i] == '-') ? -1 : 1;

            if (s[i] == '-') flag = true;

            n = "";

            continue;
        }

        n += s[i];
    }

    cout << answer << endl;

    return 0;
}