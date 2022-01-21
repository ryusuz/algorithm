## 새로 배우게 된 내용들 ✏📚

### 1. sort()
- 퀵 정렬 함수 (default: 오름차순)
- **algorithm** 헤더에 포함
- 내림차순 혹은 임의 정의한 대로 정렬 가능하다
- 리턴값 X

```c++
#include <algorithm>
```

```c++
vector<int> v = {3, 1, 5, 2, 4};

sort(v.begin(), v.end());   // less<int>()
```

```c++
// 내림차순
sort(v.begin(), v.end(), greater<int>());
```

```c++
// 임의 정의
bool compare(string a, string b) {
    return a > b;
}
```

```c++
sort(v.begin(), v.end(), compare);
```

- ⭐ compare()가 아닌 compare를 넣어줄 것
- 위에서 정의된 compare 함수는 a > b, 왼쪽이 더 클 수 있도록 정렬, 즉 내림차순 정렬을 한다
