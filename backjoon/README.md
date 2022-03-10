# 💻 백준 문제풀이
<h3> 백준으로 알고리즘 부시기...빠샤ㅑㅑ 👊🏻👊🏻👊🏻</h3>
</br>

## ⭐ 중요한 자료구조
> 1. 배열, 연결 리스트
> 2. 스택, 큐, 디큐
> 3. 힙
> 4. 트리, BST, 그래프
> 5. 해쉬테이블

<br/>

## ✏ Breadth-First Search (BFS; 너비우선탐색)
> 1. 자료구조 **Queue** 사용!! ⭐⭐
</br>

||No.|문제번호|티어|제목|날짜|
|:--:|:---:|:---:|:---:|:---:|:---:|
||1|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/bfs/10709">16173</a>|실버5|점프왕 쩰리|21.09.07.|
||2|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/bfs/16956/">16956</a>|실버4|늑대와 양|21.09.08.|
||3|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/bfs/2589/">2589</a>|골드5|보물섬|21.09.08.|
||4|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/bfs/10709/">10709</a>|실버5|기상캐스터|21.09.09.|

</br>

## ✏ Depth-First Search (DFS; 깊이우선탐색)
> 1. 자료구조 **Stack** 사용!! ⭐⭐ (재귀로 할 수 있으나 스택이 더 빠르고 안전)
> 2. 동작방식은 bfs와 거의 같다
</br>

||No.|문제번호|티어|제목|날짜|
|:---:|:---:|:---:|:---:|:---:|:---:|
||1|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/dfs/1388/">1388</a>|실버4|바닥 장식|21.09.08.|

</br>

## ✏ Dynamic Programming (DP; 동적 계획법)
> 1. 가장 중요한 것은 ⭐**memorization**⭐ !!
> 2. 큰 문제를 작은 문제로 나눌 수 있고, 해답이 무조건 있다는 가정 하에 시행
> 3. 점화식 찾기!
</br>

||No.|문제번호|티어|제목|날짜|
|:---:|:---:|:---:|:---:|:---:|:---:|
||1|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/dp/1010/">1010</a>|실버5|다리 놓기|21.09.09.|
||2|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/dp/9655/">9655</a>|실버5|돌 게임|21.09.09.|
||3|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/dp/9656/">9656</a>|실버5|돌 게임2|21.09.09.|
||4|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/dp/10709/">10709</a>|실버5|기상캐스터|21.09.09.|

</br>

## ✏ Greedy (욕심쟁이)
  > 1. 순간순간이 최선인 선택을 하는(욕심내는) 알고리즘
</br>

||No.|문제번호|티어|제목|날짜|
|:---:|:---:|:---:|:---:|:---:|:---:|
|1|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/greedy/1343/">1010</a>|실버5|폴리오미노|21.09.10.|
|2|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/greedy/1789/">9655</a>|실버5|뒤집기|21.09.10.|

</br>

## ✏ Brute force (브루트포스) ; Exhaustive Search (완전탐색)
> 1. 모든 경우를 직접 하는 알고리즘
> 2. 시간 면에서 매우 비효율적이지만 정확
</br>

||No.|문제번호|티어|제목|날짜|
|:---:|:---:|:---:|:---:|:---:|:---:|
||1|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/brute/1018/">1018</a>|실버5|체스판 다시 칠하기|21.09.13.|
||2|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/brute/1436/">1436</a>|실버5|영화감독 숌|21.09.13.|

</br>

## ✏ Recursion (재귀)

</br>

## ✏ Binary Search (이진탐색)
> 1. 탐색 범위를 절반씩 좁혀가며 탐색하는 알고리즘
> 2. 탐색할 리스트가 ⭐정렬⭐되어 있어야함!!!!
> 3. 변수 3개를 사용해서 탐색 (start, end, mid)
</br>

||No.|문제번호|티어|제목|날짜|
|:---:|:---:|:---:|:---:|:---:|:---:|
||1|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon//brute/1920/">1920</a>|실버4|수 찾기|21.09.16.|
||2|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon/brute/2110/">2110</a>|실버1|공유기 설치|21.09.16.|
</br>

## ✏ Backtracking (백트래킹)

</br>

## ✏ Divide and Conquer (분할 정복)

</br>

## ✏ Shortest Path (최단 경로 - 다익스트라, 벨만-포드, 플로이드-와샬)
> 1. 그래프가 주어졌을 때, 최단 경로를 구하는 알고리즘
> 2. 일반적으로 다익스트라, 벨만-포드, 플로이드-와샬 알고리즘 사용
> 3. 다익스트라는 하나의 정점에서 출발해서 모든 정점을 거쳐 최단 거리를 업데이트 하는 알고리즘
> 4. 플로이드-와샬은 모든 정점에서 출발해서 모든 정점을 거치는 알고리즘! => 다익스트라보다 구현은 쉽지만 시간복잡도가 상대적으로 큼
</br>

||No.|문제번호|티어|제목|날짜|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
||1|<a href="https://github.com/ryusuz/algorithm/tree/master/backjoon//shortest-path/11403/">11403</a>|실버1|경로 찾기|플로이드-와샬|22.03.10.|
</br>
</br>

## ✏ Bit masking (비트마스킹)

</br>

## ✏ Sliding Window (슬라이딩 윈도우)

</br>

## ✏ Two Pointers (투포인터)

