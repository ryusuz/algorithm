//week7 - 기능개발
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    stack<int> st;
    int numOfJob = progresses.size();
    int count = 1;
    
    // 각 배포까지 걸리는 일수 계산
    for (int i = 0; i < numOfJob; i++) {
        int progress = 100 - progresses[i];
        int speed = speeds[i];
        
        if (progress % speed == 0) days.push(progress/speed);
        else days.push(progress/speed + 1);
        //cout << days.back() << endl;
    }
    
    st.push(days.front());
    days.pop();

    while (!days.empty()) {
        if (st.top() >= days.front()) {
            count++;
            days.pop();
        } else {
            answer.push_back(count);
            st.push(days.front());
            days.pop();
            count = 1;
        }
        
        //cout << st.top() << endl;
    }
    
    answer.push_back(count);
    
    
    return answer;
}

// 잘 짠 남의 코드
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}