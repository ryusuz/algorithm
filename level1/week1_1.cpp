#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;             // 사라진 인형 개수
        int basket[1000];       // 인형 담는 바구니
        int last_index = 0;         // 바구니에 담긴 인형의 마지막 인덱스

        // moves의 길이만큼 크레인 이동 반복
        for (int move = 0; move < moves.size(); move++) {
            for (int col = 0; col < board.size(); col++) {
                int row = moves[move] - 1;

                if (board[col][row] > 0) {
                    //System.out.println("인형 있음");
                    basket[last_index] = board[col][row];
                    board[col][row] = 0;

                    if (last_index > 0 && basket[last_index] == basket[last_index - 1]) {
                        last_index -= 1;
                        answer += 2;
                    } else {
                        last_index++;
                    }

                    break;

                }
            }

        }
        return answer;
}