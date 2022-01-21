import java.util.*;

class Solution {
    private String rotate(String s, int num) {
        String front = s.substring(num);
        String back = s.substring(0, num);
        return front+back;
    }
    
    public int solution(String s) {
        int answer = 0;
        
        for(int i = 0; i < s.length(); i++) {
            String rts = rotate(s, i);
            
            Stack<Character> st = new Stack<>();
            boolean flag = false;
            
            for(char c : rts.toCharArray()) {
                if (c == '(' || c == '{' || c == '[') st.push(c);
                else {
                    if (st.isEmpty()) continue;
                    
                    char peek = st.peek();
                    st.pop();
                    
                    if (peek == '(') flag = (c == ')') ? true : false;
                    else if (peek == '[') flag = (c == ']') ? true : false;
                    else if (peek == '{') flag = (c == '}') ? true : false;
                    
                    if (!flag) break;
                }
            }
            
            if (st.isEmpty() && flag) answer++;
        }
        return answer;
    }
}