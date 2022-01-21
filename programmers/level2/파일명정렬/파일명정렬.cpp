// 22.01.20. 파일명 정렬
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct file {
    string head;
    string number;
    string tail;
};

// 대문자 -> 소문자 변환
string convert(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) str[i] = tolower(str[i]);
    }
    
    return str;
}

bool cmp(file a, file b) {
    if (convert(a.head) == convert(b.head)) return stoi(a.number) < stoi(b.number);
    else return convert(a.head) < convert(b.head);
}

vector<string> solution(vector<string> files) {
    vector<file> splits;
    
    for(auto& f : files) {
        file tmpFile;
        int idx;
        
        // head : 숫자 나오면 끝
        for(int i = 0; i < f.size(); i++) {
            if (isdigit(f[i])) break;
            
            tmpFile.head += f[i];
            idx = i+1;
        }
        
        // number : 숫자 아니면 끝 or 5자리 넘으면 끝
        for(int i = idx; i < f.size(); i++) {
            if (!isdigit(f[i]) || tmpFile.number.size() == 5) break;
            
            tmpFile.number += f[i];
            idx = i+1;
        }
        
        // tail : 뒤에 남은거 다
        for (int i = idx; i < f.size(); i++) {
            tmpFile.tail += f[i];
        }
        
        splits.push_back(tmpFile);
    }
    
     // 정렬
    stable_sort(splits.begin(), splits.end(), cmp);
    
    vector<string> answer;
    for(auto& f : splits) {
        // cout << f.head << " " << f.number << " " << f.tail << endl;
        answer.push_back(f.head + f.number + f.tail);
    }
    
    
    return answer;
}