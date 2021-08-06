//week11-2 모의고사
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores = {0, 0, 0};
    vector<vector<int>> students = {{1, 2, 3, 4, 5},
                                    {2, 1, 2, 3, 2, 4, 2, 5},
                                    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    
   for (int i = 0; i < answers.size(); i++) {
       int answer = answers[i];
       
       if (answer == students[0][i%5]) scores[0]++;
       
       if (answer == students[1][i%8]) scores[1]++;
       
       if (answer == students[2][i%10]) scores[2]++;
   }
        
   int max_num = max(max(scores[0], scores[1]), scores[2]);
    
    for (int i = 0; i < scores.size(); i++) {
        if (max_num == scores[i]) answer.push_back(i+1);
    }
    
    
    return answer;
}