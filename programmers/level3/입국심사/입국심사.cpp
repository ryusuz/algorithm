// 22.03.30. 입국심사 (이분탐색)
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    long long lo = 0;
    long long hi = times.back() * n;
    
    while(lo != hi){
        long long mid = (lo + hi) / 2;
        long long canDoIt = 0;
        
        for(int i = 0; i < times.size(); i++)
            canDoIt += mid / times[i];
        
        if(canDoIt >= n) hi = mid;
        else lo = mid + 1;
    }
    
    return lo;
}