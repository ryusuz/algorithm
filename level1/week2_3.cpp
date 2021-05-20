// week2-3 키패드 누르기 
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int cal_dist(int num1, int num2);

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;          // * 왼손 시작 지점
    int right = 12;         // # 오른손 시작 지점
    
    // left = 1, 4, 7, *(10) 은 left % 3 == 1인 애들
    // right = 3, 6, 9, #(12)은 right %3 == 0인 애들
    // middle = 2, 5, 8, 11(0)은 middle % 3 == 2인애들
    for(int num : numbers) {   
        if (num == 0) num = 11;

        if (num % 3 == 1) {                 // 1, 4, 7, 10(*)
            answer += "L";
            left = num;
        } else if (num % 3 == 0) {          // 3, 6, 9, 12(#)
            answer += "R";
            right = num;
        } else {                            // 2, 5, 8, 11(0)
            
            int dist_l = cal_dist(num, left);
            int dist_r = cal_dist(num, right);
            
            if (dist_l < dist_r) {
                answer += "L";
                left = num;
            } else if (dist_l > dist_r) {
                answer += "R";
                right = num;
            } else {
                if (hand == "left") {
                    answer += "L";
                    left = num;
                } else {
                    answer += "R";
                    right = num;
                }
            }
        }
    }
    
    return answer;
}

// 1, 3 차이는 +1
// 2, 4, 6 차이는 +2
// 5, 7, 9 차이는 +3
// 8, 10 차이는 +4

int cal_dist(int num1, int num2) {
    int dist = 0;
    int cal = abs(num1 - num2);       // num1과 num2의 차의 절대값
    
    if (cal == 1 || cal == 3) {
        dist = 1;
    } else if (cal == 2 || cal == 4 || cal == 6) {
        dist = 2;
    } else if (cal == 5 || cal == 7 || cal == 9) {
        dist = 3;
    } else if (cal == 8 || cal == 10) {
        dist = 4;
    }
    
    return dist;
}
