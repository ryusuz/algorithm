// 22.01.20. 점프와 순간이동
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while (n > 0) {
        ans += n%2;
        n /= 2;
    }

    return ans;
}

/*
5/2 = 2
2/2 = 1 => 1+1;
2/2

*/