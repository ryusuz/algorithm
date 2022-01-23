// 21.01.23. 소수 찾기
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

set<int> numberSet;

bool checkPrime(int n) {
    if (n == 0 || n == 1) return false;
    
    for(int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    // makeCombination("", numbers);

    // 모든 경우의 수를 구하고, 소수인 애들만 체크?
    int x = 0;
    sort(numbers.begin(), numbers.end());
    
    do {
        for(int i = 1; i < numbers.size() + 1; i++) {
            x = stoi(numbers.substr(0, i));
            if (checkPrime(x)) numberSet.insert(x);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    
    return numberSet.size();
}

/* 재귀 함수 쓰는 법
void makeCombination(string comb, string others) { 
    // 1. 현 조합을 numberSet에 추가한다.
    if (comb != "") numberSet.insert(stoi(comb));
    
    // 2. 현 조합 + others[i]를 조합하여 새로운 조합을 만든다.
    for (int i = 0; i < others.size(); i++) {
        makeCombination(comb + others[i], others.substr(0, i) + others.substr(i + 1));
    }
}
*/