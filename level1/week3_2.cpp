// week3-2 폰켓몬
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int pick = nums.size() / 2;
    
    // sort로 정렬 후, unique로 중복원소를 쓰레기값으로 보내고 쓰레기값 첫번째 자리 리턴, <-여기부터 끝까지 삭제
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    if (pick >= nums.size()) {
        answer = nums.size();
    } else {
        answer = pick;
    } 
    
    
    return answer;
}