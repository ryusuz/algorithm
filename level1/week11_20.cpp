//week11-20 콜라츠 추측
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long number = num;
    
    while (number != 1) {
        if (answer >= 500) return -1;
        
        number = (number & 1) ? (number * 3 + 1) : (number / 2);
        answer++;
    }
    
    return answer;
}
