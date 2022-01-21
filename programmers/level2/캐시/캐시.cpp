// 21.12.08 캐시
#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    
    for(int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        
        // 모든 문자를 소문자로 변경
        for(int j = 0; j < city.size(); j++) {
            if (isupper(city[j])) city[j] = tolower(city[j]);
        }
        
        // 캐시에 있는지 확인 있으면 hit, 없으면 miss
        bool hit = false;
        int idx;
        for(idx = 0; idx < cache.size(); idx++) {
            if (cache[idx] == city) {
                hit = true;
                break;
            }
        }
        
        cache.push_back(city);
        
        if (hit) {
            answer++;
            cache.erase(cache.begin() + idx);
        } else {
            if (cache.size() > cacheSize) {
                cache.pop_front();
            }
            answer += 5;
            
        }
        
    }
    return answer;
}