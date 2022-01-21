// week16-2 위클리 8주차
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    vector<int> c;
    vector<int> r;
    
    for (auto& size : sizes) {
        if (size[0] >= size[1]) {
            c.push_back(size[0]);
            r.push_back(size[1]);
        } else {
            c.push_back(size[1]);
            r.push_back(size[0]);
        }
    }
    
    answer = *max_element(c.begin(), c.end()) * *max_element(r.begin(), r.end());
    
    return answer;
}