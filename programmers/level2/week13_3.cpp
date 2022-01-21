//week13-3 다음 큰 숫자
#include <string>
#include <vector>

using namespace std;

int count_one(int num) {
	int ret = 0;
    
	while (num > 0) {
		if (num % 2 == 1) ret++;
		num >>= 1;
	}
    
	return ret;
}

int solution(int n) {
    int answer = 0;
    int count = count_one(n);
    
    while (1) {
        n++;
        if (count == count_one(n)) return n;
    }
    return answer;
}

////// 10 -> 2진수로 바꾸기
string to_binary(int num) {
	string s = "";
    
	while (num > 0) {
		if (num % 2 == 1) s = "1" + s;
        else s = "0" + s;
		num >>= 1;
	}
    
	return s;
}