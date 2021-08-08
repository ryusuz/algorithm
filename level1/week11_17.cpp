//week11-17 정수 내림차순으로 배치하기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string tmp = to_string(n);
    
    sort(tmp.begin(), tmp.end(), greater<char>());
    answer = stoll(tmp);
    
    return answer;
}