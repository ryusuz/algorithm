# [Level3] 불량 사용자

https://programmers.co.kr/learn/courses/30/lessons/64064

</br>

## ✏️ 풀이 방법
user_id의 길이는 최대 8이니까 재귀함수로 풀어도 오버플로우 안됨!

1. banned_id의 원소를 재귀함수로 돌리면서 user_id에 일치하는 값이 있는지 확인
2. 있으면 visit을 true로 해주고 dfs에 banned_id의 idx + 1 값을 넘겨주고 재귀
3. idx가 banned_id 사이즈랑 같아지면 재귀 종료
4. visit을 돌면서 true인 애들을 res에 누적
5. set에 res 넣음 (set은 중복 제거됨.)


