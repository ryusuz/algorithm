import java.util.*;

class Solution {
    boolean[][] visit = new boolean[100][100];
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int N, M;
    
    public int bfs(int y, int x, int var, int[][] picture) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(y, x));
        visit[y][x] = true;
        int count = 1;
        
        while(!q.isEmpty()) {
            int cy = q.peek().y;
            int cx = q.peek().x;
            int cvar = picture[cy][cx];
            q.remove();
            
            for (int i = 0; i < 4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                
                if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
                int nvar = picture[ny][nx];
                
                if (var == nvar && !visit[ny][nx]) {
                    q.add(new Pair(ny, nx));
                    visit[ny][nx] = true;
                    count++;
                }
                
            }
        }
        
        return count;
    }
    
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        int[] answer = new int[2];
        N = n; M = m;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && picture[i][j] != 0) {
                    numberOfArea++;
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, bfs(i, j, picture[i][j], picture));
                }
            }
        }
     
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}

class Pair {
    int x;
    int y;
    
    public Pair(int y, int x) {
        this.x = x;
        this.y = y;
    }
}