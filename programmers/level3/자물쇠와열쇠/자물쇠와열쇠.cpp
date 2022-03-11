// 22.03.11. 자물쇠와 열쇠
#include <string>
#include <vector>
using namespace std;

int N, M;

bool check(vector<vector<int>> &lock, vector<vector<int>> &key, int y, int x) {
    bool ret = true;
        
    for(int i = y; i < y + M; i++)
        for(int j = x; j < x + M; j++)
            lock[i][j] += key[i - y][j - x];
    
    for(int i = N; i < N * 2; i++){
        for(int j = N; j < N * 2; j++) {
            if (lock[i][j] != 1) {
                ret = false;
                break;
            }
        }
        if (!ret) break;
    }
        
    for(int i = y; i < y + M; i++)
        for(int j = x; j < x + M; j++)
            lock[i][j] -= key[i - y][j - x];
        
    return ret;
}

vector<vector<int>> rotate(vector<vector<int>> &key) {
    vector<vector<int>> ret(M, vector<int>(M, 0));
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            ret[j][M - i - 1] = key[i][j];
        }
    }
    
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    N = lock.size();
    M = key.size();
    
    vector<vector<int>> nlock(N * 3, vector<int> (N * 3, 0));
    
    for(int i = N; i < N * 2; i++) {
        for(int j = N; j < N * 2; j++) {
            nlock[i][j] = lock[i - N][j - N];
        }
    }
    
    int start = N - M + 1;
    
    for(int i = start; i < N * 2; i++) {
        for(int j = start; j < N * 2; j++) {
            for(int k = 0; k < 4; k++) {
                if (check(nlock, key, i, j)) return true;

                key = rotate(key);
            }
        }
    }
    
    return answer;
}

/* 
    123    741
    456    852
    789    963

    key[i][j] ==> ret[j][M-i-1]
    0,1
    2,1
    */