//week11-24 x만큼 간격이 있는 n개의 숫자
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long tmp = 0;
    
    for (int i = 0; i < n; i++) {
        tmp += x;
        answer.push_back(tmp);
    }
    
    return answer;
}