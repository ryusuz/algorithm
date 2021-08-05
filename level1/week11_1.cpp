// week11-1 1주차
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    do {
        answer += price * count--;
    } while (count > 0);
    
    if (answer > money) return answer - money;

    return 0;
}