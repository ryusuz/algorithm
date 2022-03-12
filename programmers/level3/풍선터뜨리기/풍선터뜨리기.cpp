#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
   // int min1 = a[0];
   // int min2 = *min_element(a.begin() + 1, a.end());
    
    int max = *max_element(a.begin(), a.end());
    auto it_max = find(a.begin(), a.end(), max);
    
    
    int min1 = *min_element(a.begin(), it_max);
    int min2 = *min_element(it_max, a.end());
    int min3 = *min_element()
    
    cout << min1 << "," << min2;
    
    int find_var = (min1 > min2) ? min1 : min2;
    
    sort(a.begin(), a.end());

    auto end = find(a.begin(), a.end(), find_var);
    
    answer = end - a.begin() + 1;
    
    return answer;
}


//


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1000000

using namespace std;
int left_min[MAX],right_min[MAX];

int solution(vector<int> a) {
    int answer = 0;
    
    //왼쪽부터 최솟값 저장
    left_min[0]=a[0];
    for(int i=1; i<a.size()-1;i++){
        left_min[i] = min(left_min[i-1],a[i]); 
    }
    
    //오른쪽부터 최솟값 저장
    right_min[a.size()-1]=a[a.size()-1];
    for(int i=a.size()-2;i>0;i--){
        right_min[i] = min(right_min[i+1],a[i]); 
    }
    
    //i번째 풍선을 검사할 때, i의 왼쪽 풍선들의 최솟값, i의 오른쪽 풍선들의 최솟값 둘 중
    //하나라도 i번째 풍선의 값보다 작으면 된다.
    for(int i=0; i<a.size();i++){
        if(i==0||i==a.size()-1){
            answer++;
            continue;
        }
        if(a[i]<left_min[i-1] || a[i]<right_min[i+1])
            answer++;
    }
    
    return answer;
}