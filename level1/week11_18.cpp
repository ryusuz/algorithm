//week11-18 짝수와 홀수
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    return num % 2 == 0 ? "Even" : "Odd";
}

//////
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";

    return num & 1 ? "Odd" : "Even";    // 홀수를 비트로 바꾸면 1의 자리에 무조건 1이 있음 => 1이랑 and연산하면 홀수면 1 짝수면 0
}