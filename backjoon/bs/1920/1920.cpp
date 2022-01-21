// 1920 수 찾기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num1;
vector<int> num2;

void input();

int bs(int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (num1[mid] == target) {
			return 1;
		}
		else if (num1[mid] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	 
	return 0;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	input();

	for (int i = 0; i < M; i++) {
		//cout << bs(num2[i], 0, N - 1) << endl;
		printf("%d \n", bs(num2[i], 0, N - 1));
	}

	return 0;
}

void input() {
	//cin >> N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int n;
		//cin >> n;
		scanf("%d", &n);
		num1.push_back(n);
	}
	sort(num1.begin(), num1.end());

	//cin >> M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int n;
		//cin >> n;
		scanf("%d", &n);
		num2.push_back(n);
	}
}

/* 재귀 함수로 구현한 이진 탐색
def binary_search(array, target, start, end):
if start > end:
return None
mid = (start + end) // 2

# 원하는 값 찾은 경우 인덱스 반환
if array[mid] == target:
return mid
# 원하는 값이 중간점의 값보다 작은 경우 왼쪽 부분(절반의 왼쪽 부분) 확인
elif array[mid] > target:
return binary_search(array, target, start, mid - 1)
# 원하는 값이 중간점의 값보다 큰 경우 오른쪽 부분(절반의 오른쪽 부분) 확인
else:
return binary_search(array, target, mid + 1, end)
*/