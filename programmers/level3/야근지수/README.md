# [Level3] 야근 지수
https://programmers.co.kr/learn/courses/30/lessons/12927
</br></br>

## ✏️ 풀이 방법
야근지수는 각 원소의 제곱값을 더한 값이기 때문에 최댓값을 1씩 줄여주는 것이 좋다.

상대적으로 작은 값을 줄이면 별로 티도 안 남. 제곱이기 때문에 최댓값과 작은 값의 제곱값은 기하급수적으로 차이가 난다.

따라서 ⭐️"최대힙"⭐️을 이용해 힙의 top값에서 1을 빼고 다시 힙에 넣어주는 과정을 n만큼 반복한다.

<br/>

## 💡 배열의 원소 값을 모두 더해주는 함수
```c++
#include <numeric>

int sum = std::accumulate(v.begjin(), v.end(), 0);

long long sum = std::accumulate(v.begin(), v.end(). 0LL);
```
 첫 번째, 두 번째 인자는 first, last iterator가 들어가고, 세 번째 인자는 합의 초기값을 넣어준다.
 
 <br/>
 
⭐️ 주의!!

합이 커서 long long 타입으로 받아야할 때는 초기값을 0LL(long long의 리터럴 접미사 == ll)으로 설정해주어야함

0으로 설정하면 오버플로우 발생 => 함수의 반환값이 초기 값의 타입(0을 대입한다면 int)을 따라가기 때문!
 
