// 22.05.14. 리모컨
#include <iostream>
#include <cmath>
using namespace std;

int answer;
int N, M;
bool numbers[10];
int target[6];

void Input() {
    cin >> N >> M;

    int n;
    for(int i = 0; i < M; i++) {
        cin >> n;
        numbers[n] = true; 
    }  
}

int getNum(int num) {
    int i = 1;

    if (!numbers[num]) return num;

    while (1) {
        if (num - i > -1 && !numbers[num - i]) return num - i;

        if (num + i < 10 && !numbers[num + i]) return num + i;

        if (num - i < 0 && num + i > 9) break;

        i++;
    }

    return -1;
}

int main() {
    Input();

    answer = abs(100 - N);

    int n = N;
    int tsize = 0;

    while (n > 0) {
        target[tsize] = n % 10;
        n /= 10;
        tsize++;
    }

    int tmp = 0;
    int idx = 0;
    bool check = false;

    for(int i = tsize - 1; i >= 0; i--) {
        if (check) {
            tmp += idx * pow(10, i);
            continue;
        }

        int num = target[i];

        if (!numbers[num]) {
            tmp += num * pow(10, i);
            continue;
        }

        idx = getNum(num);

        if (idx == -1) {
            cout << answer << endl;
            return 0;
        }

        tmp += idx * pow(10, i);

        check = true;

        if (idx < num) {    // idx가 크면 가장 작은 수 만들기
            for (int i = 9; i >=0; i--) {
                if (!numbers[i])  {
                    idx = i;
                    break;
                }
            }
        } else if (idx > num) {            // idx가 작으면 가장 큰 수 만들기
            for(int i = 0; i < 10; i++) {
                if (!numbers[i]) {
                    idx = i;
                    break;
                }
            }
        }
    }

    tmp = tsize + abs(N - tmp);

    answer = min(answer, tmp);
    cout << answer << endl;

    return 0;
}