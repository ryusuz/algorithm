// 22.02.20. 교점에 별 만들기
#include <string>
#include <vector>
#include <climits>
#include <utility>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    long long minX = LLONG_MAX, maxX = LLONG_MIN;
    long long minY = LLONG_MAX, maxY = LLONG_MIN;
    
    vector<pair<long long, long long>> points;
    int lineSize = line.size();
    
    // 모든 선에 대해 교점 구하기
    for(int i = 0; i < lineSize; i++) {
        for(int j = i + 1; j < lineSize; j++) {
            long long A = line[i][0], B = line[i][1], E = line[i][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];
            
            long long xd = B * F - E * D;
            long long yd = E * C - A * F;
            long long mod = A * D - B * C;
            
            if (mod == 0) continue;                     // 분모 0이면 평행/일치 => 교점x
            
            if (xd % mod || yd % mod) continue;    // 나머지 생김 => 정수가 아니면 x
            
            long long x = xd / mod;
            long long y = yd / mod;

            minX = min(minX, x);
            maxX = max(maxX, x);

            minY = min(minY, y);
            maxY = max(maxY, y);

            points.push_back({x, y});
        }
    }
    
    // . 사각형 만들기
    string row(maxX - minX + 1, '.');
    vector<string> answer(maxY - minY + 1, row);
    
    for(auto& p : points) {
        answer[abs(maxY - p.second)][abs(minX - p.first)] = '*';
    }
    
    return answer;
}