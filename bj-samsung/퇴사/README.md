# [S3] 퇴사

https://www.acmicpc.net/problem/14501

</br>

## ✏️ 풀이 방법
1. dfs 사용.
2. 날짜를 넣고, 해당 날짜의 시간비용을 더해서 N+1보다 작으면 현재 날짜의 비용을 더해주고 다음 dfs 실행
3. N+1이랑 같으면 해당 날짜를 포함 시켜야하므로 cost를 더해줌
4. 크면 해당 날짜의 cost는 더해줄 필요가 없다.
5. answer과 cost 중 큰 값을 answer에 넣는다.

<br/>
