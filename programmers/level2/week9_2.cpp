//week9-2 큰 수 만들기
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int num_size = number.size() - k;
    int start = 0;
    
    for(int i = 0; i < num_size; i++) {
        int max_num = number[start];
        int max_idx = start;
        
        for(int j = start; j <= k + i; j++) {
            if (max_num < number[j]) {
                max_num = number[j];
                max_idx = j;
            }
        }
        
        start = max_idx + 1;
        answer += max_num;
    }
    
    
    return answer;
}