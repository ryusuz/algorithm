# [Level3] 다단계 칫솔 판매

https://programmers.co.kr/learn/courses/30/lessons/60062

</br>

## ✏️ 풀이 방법
1. 구조체 Person을 만들어서 사용했다. 각 구조체에는 부모와 돈이 들어간다!

```c++
struct Person {
    string parents;
    int money;
};
```

</br>

2. enroll을 돌면서 맵에 Person을 넣어 초기화 해주었다.

```c++
map<string, Person> m;
    
    for(int i = 0; i < enroll.size(); i++) {
        Person p = {referral[i], 0};
        m[enroll[i]] = p;
    }
};
```

</br>

3. seller를 돌면서 m[me]의 부모를 타고 올라가면서 돈을 누적 계산해주었다.

```c++
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
```

</br>

4. 계산한 값들을 answer에 넣어주면 끝!
```c++
for(int i = 0; i < enroll.size(); i++) {
        answer.emplace_back(m[enroll[i]].money);
    }
    
return answer;
```

</br>

## 💡 시간 초과 해결 방법
테스트 케이스 13개 중에 11~13번이 시간 초과가 났다.

이유는 seller의 값이 100,000인데 while을 돌기 때문

give가 0이면 더이상 부모로 올라가지 않아도 되므로 while 종료값에 give == 0 을 추가해주었다.



