//week7-1 비밀지도
#include <string>
#include <vector>
#include <iostream>

using namespace std;
string changeBinary(int num, int n);

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> tmp;
    
    // 벽 = 1, 공백 = 0
    // 지도1과 지도2 중 하나라도 벽(1)이면 벽(1), 둘 다 공백(0)이면 전체도 공백(0) => OR연산
    // 굳이 이진수로 변환할 필요 x네
    for(int i = 0; i < n; i++) {
        answer.push_back(changeBinary(arr1[i] | arr2[i], n));
    }
    
    return answer;
}

string changeBinary(int num, int n) {
    string result;
    string tmp;
    
    while (num != 0) {
        tmp += to_string(num%2);
        num /= 2;
    }
    
    if (tmp.size() < n) {
        while (tmp.size() != n) tmp = tmp + '0';
    }
        
    for(int i = n-1; i >= 0; i--) {
        if (tmp[i] == '1') result += '#';
        else if(tmp[i] == '0') result += ' ';
    }
    
    return result;
}

// 다른 사람 풀이
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i <n; i++){
        arr1[i] = arr1[i]|arr2[i];
        string ans = "";
        for(int j = 0; j<n; j++){
            if(arr1[i] % 2 == 0) ans = " " + ans;
            else ans = "#" + ans;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(ans);
    }
    return answer;
}