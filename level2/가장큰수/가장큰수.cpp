#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    
    for (auto& s : numbers) {
        nums.push_back(to_string(s));
    }
    
    sort(nums.begin(), nums.end(), cmp);
    
    if (nums[0] == "0") return "0";
    
    for(auto& s : nums) {
        answer += s;
    }
    
    return answer;
}