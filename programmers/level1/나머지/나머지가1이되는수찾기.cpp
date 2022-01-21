// 21.10.22.
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int i = 0;
    while(1) {
        if (n % ++i == 1) break;
    }
    
    return i;
}