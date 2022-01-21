//week12 N개의 최소공배수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    for(int i = 0; i < arr.size() - 1; i++) {
        arr[i+1] = arr[i] * arr[i+1] / __gcd(arr[i], arr[i+1]);
    }
    
    return arr[arr.size() - 1];
}