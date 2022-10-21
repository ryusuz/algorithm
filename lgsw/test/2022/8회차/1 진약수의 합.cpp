// 주어진 코드
#include <iostream>
using namespace std;
#define MAXN ((int)1e5)

int A, B;
int sum[MAXN + 10];

void Solve(){
	int i, k;
	for (i = A; i <= B; i++){
		sum[i] = 0;
		for (k = 1; k <= i; k++){
			if (i%k != 0) continue;
			sum[i] += k;
		}
	}
}

void InputData(){
	cin >> A >> B;
}

void OutputData(){
	int i;
	for (i = A; i <= B; i++){
		cout << sum[i] << " ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	InputData();//입력 함수

	Solve();

	OutputData();//출력 함수
	return 0;
}

// 제출한 코드
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN ((int)1e5)

int A, B;
int sum[MAXN + 10];

void Solve() {
	int i, k, t;
	
	for (i = A; i <= B; i++){
		sum[i] = 1;
		t = sqrt(i);
		
		for (k = 2; k <= t; k++) {
			if (i%k != 0) continue;

			if (k * k == i) sum[i] += t;
			else sum[i] += (k + (i / k));
		}
	}
}

void InputData(){
	cin >> A >> B;
}

void OutputData(){
	int i;
	for (i = A; i <= B; i++){
		cout << sum[i] << " ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	InputData();//입력 함수

	Solve();

	OutputData();//출력 함수
	return 0;
}