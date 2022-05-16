// 22.05.16. 팩토리얼 0의 개수
#include <iostream>
using namespace std;

int N, answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 5; i <= N; i *= 5) {
        answer += (N / i);
    }
    
    cout << answer << endl;

    return 0;
}