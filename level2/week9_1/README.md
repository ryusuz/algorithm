## 새로 배우게 된 내용들 ✏📚

### 1. istringstream
- 문자열을 공백으로 스플릿할 때 유용하게 쓸 수 있다.
- **sstream** 헤더에 포함.

```c++
#include <sstream>
```

```c++
string str = "프로그래머스 문제 풀이";
string tmp[3];
    
istringstream ss(str);
ss >> tmp[0] >> tmp[1] >> tmp[2];
// tmp[0]에는 '프로그래머스', tmp[1]에는 '문제', tmp[2]에는 '풀이'가 들어간다.
```

</br>

### 2. auto
- 초기화값에 따라서 자동으로 데이터타입을 정해주는 키워드.
- 타입추론이라고도 한다.

```c++
auto a = 10                 // a는 int
auto b = "프로그래머스"     // b는 string
```

```c++
// 벡터 순회
vector<int> v = {1, 2, 3, 4};

for(auto it = v.begin(); it != v.end(); it++) {
    *it = 3;
}
```

```c++
// for each문, auto&을 사용해서 벡터 순회
vector<int> v = {1, 2, 3, 4};

for(auto& elem : v) {
    elem = 3;
}
```

</br>

### 3. lower_bound와 upper_bound
- 이진탐색으로 원소를 탐색하는 함수들
- **algorithm** 헤더에 포함.
- 매개변수는 (탐색 시작 위치, 탐색 종료 위치, 기준이 될 숫자)
- **리턴타입이 iterator**이므로 실제 인덱스 위치를 알고 싶다면 시작 위치를 빼줘야 한다.
- ⭐ 오름차순으로 정렬되어 있어야 한다

#### 1) lower_bound
- 찾으려는 key값과 같거나 큰 숫자가 몇 번째에 처음 나오는 지

```c++
#include <algorithm>
```

```c++
vector<int> v = {1, 2, 3, 4, 5, 6};
auto it = lower_bound(v.begin(), v.end(), 3);     // iterator를 리턴하기 때문에 타입을 auto로 해줌
cout << "인덱스: " << it - v.begin() << endl;     // 인덱스: 2      
// 3과 같거나 큰 숫자의 인덱스이기 때문에 원소 '3'의 인덱스인 2가 출력된다.
```

#### 2) upper_bound
- 찾으려는 key값을 초과하는 숫자가 몇 번째에 처음 나오는 지

```c++
vector<int> v = {1, 2, 3, 4, 5, 6};
auto it = upper_bound(v.begin(), v.end(), 3);
cout << "인덱스: " << it - v.begin() << endl;   // 인덱스: 3
// 3을 초과하는 숫자의 인덱스이므로 원소 '4'의 인덱스인 3이 출력된다.
```
