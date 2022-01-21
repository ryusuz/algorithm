//week12-4 최대값과 최소값
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    istringstream ss(s);
    vector<int> split;
    
    while (!ss.eof()) {
        string tmp = "";
        ss >> tmp;
        split.push_back(stoi(tmp));
    }
    
    sort(split.begin(), split.end());
    answer = to_string(split[0]) + " " + to_string(split[split.size() - 1]);
    
    
    return answer;
}