# [Level3] 줄 서는 방법

https://programmers.co.kr/learn/courses/30/lessons/64064

</br>

## ✏️ 풀이 방법
1. DP를 이용해서 1부터 20까지의 팩토리얼을 구한다 (fac)
2. 새로운 배열에 1부터 20까지 차례대로 넣어준다. (nums)
3. 첫번째 자리가 start부터 end까지 중 몇 번째에 있는지 구한다. (order)
4. start와 end를 갱신.
5. nums[order]값을 answer에 넣어주고 nums[order]를 삭제한다.
6. 3~5을 n번 반복
<br/>

```c++
for(int i = 1; i <=n; i++) {
    order = (k - start) / fac[n-i];
    start = start + fac[n-i] * order;
    end = start + fac[n-i] - 1;

    answer.push_back(num[order]);
    num.erase(num.begin() + order);
}
```

```
num = [ 1 2 3 4 5 ]
k = 30

start = 0, end = 0
나는 0번째부터 시작하기 때문에 k에서 1을 빼주었다. == 29번째 값 찾기!

1. 첫번째 자리 ==> (n-1)! == 24개
    order = (29 - 0) / 24 = 1
    start = 0 + (24 * 1) = 24
    end = 24 + 24 - 1 = 47
    answer.push_back(num[1]);
    ==> answer = [2]
    ==> num = [ 1 3 4 5 ]
    
2. 두번째 자리 ==> (n-2)! == 6개
    order = (29 - 24) / 6 = 0
    start = 24 + (6 * 0) = 24
    end = 24 + 6 - 1 = 29
    answer.push_back(num[0]);
    ==> answer = [2 1]
    ==> num = [ 3 4 5 ]
    
3. 세번째 자리 ==> (n-3)! == 2개
    order = (29 - 24) / 2 = 2
    start = 24 + (2 * 2) = 28
    end = 28 + 2 - 1 = 29
    answer.push_back(num[2]);
    ==> answer = [2 1 5]
    ==> num = [ 3 4 ]
    
4. 네번째 자리 ==> (n-4)! == 1개
    order = (29 - 28) / 1 = 1
    start = 28 + (1 * 1) = 29
    end = 29 + 1 - 1 = 29
    answer.push_back(num[1]);
    ==> answer = [2 1 5 4]
    ==> num = [ 3 ]
    
5. 다섯번째 자리 ==> (n-5)! == 1개
    order = (29 - 29) / 1 = 0
    start = 29 + (29 * 0) = 29
    end = 29 + 0 - 1 = 28
    answer.push_back(num[0]);
    ==> answer = [2 1 5 4 3]
    ==> num = [ ]
    
answer = [2 1 5 4 3]

```

![image](https://user-images.githubusercontent.com/59083189/158736574-22cc989e-08b7-4e5a-873c-9bab1b3b29d9.png)


