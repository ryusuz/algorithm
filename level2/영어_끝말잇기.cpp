// 영어 끝말잇기 21.10.07.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    map<string, int> m;
    
    int cnt = 0;
    int num = 0;
    string preWord = words[0].substr(0,1);
    
    for (int i = 0; i < words.size(); i++) {
        num = (i+1) % n ? (i+1) % n : (i+1) % n + n;
        if (num == 1) cnt++;
        
        m[words[i]]++;
        if (preWord[preWord.size()-1] != words[i][0] || m[words[i]] != 1) {
            answer = {num, cnt};
            break;
        }
        
        preWord = words[i];
    }
    
    return answer;
}

// 다른 사람 풀이
vector<int> solution(int n, vector<string> words) {
    int len=words.size();
    map<string,int> h;
    h[words[0]]=1;
    for(int i=1;i<len;i++)
    {
        int len1=words[i-1].size();
        if(h[words[i]] || (words[i-1][len1-1]!=words[i][0]))
            return {i%n+1,i/n+1};
        else
            h[words[i]]=1;
    }
    return {0,0};
}