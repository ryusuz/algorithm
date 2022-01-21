// week16-3 타겟 넘버
#include <string>
#include <vector>

using namespace std;

int answer;

void dfs(vector<int> nums, int target, int sum, int idx) {
    if (idx == nums.size()) {
        if (sum == target) answer++;
        return;
    }
    
    dfs(nums, target, sum+nums[idx], idx+1);
    dfs(nums, target, sum-nums[idx], idx+1);
}

int solution(vector<int> numbers, int target) {    
    dfs(numbers, target, 0, 0);
    return answer;
}