// 22.03.14.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(int& n, vector<int>& stones, int& k){
    int cnt=0;
    
    for(int i = 0; i < stones.size(); i++){
        if(stones[i] - n <= 0) cnt++;
        else cnt = 0;
        
        if(cnt >= k) return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int Start = 1;
    int End = *max_element(stones.begin(),stones.end());
    
    while(Start <= End){
        int mid = (Start + End) / 2;
        //못건너면 사람 줄여서 줄인 사람은 건널 수 있는지 알아본다.
        if(binarySearch(mid, stones, k)) End = mid-1; 
        else Start = mid+1; //건너면 사람 늘려서 더 건널 수 있는지 알아본다.
    }
    
    return Start;
}

// 2. 내 풀이 ===> 시간 초과
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    priority_queue<pii> pq;
    map<int, int> zeros;
    
    for(int i = 0; i < stones.size(); i++) {
        if (stones[i] == 0) {
            cout << "zero" << endl;
            zeros[i] = i;
            continue;
        }
        
        pq.push({-stones[i], -i});
    }
    
    int sum = 0, min = 0;
    int idx;
    
    while(1) {        
        bool check = false;
        int prev = -2;
        int cnt = 0;
        
        // 0 3 4 5 7 9
        for(auto z : zeros) {
            cout << "zero idx :: " << z.first << endl;
            if (z.first == prev + 1) {
                cout << "   continue!" << endl;
                cnt++;
                prev = z.first;
                
                if (cnt == k - 1) {
                    cout << "   break!!!!" << endl;
                    check = true;
                    break;
                }
            } else {
                prev = z.first;
                cnt = 0;
                check = false;
            }
        }
        
        if (pq.empty() || check) break;

        min = -pq.top().first;      // 1
        idx = -pq.top().second;           //
        pq.pop();
        
        cout << "min :: " << min << endl;
                
        // 실제 뛸 수 있는 횟수
        int real = min - sum;   // 1-0...2-1
        answer += real;         // 1 1
        sum += real;             // 1 

        vector<int> min_idxs;
        min_idxs.push_back(idx);
        
        while(1) {
            int next = -pq.top().first;
            cout << "   next min :: " << next << endl;

            if (next == min) {
                min_idxs.push_back(-pq.top().second);
                pq.pop();
            } else break;
        }
        
        for(auto n : min_idxs) {
            zeros[n] = n;
        }
                
    }
    
    
    return answer;
}

/*
m[idx] = var;

1. 0이 아닌 최솟값 찾기. answer += 최솟값
2. 0인 애들 있는지 확인 있으면 인덱스확인 => 연결되면 k보다 큰지 확인
3. 작으면 그다음 최솟값 찾기.

*/
