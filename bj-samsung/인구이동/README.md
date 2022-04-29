# [G5] 인구 이동

https://www.acmicpc.net/problem/16234

</br>

## ✏️ 풀이 방법
1. bfs를 이용해서 연합할 수 있는 국가들 탐색 (좌표를 벡터에 저장해줌)
    1. 연합 가능 국가가 1개면 return 0;
    2. 여러 개면 벡터 돌면서 해당 국가들 인구 이동
2. bfs 리턴값의 합이 0이면 국경 열기 불가능이므로 무한반복문 멈춤
3. 0이 아니면 위의 과정 반복

</br>

![image](https://user-images.githubusercontent.com/59083189/165894869-63eb8e00-fbbf-4d8a-aa4c-578277dd9b1d.png)

<br/>
