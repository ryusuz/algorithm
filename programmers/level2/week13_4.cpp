// week13-4 조이스틱
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    // 알파벳 26개 A~M, N~Z
    //a b c d e f g h i j k l m(12)    n(13)   o(14,12) p q r s t u v w x y z
    int answer = 0;
    
    for (char alpha : name) {
        //cout << alpha - 'A' << " " << 'Z' - alpha + 1 << endl;
        if (alpha - 'A' >= 13) {
            
        } else {
            
        }
    }
    
    
    return answer;
}