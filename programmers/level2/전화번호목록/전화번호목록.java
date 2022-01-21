// 21.10.21.
import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;

        Arrays.sort(phone_book);
        for(int i = 0; i < phone_book.length - 1; i++) {
            if (phone_book[i].length() > phone_book[i+1].length()) continue;
            String next = phone_book[i+1].substring(0, phone_book[i].length());
            
            if(phone_book[i].equals(next)) return false;
        }
        
        return answer;
    }

    // 다른 사람 풀이
    public boolean solution(String[] phoneBook) {
        for(int i=0; i<phoneBook.length-1; i++) {
             for(int j=i+1; j<phoneBook.length; j++) {
                 if(phoneBook[i].startsWith(phoneBook[j])) {return false;}
                 if(phoneBook[j].startsWith(phoneBook[i])) {return false;}
             }
         }
         return true;
     }
}