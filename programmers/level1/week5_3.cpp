//week5-3 제일 작은 수 제거하기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int idx = min_element(arr.begin(), arr.end()) - arr.begin();
    arr.erase(arr.begin() + idx);
    
    if (arr.empty()) arr.push_back(-1);
    
    return arr;
}