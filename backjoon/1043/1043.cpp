// 22. 05. 09. 거짓말
#include <iostream>
#include <vector>
using namespace std;

int answer;
int N, M, T;

bool person[51] = {false};     // T: 진실을 아는 사람
vector<vector<int>> info;

void Input() {
    cin >> N >> M >> T;

    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;

        person[n] = true;
    }

    int P;

    for(int i = 0; i < M; i++) {
        cin >> P;
        vector<int> tmp;

        int n;

        for(int j = 0; j < P; j++) {
            cin >> n;

            tmp.push_back(n);
        }

        info.push_back(tmp);
    }

    answer = 0;
}

int main() {
    Input();

   
    

    cout << answer << endl;


    return 0;
}