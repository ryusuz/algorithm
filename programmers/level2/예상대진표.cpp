// 예상대진표
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b) {
        if (a & 1) a++;
        if (b & 1) b++;
        
        a /= 2;
        b /= 2;
        
        answer++;
    }

    return answer;
}