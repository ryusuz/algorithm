//22. 02. 14. 구명보트(그리디)

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int sidx = 0;
    int eidx = people.size() - 1;
    
    while (sidx <= eidx) {
        int start = people[sidx];
        int end = people[eidx];
        int sum = start + end;
        
        if (sum <= limit) sidx++;
        
        eidx--;
        answer++;
    }
    
    
    return answer;
}

//////
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());
    int N = (int)people.size();
    int res = 0;
    for (int i = 0, j = N - 1; i <= j; i++) {
        if (people[i] + people[j] <= limit) {
            j--;
        }
        res++;
    }
    return res;
}
