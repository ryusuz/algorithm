//weel11-7 문자열 내림차순으로 배치하기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), greater<int>());
    
    return s;
}