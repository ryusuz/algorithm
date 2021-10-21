import java.util.*;

class Solution {
    class Solution {
        public int[] solution(int[] answers) {
            int[][] p = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
            int[] count = {0, 0, 0};
            
            for(int i = 0; i < answers.length; i++) {
                if (answers[i] == p[0][i%5]) count[0]++;
                
                if (answers[i] == p[1][i%8]) count[1]++;
                
                if (answers[i] == p[2][i%10]) count[2]++;
            }
            
            int max = Math.max(count[0], Math.max(count[1], count[2]));
            
            int cnt = 0;
            for(int i = 0; i < count.length; i++) {
                if (max == count[i]) cnt++;
            }
            
            int[] answer = new int[cnt];
            
            int j = 0;
            for(int i = 0; i < 3; i++) {
                if (max == count[i]) answer[j++] = i+1;
            }
            
            return answer;
        }
    }

    // 다른 사람 풀이
    public static int[] solution(int[] answers) {
        int[][] patterns = {
                {1, 2, 3, 4, 5},
                {2, 1, 2, 3, 2, 4, 2, 5},
                {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };

        int[] hit = new int[3];
        for(int i = 0; i < hit.length; i++) {
            for(int j = 0; j < answers.length; j++) {
                if(patterns[i][j % patterns[i].length] == answers[j]) hit[i]++;
            }
        }

        int max = Math.max(hit[0], Math.max(hit[1], hit[2]));
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < hit.length; i++)
            if(max == hit[i]) list.add(i + 1);

        int[] answer = new int[list.size()];
        int cnt = 0;
        for(int num : list)
            answer[cnt++] = num;
        return answer;
    }
}