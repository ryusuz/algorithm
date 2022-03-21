# [Level3] 합승 택시 요금

https://programmers.co.kr/learn/courses/30/lessons/72413

</br>

## ✏️ 풀이 방법

플로이드 와샬 사용.

s 출발, a 도착, b 도착이라면

i를 거쳐서 가는 비용들을 계산해서 최소 비용을 리턴

dp[s][i] + dp[i][a] + dp[i][b]


