# [Level 2] 괄호 회전하기 (월간 코드 챌린지 시즌2)
<h3> ⭐ 괄호 문제는 스택 이용하기 </h3>

- 스택의 **최상단값**을 출력하는 함수
  - C++ : **top()**
  - JAVA : **peek()**
- 스택이 비었는지 확인하는 함수
  - C++ : **empty()**
  - JAVA : **isEmpty()**
- 자바에서 스택 선언할 때 제네릭에 자료형 클래스 명시하기 

</br>

## C++
```c++
#include <stack>

stack<int> st;

st.push(1);
st.top();
st.pop();
st.empty();
st.size();
```

</br>

## JAVA
```java
import java.util.Stack

// 제네릭에 자료형 클래스 타입 명시!! Integer, String, Character, ...
Stack<Integer> st = new Stack<>();
Stack<String> st2 = new Stack<>();
Stack<Character> st3 = new Stack<>();

st.push(1);
st.peek();      // c++과 다름!
st.pop();
st.isEmpty();   // c++과 다름!
st.size();
st.contains(1);
```

</br>

## 📌 문제
> 다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.
>
> - (), [], {} 는 모두 올바른 괄호 문자열입니다.
> - 만약 A가 올바른 괄호 문자열이라면, (A), [A], {A} 도 올바른 괄호 문자열입니다. 예를 들어, [] 가 올바른 괄호 문자열이므로, ([]) 도 올바른 괄호 문자열입니다.
>
> 만약 A, B가 올바른 괄호 문자열이라면, AB 도 올바른 괄호 문자열입니다. 예를 들어, {} 와 ([]) 가 올바른 괄호 문자열이므로, {}([]) 도 올바른 괄호 문자열입니다.
대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어집니다. 이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 칸만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.
</br>

## 📌 제한사항
> - s의 길이는 1 이상 1,000 이하입니다.
</br>

## 📌 입출력 예
|s|result|
|:--:|:--:|
|"[] () {}"|3|
|"}]()[{"|2|
|"[)(]"|0|
|"}}}"|0|

</br>

