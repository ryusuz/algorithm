# [G1] 구슬 탈출 2

https://www.acmicpc.net/problem/13460

</br>

## ✏️ 풀이 방법
bfs를 이용해서 구현해야하는 문제.

<br/>

* 고려해야할 점
  * 빨간 공이 움직이지 않아도 파란 공은 움직이므로 횟수를 체크해줘야한다. >> 빨간 공 바로 옆이 벽이거나 제자리이면 continue 해서 틀림
  * 파란 공이 빠지면 다른 경우의 수도 생각해줘야한다. >> 파란 공 빠지면 바로 -1을 해버려서 틀림
  * 파란 공 때문에 빨간 공이 왔던 길을 되돌아 갈 수도 있다. >> 방문한 곳이면 continue 해서 틀림

</br>

* 히든 케이스
```
7 6
######
######
####.#
#.R#.#
#.#.##
#O.B.#
######

answer: 3
```

```
6 7
#######
##.##.#
#.B.#.#
#O..R##
#.#...#
#######

answer: 1
```

```
4 6
######
#..###
#OBR##
######

answer: 2
```

