//week12-3 오픈채팅방
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> info;
    vector<vector<string>> split;
    
    for (auto& elem : record) {
        vector<string> message(3);
        
        istringstream ss(elem);
        ss >> message[0] >> message[1] >> message[2];
        if (message[0] == "Enter" || message[0] == "Change") info[message[1]] = message[2];

        if (message[0] != "Change") split.push_back(message);
    }
    
    for (auto& elem : split) {
        string message = info[elem[1]];
        
        if (elem[0] == "Enter") message += "님이 들어왔습니다.";
        else if (elem[0] == "Leave") message += "님이 나갔습니다.";
        
        answer.push_back(message);
    }
    
    return answer;
}