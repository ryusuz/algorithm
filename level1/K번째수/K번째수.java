// 21.10.21.
class Solution {
    import java.util.*;

    class Solution {
        public int[] solution(int[] array, int[][] commands) {
            List<Integer> list = new ArrayList<>();

            for(int i = 0; i < commands.length; i++) {
                int[] tmp = Arrays.copyOfRange(array, commands[i][0]-1, commands[i][1]);
                Arrays.sort(tmp);
                list.add(tmp[commands[i][2]-1]);
            }

            int i = 0;
            int[] answer = new int[list.size()];
            for(int n : list) {
                answer[i++] = n;
            }
            
            return answer;
        }

        // 퀵 정렬 직접 구현해서 풀기 >>> 시간 훨씬 빠름
        public int[] solution(int[] array, int[][] commands) {
            
            List<Integer> list = new ArrayList<>();
            
            for(int i = 0; i < commands.length; i++) {
                int len = commands[i][1] - commands[i][0] + 1;
                
                if (len == 1) {
                    list.add(array[commands[i][0]-1]);
                    continue;
                }
                
                int k = 0;
                int[] a = new int[len];
                for (int j = commands[i][0]-1; j < commands[i][1]; j++) {
                    a[k++] = array[j];
                }
                
                sort(a, 0, len-1);
                list.add(a[commands[i][2]-1]);
            }
            
            int[] answer = new int[list.size()];
            int i = 0;
            for(int n : list) {
                answer[i++] = n;
            }
            
            return answer;
        }
      
        // 퀵 정렬
        public void sort(int[] a, int left, int right) {
            int lo = left;
            int hi = right;
            int p = a[(lo+hi)/2];
            
            do {
                while (a[lo] < p) lo++;
                while (a[hi] > p) hi--;
                
                if (lo <= hi) {
                    int tmp = a[lo];
                    a[lo] = a[hi];
                    a[hi] = tmp;
                    
                    lo++;
                    hi--;
                }
            } while (lo <= hi);
            
            if (left < hi) sort(a, left, hi);
            if (right > lo) sort(a, lo, right);
        }
    }
}
