// 22. 01. 15. 메뉴리뉴얼

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool cmp (pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

void dfs(map<string, int> &m, string &order, string comb, int depth, int index) {
    if (depth == comb.size()) {
        m[comb]++;
        // cout << endl << "in!!" << endl;
        return;
    }
    
    for (int i = index; i < order.size(); i++) {
        comb[depth] = order[i];
        //cout << comb << " ";
        dfs(m, order, comb, depth+1, i+1);
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string ,int> m;
    
    // orders는 정렬되어있지않음, 정렬 후 모든 조합 구해서 맵에 넣기
    for(int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        string comb = "";
        
        for(int j = 0; j < course.size(); j++) {
            comb.resize(course[j]);
            dfs(m, orders[i], comb, 0, 0);
        }
    }
    
    // 맵 -> 벡터에 옮기기(2 이상인 애들만)
    vector<pair<string, int>> sorted;
    for (auto& elem : m) {
        if (elem.second > 1) {
            sorted.push_back(make_pair(elem.first, elem.second));
        }
    }
    
    // 벡터 정렬
    sort(sorted.begin(), sorted.end(), cmp);
    // for(auto& p : sorted) {
    //     cout << p.first << " " << p.second << endl;
    // }
    
    // 값이 큰 애들만 정답 벡터에 넣기
    for(int i = 0; i < course.size(); i++) {
        int max = 0;
        
        for(int j = 0; j < sorted.size(); j++) {
            if (sorted[j].first.size() != course[i])
                continue;
            else if (max == 0) {    // 최대값 첫 등장
                answer.push_back(sorted[j].first);
                max = sorted[j].second;
            } else if (max == sorted[j].second){
                answer.push_back(sorted[j].first);
            } else
                break;
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}


/////////
map<string,int> combi;

void combination(string src, string crs, int depth) {
    if (crs.size() == depth) combi[crs]++;

    else for (int i = 0; i < src.size(); i++)
        combination(src.substr(i+1), crs+src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string &order : orders)
        sort(order.begin(), order.end());

    for (int crs : course) {
        for (string order : orders)
            combination(order, "", crs);

        int sup = 0;
        for (auto it : combi)
            sup = max(sup, it.second);
        for (auto it : combi)
            if (sup >= 2 && it.second == sup)
                answer.push_back(it.first);
        combi.clear();
    }

    sort(answer.begin(), answer.end());
    return answer;
}