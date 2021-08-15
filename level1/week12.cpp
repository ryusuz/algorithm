// week12 2주차
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string cal_grade(int avg) {
    if (avg >= 90) return "A";
    else if (avg >= 80) return "B";
    else if (avg >= 70) return "C";
    else if (avg >= 50) return "D";
    else return "F";
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for (int i = 0; i < scores[0].size(); i++) {
        vector<int> tmp;
        int sum = 0; 
        
        for (int j = 0; j < scores.size(); j++) {
            sum += scores[j][i];
            tmp.push_back(scores[j][i]);
        }
        
        int max = *max_element(tmp.begin(), tmp.end());
        int min = *min_element(tmp.begin(), tmp.end());
        int count = 0, avg = 0;
        
        if (tmp[i] == max) {
            for (auto& elem : tmp) {
                if (elem == max) count++;
            }
            
            if (count == 1) {
                avg = (sum - max) / (tmp.size() - 1);
            } else {
                avg = sum / tmp.size();
            }
            
            answer += cal_grade(avg);
            
        } else if (tmp[i] == min) {
            for (auto& elem : tmp) {
                if (elem == min) count++;
            }
            
            if (count == 1) {
                avg = (sum - min) / (tmp.size() - 1);
            } else {
                avg = sum / tmp.size();
            }
            answer += cal_grade(avg);
        } else {
            avg = sum / tmp.size();
            answer += cal_grade(avg);
        }
        
    }
    return answer;
}