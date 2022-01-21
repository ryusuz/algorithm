//week11-23 핸드폰 번호 가리기
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int len = phone_number.size();
    
    for (int i = 0; i < len - 4; i++) {
        phone_number[i] = '*';
    }
    
    return phone_number;
}