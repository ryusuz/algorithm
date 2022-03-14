# [Level3] 디스크 컨트롤러

https://programmers.co.kr/learn/courses/30/lessons/64062

</br>

## ✏️ 풀이 방법
우선순위 큐를 사용

<br/>

## 💡 우선순위 큐를 선언하는 또다른 방식
* 내가 기존에 했던 방식
  * priority_queue<pair<int, int>> pq;

* 다른 방식
  * priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
  * 첫 번째 인자에는 pq에 들어갈 데이터 형식
  * 두 번째 인자에는 데이터를 넣을 큰 틀?의 형식
  * 세 번째 인자는 정렬을 위해 cmp 구조체를 만들고 그 안에 비교함수 오버라이딩 (아래 코드 참고)

```c++
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};
```
