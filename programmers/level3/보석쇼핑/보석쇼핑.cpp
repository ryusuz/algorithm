// 22.03.15. 보석쇼핑(투포인터)
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int MIN;

bool twopointer(int start, int end, int type, vector<string> &gems) {
    map<string, int> m;
    
    for(int i = start; i < end; i++) {
        m[gems[i]]++;
        cout << gems[i] << " ";
        
        if (m.size() == type) {
            int len = end - start;
            cout << " :::: len == " << len << endl;
            cout << "   MIN == " << MIN << endl;
            
            if (MIN >= len) {
                MIN = len;
                cout << "   change MIN == " << MIN << endl;
                return true;
            }
        }
    }
    
    cout << endl;
    
    return false;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    map<string, int> m;
    
    MIN = gems.size();
    
    for(auto g : gems) {
        m[g] = 0;
    }
    
    int type = m.size();
    
    if (type == 1) return {1, 1};
    
    for(int start = 0; start < gems.size(); start++) {
        int end = start + type;
        if (end > gems.size()) break;
        cout << "here" <<endl;
        cout << gems.size()  << ":::" << type << endl;
        while (1) {
            if (twopointer(start, end, type, gems)) {
                answer[0] = start + 1;
                answer[1] = end;
                cout << answer[0] << "," << answer[1] << endl << endl;
                
                if (MIN == type) break;
                break;
            } else {
                end++;
                
                if (end > gems.size()) break;
            }
        }
        
        if (MIN == type) break;
    }
    
    
    cout << type << endl;
    return answer;
}

/*
보석 종류가 몇 갠지 확인해야함 => 맵에 넣어서 확인. 맵의 크기로
보석 종류의 수만큼 잘라보고 확인

투포인터 사용.
start = 0, 1, 2 ,...
end = 456,.... 567..., 678,,,
*/