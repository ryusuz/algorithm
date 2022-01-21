//week8-6 2016년
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> monthDay = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 금요일을 기준으로..
    // 1월 31일은 뮤슨 요일? = > +30
    // 30 % 7 = 2 ==> 일요일
    // 2월 28일은 무슨 요일? => 31+27일 = 58일
    // 58 % 7 = 2 ==> 일요일?
    // 5월 24일은 ? =>
    
    int day = 0;
    for (int i = 0; i < a; i++) {
        day += monthDay[i];
    }
    
    day += b - 1;
    day %= 7;
    
    
    return days[day];
}
