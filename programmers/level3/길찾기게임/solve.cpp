// 22.03.18. 길 찾기 게임 (이진탐색트리 구현)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int x;
    int y;
    int num;
    Node *left;     // 왼쪽 자식
    Node *right;    // 오른쪽 자식
};

bool cmp(Node a, Node b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

void addNode(Node *parent, Node *child) {
    if (child-> x < parent->x) {
        if (parent->left == NULL) parent->left = child;
        else addNode(parent->left, child);
    } else {
        if (parent->right == NULL) parent->right = child;
        else addNode(parent->right, child);
    }
}

void preorder(vector<int> &answer, Node * node) {
    if(node == NULL) return;
    
    answer.push_back(node->num);
    preorder(answer, node->left);
    preorder(answer, node->right);
}

void postorder(vector<int> &answer, Node * node) {
    if(node == NULL) return;
    
    postorder(answer, node->left);
    postorder(answer, node->right);
    answer.push_back(node->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer = {{}, {}};
    vector<Node> nodes;
    
    for(int i = 0; i < nodeinfo.size(); i++) {
        Node tmp = {nodeinfo[i][0], nodeinfo[i][1], i+1};
        nodes.emplace_back(tmp);
    }
    
    sort(nodes.begin(), nodes.end(), cmp);
    
    Node *root = &nodes[0];
    
    for(int i = 1; i < nodes.size(); i++) {
        addNode(root, &nodes[i]);
    }
    
    preorder(answer[0], root);
    postorder(answer[1], root);
    
    return answer;
}


// 2. 나의 틀린 풀이
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) {
    if (a.second[1] == b.second[1]) return a.second[0] < b.second[0];
    
    return a.second[1] > b.second[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<int, vector<int>>> nodes(nodeinfo.size());
    
    for(int i = 0; i < nodeinfo.size(); i++) {
        nodes[i].first = i + 1;
        nodes[i].second = nodeinfo[i];
    }
    
    sort(nodes.begin(), nodes.end(), cmp);
    
    vector<vector<bool>> graph(nodes.size() + 1, vector<bool> (nodes.size() + 1, false));
    vector<pair<int, vector<int>>> parents;
    parents.push_back(nodes[0]);
    int idx = 1;
    
    while (idx < nodes.size()) {
        // 1. y값이 같은 애들을 차일드 백터에 넣음
        // 2. 차일드 벡터 돌면서 부모 벡터도 돌아 누구에게 들어가야하는지 확인
        // 3. 다 돌면 부모벡터 클리어하고 차일드벡터를 부모벡터에 넣어줘
        int child_y = nodes[idx].second[1];
        vector<pair<int, vector<int>>> children;
        
        while (idx < nodes.size() && child_y == nodes[idx].second[1]) {
            children.push_back(nodes[idx]);
            idx++;
        }
        
        for(int i = 0; i < children.size(); i++) {
            auto child = children[i];
            int gap = INT_MAX;
            int myP = 0;
            
            for(int j= 0; j < parents.size(); j++) {
                auto p = parents[j];
                int real = abs(child.second[0] - p.second[0]);
                
                if (gap > real) {
                    myP = p.first;
                    gap = real;
                }
            }
            
            graph[myP][child.first] = true;
            graph[child.first][myP] = true;
           // cout << child.first << "'s parent == " << myP << endl;
        }
     //   cout << endl;
        
        parents.clear();
        parents = children;
    }
    
    for(int i = 1; i <= nodes.size(); i++) {
        cout << i << " :: ";
        for(int j = 1; j <= nodes.size(); j++) {
            if (graph[i][j]) {
                cout << j << " ";
            }
        }
        cout << endl;


    }
    
    // 전위순회
    
    
    // 후위순회
   
    
    return answer;
}