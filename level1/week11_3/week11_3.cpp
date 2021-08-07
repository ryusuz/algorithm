//week11-3 같은 숫자는 싫어
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    return arr;
}