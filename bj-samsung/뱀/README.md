# [G5] 뱀

https://www.acmicpc.net/problem/3190

</br>

## ✏️ 풀이 방법
1. 입력값대로 보드를 만들어준다.
2. 사과 위치를 보드에 넣어준다.
3. 뱀을 큐로 구현. head를 계속 넣어준다.
4. 다음 위치가 사과가 아니면 pop 해주고 tail을 큐의 front 값으로 바꿔준다.
5. 회전은 changeDir 함수 만들어서 바꿔주었다.
