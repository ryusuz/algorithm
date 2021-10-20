# 핸드폰 번호 가리기 21.10.15.
def solution(phone_number):    
    num = len(phone_number)
    back = phone_number[-4:]
    
    return '*'*(num-4) + back
