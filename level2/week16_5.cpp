// week16-5 skt 대비 문제 풀이 2번
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int solution(int N) {
	/*
	주어진 10진수 N에서 5를 하나 지웠을 때 나올 수 있는 가장 큰 수 (무조건 1개 이상 5 있음)
	ex1: N = 15958 => return 1958
	ex2: N = -5859 => return -589
	ex3: N = -5000 => return 0
	ex4: N = 5123 => 123
	ex5: N = 12'5'650 => 12650 or 12560
	ex6: N = 1254'5'0 => 12450 or 12540
	ex7: N = -1256'5' => -1265 or -1256
	ex8: N = -12'5'45 => -1245 or -1254
	N = -999995 ~ 999995 (최소 두자리수)
	*/
	
	/*
	양수 => 최초에 나온 5랑 그다음 인덱스 값을 비교해서 다음께 크면 바로 지우기
	다음께 작으면 다음 5를 찾아서 반복

	음수 => 반대로 최초에 나온 5랑 다음 인덱스 값 비교해서 다음께 작으면 바로 지우기
	다음께 크면 다음 5를 찾아서 비교 반복
	==> 음수면 앞에 -가 있으니까 예외 처리!
	*/
	
	string n = to_string(N);

	int idx = 0;
	if (N >= 0) {
		for (int i = 0; i < n.size(); i++) {
			if (n[i] == '5') {
				idx = i;

				if (idx == n.size() - 1) break;
				
				if (n[i + 1] >= '5') break;
			}
		}
	}
	else {
		for (int i = 1; i < n.size(); i++) {
			if (n[i] == '5') {
				idx = i;

				if (idx == n.size() - 1) break;

				if (n[i + 1] <= '5') break;
			}
		}
	}

	n.erase(n.begin() + idx);

	return stoi(n);
}