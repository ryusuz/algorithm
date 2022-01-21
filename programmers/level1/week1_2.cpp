// week1_2 레벨1 - 로또의 최고 순위와 최저 순위
#include <string>
#include <vector>

using namespace std;

int cal_lank(int num) {
        switch (num) {
            case 6: return 1;
            case 5: return 2;
            case 4: return 3;
            case 3: return 4;
            case 2: return 5;
            default: return 6;
        }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int win_nums_count = 0;
    int zero_count = 0;

    /*
     * 1. lottos와 win_nums 중 일치하는 숫자 카운트
     * 2. lottos의 0의 개수 카운트
     * 3. 일치하는 숫자 + 0의 개수 = 최고 순위, 일치하는 숫자 = 최저 순위
     */

    // 일치하는 숫자 카운트
    for (int i = 0; i < win_nums.size(); i++) {
        for (int j = 0; j < lottos.size(); j++) {
            if (win_nums[i] == lottos[j]) {
                win_nums_count++;
            }
        }
    }

    // 0의 개수 카운트
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            zero_count++;
        }
    }

    int high = cal_lank(win_nums_count + zero_count);
    int low = cal_lank(win_nums_count);

    answer.push_back(high);
    answer.push_back(low);
    
    return answer;
}