//week8-7 완주하지 못한 선수
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) return participant[i];
    }
    
    return participant[participant.size() - 1];
}

////////////////////////////
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    
    for (string c : completion) {
        if (m.find(c) == m.end()) m[c] = 1;
        else m[c]++;
    }
    
    for (string p : participant) {
        if (m.find(p) == m.end()) return p;
        else {
            m[p]--;
            
            if (m[p] < 0) return p;
        }
    }
    
    return answer;
}