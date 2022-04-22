# [G4] 드래곤커브

https://www.acmicpc.net/problem/15685

</br>

## ✏️ 풀이 방법
1. 입력으로 주어지는 드래곤 커브를 순회한다.
2. 0세대인 직선을 만들어준다.
3. 커브 함수를 통해 재귀적으로 드래곤커브를 만들어준다.
    1. 직선의 좌표들을 벡터로 넘겨준다.
    2. 벡터를 역순회하면서 직선을 시계방향으로 회전하고 그 값을 벡터에 추가해준다.

</br>

## 회전 방법
```c++
Point rotate(Point p) {
    int y = p.x;
    int x = -p.y;

    return {y, x};
}
```
<br/>

## 드래곤 커브 만들기
```c++
void curve(int cnt, int gen, vector<Point> &points) {
    if (cnt == gen) return;                     // 카운트와 드래곤커버 세대 같아지면 끝내기
    
    Point end = points[points.size() - 1];      // 마지막 점을 기준으로 회전하기 때문에 마지막 점 저장
    Point endr = rotate(end);                   // 시계방향으로 마지막 점을 회전함

    int ydiff = end.y - endr.y;                 // 회전하면 좌표값이 달라지기 때문에 원래 마지막 점의 좌표 값과 빼서 나머지 회전 좌표값들에 더해줄거임
    int xdiff = end.x - endr.x;

    // 드래곤 커브 만들기
    for(int i = points.size() - 2; i >= 0; i--) {   // 마지막 점을 제외하기 위해 사이즈 -2 (마지막점도  포함하면 벡터에 좌표 중복)
        Point pr = rotate(points[i]);               // 점들 회전
        pr = {pr.y + ydiff, pr.x + xdiff};          // 위에서 구한 차이를 더해줘서 좌표를 설정해줌

        if (!check(pr.y, pr.x)) return;             // 좌표가 넘어가면 리턴

        points.push_back(pr);                       // 회전한 좌표값 벡터에 넣어줌
        board[pr.y][pr.x] = 1;                      // 값을 1로 변경함으로서 드래곤커브임을 체크
    }

    curve(cnt + 1, gen, points);                    // 재귀
}
```