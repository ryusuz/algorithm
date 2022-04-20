# [G3] 경사로

https://www.acmicpc.net/problem/14890

</br>

## ✏️ 풀이 방법

구현 문제.

```
1. 높이차가 1 이하인 애들만 확인하면 됨
2. 1 이하인 애들 중 경사로를 세울 수 있는 애면 answer + 1
3. 연속되는 수가 몇갠지 세어줌
4. '현재'를 기준으로 왼쪽과 오른쪽을 확인
5. 현재보다 높이가 높으면 현재에 경사로를 세워야함.
6. 경사로를 세우려면 현재의 길이가 L 이상이어야함.
```

## ✏️ 시간복잡도 줄이기

애초에 가능하지 않은 애들은 가지치기!!!

<img width="1177" alt="image" src="https://user-images.githubusercontent.com/59083189/164168003-a44a87d0-85d3-4e8d-a01e-baeffed49db4.png">



<br/>
