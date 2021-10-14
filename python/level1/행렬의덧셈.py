# 행렬의 덧셈 21.10.15.

# 행렬 나올 땐 넘파이
import numpy as np
def sumMatrix(A,B):
    A=np.array(A)
    B=np.array(B)
    answer=A+B
    return answer.tolist()

# 베이직한 풀이 => zip 내장함수 사용하기
def sumMatrix(A,B):
    answer = []

    for a, b in zip(A, B):
        l = []
        for x, y in zip(a, b):
            l.append(x + y)
        answer.append(l)

    return answer