#include <iostream>
using namespace std;

#define MAXN 1000

int C, R, K;    // C: 열 R: 행
int X, Y;
int board[MAXN+10][MAXN+10] = {0};
int ans[2];

void cal() {
    int ret[2];

    int num = 1;
    int y = 1, x = 0;

    while (num <= C * R) {
        while (board[y][x+1] == 0) {
            x++;
            board[y][x] = num++;
            cout << "right (" << y << "," << x << "):: " << board[y][x] << endl;

            if (board[y][x] == K) {
                ans[0] = y;
                ans[1] = x;
                return;
            }
        }

        while (board[y+1][x] == 0) {
            y++;
            board[y][x] = num++;
            cout << "down (" << y << "," << x << "):: " << board[y][x] << endl;


            if (board[y][x] == K) {
                ans[0] = y;
                ans[1] = x;
                return;
            }

        }

        while (board[y][x-1] == 0) {
            x--;
            board[y][x] = num++;
            cout << "left (" << y << "," << x << "):: " << board[y][x] << endl;


            if (board[y][x] == K) {
                ans[0] = y;
                ans[1] = x;
                return;
            }
        }

        while (board[y-1][x] == 0) {
            y--;
            board[y][x] = num++;
            cout << "up (" << y << "," << x << "):: " << board[y][x] << endl;


            if (board[y][x] == K) {
                ans[0] = y;
                ans[1] = x;
                return;
            }
        }
    }

    ans[0] = 0;
}

int solve() {
    for(int i = 0; i <= R+1; i++) {
        board[0][i] = 1;
        board[C+1][i] = 1;
    }

    for(int i = 0; i <= C+1; i++) {
        board[i][0] = 1;
        board[i][R+1] = 1;
    }

    for(int i = 0; i <= C+1; i++) {
        for(int j = 0; j <= R+1; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cal();

    return 0;

}
 
int main13(void)
{
      // 입력받는 부분
      scanf("%d %d", &C, &R);
      scanf("%d", &K);
 
      // 여기서부터 작성
      solve();

      if (ans[0] == 0) cout << 0 << endl;
      else cout << ans[0] << " " << ans[1] << endl;
 
      return 0;
} 