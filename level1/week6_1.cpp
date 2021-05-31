// week6-1 실패율
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
bool compare(pair<double, int>& front, pair<double, int>& back);

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    vector<int> challenge(N);
    vector<int> fail(N);
    vector<pair<double, int>> fail_rate(N);
    
    for (int i = 0; i < stages.size(); i++) {
        int count = stages[i];
        
        for (int j = 0; j < count; j++) {
            challenge[j]++;
        }
        
        fail[count - 1]++;
    }
    
    for (int i = 0; i < N; i++) {
        if (challenge[i]==0)  fail_rate[i] = make_pair(0, i+1);
        else fail_rate[i] = make_pair((double)fail[i]/challenge[i], i+1);
    }
            
    sort(fail_rate.begin(), fail_rate.end(), compare);
    
    for (int i = 0; i < N; i++) {
        int stage = fail_rate[i].second;
        answer[i] = stage;
    }
    
    return answer;
}

bool compare(pair<double, int>& front, pair<double, int>& back)
{
	double front_cnt = front.first;
	int front_char = front.second;
	
	double back_cnt = back.first;
	int back_char = back.second;

	if (front_cnt < back_cnt) return front_cnt > back_cnt;
	
	else if (front_cnt == back_cnt)	return front_char < back_char;
	
	else return front_cnt > back_cnt;
}