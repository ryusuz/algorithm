// 22.05.16. 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time {
    int start, end;
};

int N;
vector<Time> jobs;
int answer;

bool cmp(Time a, Time b) {
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

void Input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int s, e;
    for(int i = 0; i < N; i++) {
        cin >> s >> e;

        jobs.push_back({s, e});
    }

    answer = 1;
}

int main() {
    Input();

    sort(jobs.begin(), jobs.end(), cmp);

    int prev = 0;
    for(int i = 1; i < N; i++) {
        if (jobs[prev].end <= jobs[i].start) {
            answer++;
            prev = i;
        }
    }

    cout << answer << endl;

    return 0;
}