//week9 순위검색
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> scores;

void addCases(string *s, int score) {
    for (int i = 0; i < 16; i++) {
        string str = "";
        int a = i;
        
        for (int j = 3; j >= 0; j--) {
            if (a <= 0 || a % 2 == 0) str = '-' + str;
            else str = s[j] + str;
            a /= 2;
        }
        scores[str].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string s[4], tmp = "";

    // 1. info parsing
    for (string str : info) {
        istringstream ss(str);
        ss >> s[0] >> s[1] >> s[2] >> s[3] >> tmp;
        addCases(s, (int)stoi(tmp));
    }
    
    // 2. scores 정렬
    for (auto it = scores.begin(); it != scores.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    
    // 3. 쿼리 순회
    for (string str : query) {
        istringstream ss(str);
        ss >> s[0] >> tmp >> s[1] >> tmp >> s[2] >> tmp >> s[3] >> tmp;
        int score = stoi(tmp);

        vector<int> v = scores[s[0] + s[1] + s[2] + s[3]];
        if (v.size() != 0) {
            auto it = lower_bound(v.begin(), v.end(), score);
            //cout << score << " " << v.size() << " " << it - v.begin() << " " << v[it-v.begin()]<< endl;;
            answer.push_back(v.size() - (it - v.begin()));
        } else answer.push_back(0);
        
    }
    
    
    return answer;
}