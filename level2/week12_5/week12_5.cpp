// week12-5 피보나치 수
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> fibo = {0, 1, 1};
    
    for(int i = 3; i <= n; i++) {
        int tmp = fibo[i-1] + fibo[i-2];
        fibo.push_back(tmp % 1234567);
    }
    
    return fibo[n];
}