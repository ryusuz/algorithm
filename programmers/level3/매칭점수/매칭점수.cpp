// 22.03.22 매칭 점수
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

map<string, vector<string>> linked;
vector<pair<double, int>> match; // match, idx

struct Page {
    int idx;    
    string url;     // url
    double basic;      // 기본점수
    double cnt;        // 외부링크 개수
    double link;       // 링크점수
};

bool cmp (pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

Page parseHTML(string word, int idx, string &page) {
    int W = word.size();
    
    int cursur = page.find("<head>") + 6;
    int last = page.find("</head");
    string head = page.substr(cursur, last-cursur);
    
    string tmp = head;
    string url;
    
    while (1) {
        cursur = tmp.find("<meta");
        string meta;
        
        while (tmp[cursur] != '>') {
            meta += tmp[cursur];
            cursur++;
        }
        
        auto check = meta.find("content");
        
        if (check != string :: npos) {
            while (meta[check] != '\"') check++;
            check += 9;
            
            while (meta[check] != '"') {
                url += meta[check];
                check++;
            }
            
            break;
        } else {
            tmp = tmp.substr(cursur + 1, -1);
        }
    }
    
    cursur = page.find("<body>") + 6;
    last = page.find("</body>");
    string body = page.substr(cursur, last-cursur);
    
    for(auto &b : body)
        if (isupper(b)) b = tolower(b);
    
    double basic = 0;
        
    tmp = body;
    while (1) {
        auto check = tmp.find(word);
        
        if (check != string::npos && !isalpha(tmp[check-1]) && !isalpha(tmp[check+W])) {
            basic++;
            int csr = check + W;
            tmp = tmp.substr(csr, -1);
        } else break;
    }
        
    tmp = body;
    double cnt = 0;
    while (1) {
        auto check = tmp.find("<a href");
        
        if (check != string::npos) {
            cnt++;
            while (tmp[check] != '\"') check ++;
            check += 9;
            
            string linked_url;
            
            while (tmp[check] != '\"') {
                linked_url += tmp[check];
                check++;
            }
            
            linked[linked_url].push_back(url);            
            tmp = tmp.substr(check, -1);
        } else break;
    }
    
    Page ret = {idx, url, basic, cnt}; 
    return ret;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    map<string, Page> newPages;
    
    for(auto &w : word) if (isupper(w)) w = tolower(w);
    
    for(int i = 0; i < pages.size(); i++) {
        Page page = parseHTML(word, i, pages[i]);
        newPages[page.url] = page;
    }
    
    for(auto page : newPages) {        
        double link = 0;
        double match_s = 0;
        
        for(int i = 0; i < linked[page.first].size(); i++) {
            string linked_url = linked[page.first][i];
            double linked_basic = newPages[linked_url].basic;
            double linked_cnt = newPages[linked_url].cnt;

            if (linked_cnt == 0) continue;
            link += linked_basic / linked_cnt;
        }
        
        match_s = page.second.basic + link;
        match.push_back({match_s, page.second.idx});
    }
    
    sort(match.begin(), match.end(), cmp);
    
    return match[0].second;
}