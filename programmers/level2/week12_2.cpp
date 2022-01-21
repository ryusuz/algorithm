//week12_2 숫자의 표현
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    int num = (n + 1) / 2, sum = 0, j = 1;
    
    for(int i = 1; i <= num; i++) {
         sum += i;
        
        if (sum >= n) {
            while (sum > n) {
                sum -= j++;
            }
            
            if (sum == n) answer++;
        }
    }
    
    
    return answer;
}