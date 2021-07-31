//week10 수식 최대화
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calculate(long long a, long long b, char op) {
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == '*') return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    
    // 1. expression split
    vector<long long> split_nums;
    vector<char> split_ops;
    
    string tmp = "";
    for (char c : expression) {
        if (c >= '0' && c <= '9') {
            tmp += c;
        } else {
            split_ops.push_back(c);
            split_nums.push_back(stoll(tmp));
            tmp = "";
        }
    }
    split_nums.push_back(stoll(tmp));
    
    // 2. 우선순위 고려해서 계산
    vector<int> perm = {0, 1, 2};
    vector<char> op = {'+', '-', '*'};
    
    do {
        vector<long long> tmp_nums = split_nums;
        vector<char> tmp_ops = split_ops;
        
        for (int i = 0; i < perm.size(); i++) {
            for (int j = 0; j < tmp_ops.size();) {
                if (tmp_ops[j] == op[perm[i]]) {
                    long long result = calculate(tmp_nums[j], tmp_nums[j+1], tmp_ops[j]);
                    
                    tmp_nums.erase(tmp_nums.begin() + j);
                    tmp_nums.erase(tmp_nums.begin() + j);
                    tmp_nums.insert(tmp_nums.begin() + j, result);
                    
                    tmp_ops.erase(tmp_ops.begin() + j);
                } else {
                    j++;
                }
            }
        }
        answer = max(answer, abs(tmp_nums[0]));
        
    } while (next_permutation(perm.begin(), perm.end()));
    
    return answer;
}