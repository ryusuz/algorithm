// 22. 02. 08. k진수에서 소수 개수 구하기수
// 22. 02. 08. k진수에서 소수 개수 구하기수
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(long long n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
        
    // 진수 변환
    string tmp = "";
    while (n > 0) {
        int res = n % k;
        n /= k;
        tmp += to_string(res);
    }
    
    string num = "";
    for(int i = tmp.size()-1; i >= 0; i--) {
        num += tmp[i];
    }
        
    // 1. 0 찾기b => 인덱스 저장?
    // 2. 앞, 뒤에 숫자 있으면 판별 => 뒤에 0 있는지 확인
    string check = "";
    for(int i = 0; i < num.size(); i++) {
        if (num[i] != '0') {
            check += num[i];
        }
        
        if (num[i] == '0' || i == num.size()-1) {
            if (i == 0 || check == "1" || check == "") {
                check.clear();
                continue;
            }
            
            //if (primes[stoll(check)] != 0) answer++;
            if (isPrime(stoll(check))) answer++;
            check.clear();
        }
    }
    
    
    return answer;
}