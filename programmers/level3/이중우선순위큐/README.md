# [Level3] 이중 우선순위 큐

https://programmers.co.kr/learn/courses/30/lessons/42628

</br>

## ✏️ 풀이 방법
1. 우선순위 큐 2개 생성 (최대 힙  하나, 최소 힙 하나)
2. 데이터 삽입 명령어면 put++, 최대 힙과 최소 힙에 데이터를 넣어준다.
3. 데이터 삭제 명령이면 del++, 최댓값 삭제면 최대힙에서 pop, 최솟값 삭제면 최소힙에서 pop
4. 삭제 명령 시, put == del이면 큐가 비어있다는 뜻이므로 pop하지 않는다.
5. put == del이면 최대 힙과 최소 힙 모두 비워준다. (실제로는 값이 있기 때문)
6. 위 과정을 operations 크기만큼 반복.
7. 반복이 끝나고 put == del 이라면 {0, 0}을 리턴, 아니라면 {최대 힙의 top, 최소 힙의 top}을 리턴한다.

```
입력: ["I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"]

1. "I 4", "I 3", "I 2", "I 1"
max_pq = {4, 3, 2, 1} 
min_pq = {1, 2, 3, 4}
put = 4, del = 0

2. "D 1", "D 1", "D -1", "D -1"
max_pq = {2, 1};
min_pq = {3, 4};
put = 4, del = 4    // put == del 이므로 삽입한 데이터는 모두 삭제했다. 둘다 비워주기

3. "I 5", "I 6"
max_pq = {6, 5};
min_pq = {5, 6};

4. return {6, 5}    // {max_pq.top(), min_pq.top()}

```

<br/>

