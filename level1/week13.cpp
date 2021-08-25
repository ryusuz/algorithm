// week13 위클리 4주차
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    
    // 1. 테이블 파싱
    vector<vector<string>> langScore;
    
    for (auto& str : table) {
        istringstream ss(str);
        vector<string> score;
        string tmp = "";
        
        while (!ss.eof()) {
            ss >> tmp;
            score.push_back(tmp);
        }
        langScore.push_back(score);
    }
    
    // 2. 언어 - 선호도 병합
    unordered_map<string, int> m;
    
    for (int i = 0; i < languages.size(); i++) {
        m[languages[i]] = preference[i];
    }
    
    // 3. 각 직업군 별 점수 계산
    int maxScore = 0;
    string partName = "";

    for (auto& part : langScore) {
        int score = 0;
        
        for (string lang : languages) {
            for (int i = 1; i < 6; i++) {
                if (part[i] == lang) {
                    score += m[lang] * (6-i);
                    break;
                }
            }
        }
        
        if (maxScore < score) {
            maxScore = score;
            partName = part[0];
        } else if (maxScore == score) {
            if (partName[0] > part[0][0]) {
                partName = part[0];
            }
        }
    }
    
    answer = partName;    
    return answer;
}