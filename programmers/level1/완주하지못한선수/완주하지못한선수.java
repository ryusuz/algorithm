// 21.10.21.
import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        
        for(String p : participant) {
            if (!map.containsKey(p)) map.put(p, 1);
            else map.put(p, map.get(p)+1);
        }
        
        for(String com : completion) {
            if(map.containsKey(com)) map.put(com, map.get(com)-1);
        }
        
        for(String key : map.keySet()) {
            if (map.get(key) != 0) return key; 
        }
        
        return answer;
    }

    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<>();
        for (String player : participant) hm.put(player, hm.getOrDefault(player, 0) + 1);
        for (String player : completion) hm.put(player, hm.get(player) - 1);

        for (String key : hm.keySet()) {
            if (hm.get(key) != 0){
                answer = key;
            }
        }
        return answer;
    }
}