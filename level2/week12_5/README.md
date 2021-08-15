## 새로 배우게 된 내용들 ✏📚

### 1. 피보나치 수를 구하는 3가지 방법!😶
1. 재귀 O(2^n)
2. 동적 프로그래밍 O(n^2)
3. 반복 O(n)

- 재귀와 동적은 연속 함수를 호출하는 방식으로 stack overflow가 날 확률이 높고, 데이터의 크기가 기하급수적으로 커진다
- 실행시간은 재귀 > 동적 > 반복
- 가장 안전하고 빠른 방법은 ⭐**반복**으로 구하는 것!
<br/>

#### 1) 재귀
```c++
int fibo_recursion(int n) {
  if (n == 0) return 0;
  else if (n == 1) return 1;
  
  return fibo(n-1) + fibo(n-2);
}
```
<br/>

#### 2) 동적 프로그래밍
```c++
double fibo_dynamic(int n) {
  if (fibo[n] != -1) return fibo[n];                   // 초기화 되어있는 배열 fibo
  
  fibo[n] = fibo_dynamic(n-1) + fibo_dynamic(n-2);
  return fibo[n];
}
```
<br/>

#### 3) 반복
```c++
double fibo_while(int n) {
  for (int i = 2; i <= n; i++) {
    fibo[n] = fibo[n-1] + fibo[n-2]; 
  }
  
  return fibo[n];
}
```
<br/>

### 2. 모듈러 연산
- 계산 결과가 항상 0 - (m-1) 범위에있는 경우 모듈러 연산 사용
- 이때 m은 %를 하고자 하는 modular 값
- m이 음수 일 때는, 양수로 바꿔서 mod 하고 +m을 해주면 된다 (ex. -20 mod 11 == 20 => 20 mod 11 = 9, -9 + 11 = 2)
<br/>

#### 1) 모듈러 합동
- **(a mod n) = (b mod n)  ->  a ≡ b(mod n)**
- 어떤 값 A와 B가 n으로 나누었을 때 나머지가 같다면 A와 B는 모듈 C에 대한 합동 관계라고 한다
- 그러한 A와 B는 A - B를 하였을 때 k*n과 같다
- 즉, A - B = kn으로 나타낼 수 있다
<br/>

#### 2) 모듈러 연산의 속성
1. (a + b) mod n = ((a mod n) + (b mod n)) mod n
2. (a - b) mod n = ((a mod n) - (b mod n)) mod n
<br/>

출처: https://www.crocus.co.kr/1231 [Crocus]
