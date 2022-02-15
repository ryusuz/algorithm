// 22.02.15. 2개 이하로 다른 비트s
#include <string>
#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto num : numbers) {
        if (num % 2 == 0) answer.push_back(num+1);
        else {
            // 1. 0 최하위비트 찾기 (ex. 1001)
            long long lastzero = (num+1)&(-num); // 1010 & 0110 == 0010
            
            // 2. 0 최하위비트를 1로 바꾸기, 그 다음 비트인 1을 0으로 바꾸기 (중간결과)
            long long changezero = (num | lastzero); // 1001 | 0010 == 1010
            
            // 3. 1로 바꾼 비트의 다음 비트인 1 위치
            long long next =  (lastzero >> 1); // 0010 >> 1 == 0001
            
            // 4. 2랑 ~3 값을 and연산해서 1을 0으로 바꾸기(나머지 비트는 유지)
            answer.push_back(changezero & ~next);
        }
    }
    
    
    return answer;
}