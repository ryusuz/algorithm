// week16-4 skt 대비 문제 풀이 1번
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(string S) {
	// S에서 홀수개인 문자는 지우고, 지워야할 문자 개수 리턴
	// ex. S='acbcbba' => a:2, b:3, c:2 => b 지워야하니까 return 1
	// ex2. S='axxaxa' => a:3, x:3 => a, x 지워야하니까 return 2
	// ex3. S='aaaa' => a:4 => 지울거 없으니까 return 0
	// N = 200,000 S = a~z

	unordered_map<char, int> m;
	int answer = 0;

	for (auto& c : S) {
		m[c]++;
	}

	for (auto& elem : m) {
		int num = elem.second;
		// num & 1이 1이면 홀수, 아니면 짝수
		// if는 0이 아니면 다 참
		if (num & 1) answer++;
	}

	return answer;

}