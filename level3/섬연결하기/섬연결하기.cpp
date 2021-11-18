// 섬 연결하기 21.10.17.
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int getParent(int node, vector<int> set) {
    if (set[node] == node) return node;         // 부모노드 == 자신이면 자신 리턴  
    return set[node] = getParent(set[node], set);    // 아니면 최상위 부모노드 리턴
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> set(n);
    for (int i = 0; i < n; i++) {
        set[i] = i;
    }
    
    // 거리 오름차순으로 정렬
    sort(costs.begin(), costs.end(), cmp);
    
    
    for(int i = 0; i < costs.size(); i++) {
        int start = getParent(costs[i][0], set);
        int end = getParent(costs[i][1], set);
        int cost = costs[i][2];
        
        // 사이클 안되면 간선 연결
        if (start != end) {
            answer += cost;
            set[end] = start;
        }
    }
    
    
    
    return answer;
}