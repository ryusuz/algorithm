// 22.03.20. 다단계 칫솔 판매
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

struct Person {
    string parents;
    int money;
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    map<string, Person> m;
    
    for(int i = 0; i < enroll.size(); i++) {
        Person p = {referral[i], 0};
        m[enroll[i]] = p;
    }
    
    for(int i = 0; i < seller.size(); i++) {
        string me = seller[i];
        string parents = m[me].parents;
        
        int money = amount[i] * 100;
        int give = money / 10;
        
        m[me].money += money - give;
                
        while(me != "-" && give != 0) {
            me = parents;
            parents = m[me].parents;
            
            money = give;
            give = (me == "-") ? 0 : money / 10;
            
            m[me].money += money - give;
        }
    }
    
    for(int i = 0; i < enroll.size(); i++) {
        answer.emplace_back(m[enroll[i]].money);
    }
    
    return answer;
}