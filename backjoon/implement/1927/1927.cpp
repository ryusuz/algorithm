// 22.05.16. 최소힙
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int N, X;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &X);

        if (X == 0) {
            if (pq.empty()) printf("%d \n", 0);
            else {
                printf("%d \n", pq.top());
                pq.pop();
            }
        } else pq.push(X);
    }

    return 0;
}