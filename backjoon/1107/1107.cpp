// 22.05.14. 리모컨
#include <iostream>
#include <cmath>
using namespace std;

int answer;
int N, M;
bool numbers[10];
int INF = 1000001;

void Input() {
    cin >> N >> M;

    int n;
    for(int i = 0; i < M; i++) {
        cin >> n;
        numbers[n] = true; 
    }  
}

bool check(int num) {
    if (num == 0) {
        if (numbers[0]) return false;
        return true;
    }

    while (num) {
        if (numbers[num % 10]) return false;

        num /= 10;
    }

    return true;
}

int main() {
    Input();

    int tmp;
    answer = abs(N - 100);

    for(int i = 0; i < INF; i++) {
        int num = i;

        if (check(num)) {
            tmp = to_string(num).length();
            tmp += abs(N - num);

            answer = min(answer, tmp);
        }
    }

    cout << answer << endl;

    return 0;
}