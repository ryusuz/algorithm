// week12 2주차
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string cal_grade(double avg) {
    if (avg >= 90) return "A";
    else if (avg >= 80) return "B";
    else if (avg >= 70) return "C";
    else if (avg >= 50) return "D";
    else return "F";
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for (int i = 0; i < scores[0].size(); i++) {
        int sum = 0, count = scores.size();
        int avg = 0;
        vector<int> tmp;
        
        for (int j = 0; j < scores.size(); j++) {
            tmp.push_back(scores[j][i]);
            sum += scores[j][i];
        }
                
        int max = *max_element(tmp.begin(), tmp.end());
        int min = *min_element(tmp.begin(), tmp.end());
        
        if (scores[i][i] == max) {
            sum -= max;
            avg = sum / (count - 1);
        } else if (scores[i][i] == min) {
            sum -= min;
            avg = sum / (count - 1);
        } else {
            avg = sum / count;
        }
        
        answer += cal_grade(avg);
    }
    
    return answer;
}