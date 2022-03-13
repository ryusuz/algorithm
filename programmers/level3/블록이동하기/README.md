# [Level3] 블록 이동하기

https://programmers.co.kr/learn/courses/30/lessons/60063

</br>

## ✏️ 풀이 방법
BFS를 사용한 복잡한 구현 문제이다.

로봇의 위치를 구조체로 만들어서 BFS

방향은 상하좌우, 회전 4개 총 8가지이다.

<br/>

## 💡 직접 정의한 구조체를 해쉬에 넣으려면
해쉬(맵)에 넣으려면 정렬이 필요하다.

직접 정의한 구조체에 '<' 연산자를 오버라이딩해서 재정의해주어야 한다.

```c++
struct Point {
    int y1;
    int x1;
    int y2;
    int x2;
    
    bool operator < (const Point &var) const {
        if (y1 != var.y1) return y1 < var.y1;
        if (x1 != var.x1) return x1 < var.x1;
        if (y2 != var.y2) return y2 < var.y2;
        if (x2 != var.x2) return x2 < var.x2;
    }
};

```
