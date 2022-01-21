// 21.10.22.
class Solution {
    public int solution(int n) {
        int i = 1;
        while(true) {
            int res = n % i;
            
            if(res == 1) break;
            
            i++;
        }
        
        return i;
    }
}