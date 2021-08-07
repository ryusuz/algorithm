//week6 - 스킬트리
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (string tree : skill_trees) {
        vector<char> tmp;
        
        for (char c : tree) {
            for (char r : skill) {
                if (c == r) tmp.push_back(c);
            }
        }
        
        int idx = 0;
        bool flag = true;
        for (char c : tmp) {
            if (skill[idx++] != c) {
                flag = false;
                break;
            }
        }
        
        if (flag) answer++;
    }
    
    
    return answer;
}