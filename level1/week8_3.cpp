//week8-3 두 정수 사이의 합
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if (a == b) return a;
    
    if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    
    while (a <= b) {
        answer += a;
        a++;
    }
    
    return answer;
}