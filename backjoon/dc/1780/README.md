# [S2] 종이의 개수

https://www.acmicpc.net/problem/1780

</br>

## ✏️ 풀이 방법
분할정복 + 재귀!

처음엔 bfs로 풀었는데 확인했던 곳을 또 확인하는 바람에 시간 초과 발생!

1. 값이 같은지 확인
2. 다르면 9개로 분할 해줌 그리고 분할한 범위들 모두 재귀적으로 1인지 확인
3. 같으면 해당 값++ 해주고 다음 범위 확인

<br/>

