// week17-2 튜플
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

void eraseAll(vector<string> v) {
    while (v.size()) {
        v.erase(v.begin());
    }
}

vector<int> solution(string s) {
    // 순서 중요 중복 없음
    vector<int> answer;
    vector<string> parse;
    
    vector<vector<int>> parse2;
  
    string tmp = "";
    int check = 0;
    vector<int> vtmp;
    for(int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') check++;
                
        if (check == 1 && isdigit(s[i])) tmp += s[i];
        
        if (check == 1 && s[i] == ',') {
            vtmp.push_back(stoi(tmp));
            tmp = "";
        }
        
        if (s[i] == '}') {
            vtmp.push_back(stoi(tmp));
            tmp = "";
            check--;
            
            parse2.push_back(vtmp);
            vtmp.erase(vtmp.begin(), vtmp.end());
            //cout << vtmp.size();
        }        
    }
    
    sort(parse2.begin(), parse2.end(), cmp);
    
    /*
    for(auto& v : parse2) {
        for (auto& num : v) {
            cout << num << " ";
        }
        cout << endl;
    }
    */
    
    
    answer.push_back(parse2[0][0]);
    
    for (int i = 1; i < parse2.size(); i++) {
        for (auto& num : parse2[i]) {
            if (find(answer.begin(), answer.end(), num) == answer.end()) answer.push_back(num);
        }
    }
    
    
    
    /*
    queue<int> q;
    q.push(stoi(parse[0]));
    cout << q.front() << endl;
    
    for (int i = 1; i < parse.size(); i++) {
        for (auto& c : parse[i]) {
            if (c == ',') continue;
            
            if (q.back() != c) {
                cout << c << endl;
                q.push(c);
            }
        }
    }
    */
    

    return answer;
}

/*
잘 짠 코드

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    int st[101010]={};
    vector<int> answer;
    string tmp;
    for(char i: s){
        if(i-'0' >=0 && i-'0' <=9){
            tmp += i;
        }
        else{
            if(tmp.length())
                st[stoi(tmp)]++, tmp.clear();
        }
    }
    vector<pair<int, int>> v;
    for(int i =0; i <101010; i++)
        if(st[i])
            v.push_back({st[i], i});
    sort(v.begin(), v.end());
    reverse(v.begin(),v.end());
    for(auto it: v) answer.push_back(it.second);
    return answer;
}
*/