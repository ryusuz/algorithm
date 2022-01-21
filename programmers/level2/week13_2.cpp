// week13-2 땅따먹기
// 동적프로그래밍 => 메모이제이션!!!!!! 중요!!!!!
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for (int i = 1; i < land.size(); i++) {
        land[i][0] += max(max(land[i-1][1], land[i-1][2]), land[i-1][3]);
        land[i][1] += max(max(land[i-1][0], land[i-1][2]), land[i-1][3]);
        land[i][2] += max(max(land[i-1][0], land[i-1][1]), land[i-1][3]);
        land[i][3] += max(max(land[i-1][0], land[i-1][1]), land[i-1][2]);
    }
    
    answer = *max_element(land[land.size() - 1].begin(), land[land.size()-1].end());
    
    return answer;
}