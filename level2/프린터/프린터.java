// 프린터 21.10.12.
import java.util.*;

class Pair{
    private int loc;
    private int prio;
    
    public Pair(int loc, int prio) {
        this.loc = loc;
        this.prio = prio;
    }
    
    public int getLoc() {
        return loc;
    } 
    
    public int getPrio() {
        return prio;
    }
}

class Solution {
    public void reverseSort(int[] arr) {
        Arrays.sort(arr);
        
        for (int i = 0; i < arr.length / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[arr.length - i - 1];
            arr[arr.length - i - 1] = temp;
        }
    }
    
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        Queue<Pair> q = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++) {
            q.add(new Pair(i, priorities[i]));
        }
        
        reverseSort(priorities);
        //System.out.println(priorities[0]);
        
        int i = 0;
        while (!q.isEmpty()) {
            Pair front = q.peek();
            
            if (front.getPrio() == priorities[i]) {
                answer++;
                i++;
                q.remove();
                
                if (front.getLoc() == location) break;
            } else {
                q.add(front);
                q.remove();
            }

        }
        
        return answer;
    }
}