//week11-19 최대공약수와 최소공배수
#include <string>
#include <vector>
#include <iostream>

using namespace std;
    int i = 0;

int calGCD(int a, int b) {
    if (a % b == 0) return b;
    return calGCD(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if (n > m) answer.push_back(calGCD(n, m));
    else if (n < m) answer.push_back(calGCD(m, n));
    
    answer.push_back(n * m / answer.back());
    
    
    return answer;
}

/*
최대공약수 => 유클리드 호제법.
최소공배수 => 두 숫자의 곱 / 최대공약수
*/