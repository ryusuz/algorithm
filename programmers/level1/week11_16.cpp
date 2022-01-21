//week11-16 정수 제곱근 판별
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
        
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) answer = i;
    }    
    
    return pow(answer, 2) == n ? pow(answer + 1, 2) : -1;
}

////////////////
#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);

    return powl(answer, 2) == n ? powl(answer + 1, 2) : -1;
}