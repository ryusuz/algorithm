//week7-2 문자열 압축
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    int maxLength = s.size() / 2;
    vector<int> lengths;
    
    if(s.size() == 1) return 1;
    
    for (int i = 1; i <= maxLength; i++) {
        vector<string> tmp;
        //cout << i << " :: ";
        for(int j = 0; j < s.size(); j = i+j) {
            tmp.push_back(s.substr(j,i));
            //cout << tmp.back() << " ";
        }
        tmp.push_back("end");
        
        int count = 1;
        string result;
        for (int j=0; j < tmp.size() - 1; j++) {
            if (tmp[j] == tmp[j+1]) {
                count++;
            } else {
                //cout << tmp[j] << " >> " << count << endl;
                if(count == 1) result = result + tmp[j];
                else result = result + to_string(count) + tmp[j];
                count = 1;
            }
        }
        
        lengths.push_back(result.size());
        //cout << lengths.back() << endl;
        
        //cout << " >> " << tmp.size() << " >>> " << result << endl;
    }
    
    answer = *min_element(lengths.begin(), lengths.end());
    
    return answer;
}

// 다른사람 풀이
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> convert(string s, int n)
{
    vector<string> v;
    for(int i = 0 ; i <s.length() ; i+=n)
    {
        v.push_back(s.substr(i,n));
    }
    return v;
}

int solution(string s) {
    int answer = 0;
    vector<string> tok;
    string before;
    int cnt = 1;
    int min = s.length();
    string str="";
    for(int j = 1 ; j <= s.length()/2 ; j++)
    {
        tok = convert(s,j);
        str = "";
        before = tok[0];
        cnt = 1;
        for(int i = 1 ; i < tok.size() ; i++)
        {
            if(tok[i] == before) cnt++;
            else
            {
                if(cnt != 1) str += to_string(cnt);
                str += before;
                before = tok[i];
                cnt = 1;
            }
        }
        if(cnt != 1)str += to_string(cnt);
        str += before;  
        min = min<str.length() ? min : str.length();
    }
    cout<<str;

    return min;
}