#include <iostream>
#include <algorithm>

class Solution {
public:
    struct Info {
        int num;
        int idx;
    };
    
    static bool cmp(Info a, Info b) {
        if (a.num == b.num) return a.idx < b.idx;
        
        return a.num < b.num;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2, 0);
        vector<Info> infos;
        
        for(int i = 0; i < nums.size(); i++) {
            infos.push_back({nums[i], i});
        }
        
        sort(infos.begin(), infos.end(),cmp);
        
        int lo = 0;
        int hi = nums.size() - 1;
        
        for(auto& it : infos) {
            int result = search(infos, target - it.num, ++lo, hi);
            
            if (result == -1) continue;
            
            answer[0] = infos[lo-1].idx;
            answer[1] = result;
        }
        
        return answer;
    }
    
    int search(vector<Info>& infos, int target, int lo, int hi) {        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            
            if (target == infos[mid].num) return infos[mid].idx;
            
            if (target < infos[mid].num) hi = mid - 1;
            else lo = mid + 1;
        }
        
        return -1;
    }
};