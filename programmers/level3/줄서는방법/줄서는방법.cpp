#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    long long fac[21] = {1};
    vector<int> num;
    
    for(int i = 1; i <= 20; i++) {
        fac[i] = fac[i-1] * i;
        num.push_back(i);
    }
    
    int order = 0;
    long long start = 0, end = 0;
    k--;
    
    for(int i = 1; i <=n; i++) {
        order = (k - start) / fac[n-i];
        start = start + fac[n-i] * order;
        end = start + fac[n-i] - 1;
        
        answer.push_back(num[order]);
        num.erase(num.begin() + order);
    }
     
    return answer;
}