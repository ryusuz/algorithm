// 21.01.23. 모음사전 ==> 다시 풀기!!!
// 참고 : https://blog.naver.com/PostView.naver?blogId=jinhan814&logNo=222488988156&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    int v[5] = {781, 156, 31, 6, 1};
    
    for(int i = 0; i < word.size(); i++) {
        answer += string("AEIOU").find(word[i]) * v[i] + 1;    
    }
    
    return answer;
}