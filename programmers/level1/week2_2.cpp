// week2-2 3진법 뒤집기
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int q = n;                                   //몫
    int rest = 0;
    vector<int> three_num;                       //나머지 = 3진법 반전 숫자배열
    
    while (!q == 0) {
        rest = q % 3;
        q = q / 3;
        
        three_num.push_back(rest);               // 45 -> 0021
    }
    
    int square = 1;
    while (!three_num.empty()) {
        answer += three_num.back() * square;
        square *= 3;
        
        three_num.pop_back();
    }
    
    return answer;
}