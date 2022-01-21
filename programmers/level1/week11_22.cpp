//week11-22 하샤드 수
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    int sum = 0, tmp = x;
    
    while (tmp != 0) {
        sum += tmp % 10;
        tmp /= 10;
    }
        
    return (x % sum == 0) ? true : false;
}