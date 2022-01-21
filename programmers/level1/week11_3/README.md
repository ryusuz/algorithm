## 새로 배우게 된 내용들 ✏📚

### 1. unique()
- 중복된 원소들을 뒤로 보내는 함수
- ⭐ 중복된 원소들이 연속되어 있어야 한다
- 리턴값은 iterator, 벡터의 쓰레기 값의 첫 번째 위치
- **algorithm** 헤더에 포함

```c++
#include <algorithm>
```

```c++
vector<int> v = { 1, 1, 1, 3, 3, 2, 2, 2};

auto it = unique(v.begin(), v.end());

// 뒤로 보낸 쓰레기 값들 제거하기
v.erase(it, v.end());

// 코드 한 줄로 작성
v.erase(unique(v.begin(), v.end()), v.end());
```
