// 단체사진 찍기 21.10.12.
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(char comp, int dist, int num) {
    if (comp == '=') return dist == num;
    else if (comp == '<') return dist < num;
    else if (comp == '>') return dist > num;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    
    do {
        bool flag = true;
        for (auto& str : data) {
            char f1 = str[0];
            char f2 = str[2];
            char comp = str[3];
            int num = str[4] - '0';
            int diff = friends.find(f1) - friends.find(f2);
            int dist = abs(diff) - 1;
            
            if (check(comp, dist, num)) continue;
            
            flag = false;
            break;
        }
        
        if (flag) answer++;
        
    } while (next_permutation(friends.begin(), friends.end()));
    
    return answer;
}