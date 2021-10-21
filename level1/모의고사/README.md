## 새로 배우게 된 내용들 ✏📚

### 1. max_element(), min_element()
- iterator 사용이 가능하다 (리턴 값 iterator)
- **algorithm** 헤더에 포함

```c++
#include <algorithm>
```

```c++
vector<int> v = {1, 4, 2, 6, 3, 9, 0};

int max_num = *max_element(v.begin(), v.end());               // max_num = 9
int max_idx = max_element(v.begin(), v.end()) - v.begin();    // max_idx = 5

int min_num = *min_element(v.begin(), v.end());               // min_num = 0;
int min_idx = min_element(v.begin(), v.end()) - v.begin();    // min_idx = 6
```
