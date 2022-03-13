// 22.03.12. 숫자게임
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int a_idx = 0, b_idx = 0;
    
    while (b_idx < B.size()) {
        if (A[a_idx] >= B[b_idx]) {
            b_idx++;
            continue;
        }
        
        answer++;
        a_idx++;
        b_idx++;
    }
    
    return answer;
}

/*
1 3 5 7 :: 2 2 6 8
2 6 8 x

1 3 8   :: 1 2 9
2 9 x
*/

// 2. 조합 ==> 시간 초과
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(B.begin(), B.end());
    
    do {
        int cnt = 0;
        
        for(auto n : B) cout << n << " ";
        cout << endl;

        for(int i = 0; i < A.size(); i++) {
            if (A[i] < B[i]) cnt++;
        }
        
        if (answer < cnt) answer = cnt;
        
    } while (next_permutation(B.begin(), B.end()));

    
    return answer;
}

/*
완전탐색? => 조합

1 3 8
9 1 2 => 1 2 9

1 3 8
2 1 9


5 1 3 7
8 2 6 2
*/