# [Level3] 길 찾기 게임

https://programmers.co.kr/learn/courses/30/lessons/42892

</br>

## ✏️ 풀이 방법

트리를 구현해야하는 문제이다.

평소 트리를 구현해봤다면 어렵지 않았을 문제지만...난 대학교 2학년 자료구조 시간에 한 이후로 해본 적이 없다. (이마저도 열심히 안 했었다.)

이진 탐색 트리를 구현하고 전위순회와 후위순회 함수를 만들어 실행시키면 끝

</br>

## 💡 이진탐색 트리 구현

1. 노드 구조체 생성 및 초기화
* 노드 구조체 생성
```c++
struct Node {
    int x;
    int y;
    int num;
    Node *left;     // 왼쪽 자식
    Node *right;    // 오른쪽 자식
};
```

* 노드 초기화
```c++
vector<Node> nodes;
    
for(int i = 0; i < nodeinfo.size(); i++) {
    Node tmp = {nodeinfo[i][0], nodeinfo[i][1], i+1};
    nodes.emplace_back(tmp);
}
```

<br/>

2. 노드의 y값을 기준으로 내림차순 해줌. Tree[0]은 root!!
* sort의 매개변수로 줄 내림차순 함수
```c++
bool cmp(Node a, Node b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}
```

* sort
```c++
sort(nodes.begin(), nodes.end(), cmp);
```

<br/>

3. add 함수 정의. root 노드를 시작으로 노드를 add해서 트리를 만들어줌
* addNode 함수 정의
```c++
void addNode(Node *parent, Node *child) {
    if (child-> x < parent->x) {
        if (parent->left == NULL) parent->left = child;
        else addNode(parent->left, child);
    } else {
        if (parent->right == NULL) parent->right = child;
        else addNode(parent->right, child);
    }
}
```

* 트리 생성
```c++
Node *root = &nodes[0];
    
for(int i = 1; i < nodes.size(); i++) {
    addNode(root, &nodes[i]);
}
```

<br/>

4. preorder와 postorder 함수 정의 후 실행 ⭐️(재귀함수!)
* preorder 전위순회
```c++
void preorder(vector<int> &answer, Node * node) {
    if(node == NULL) return;
    
    answer.push_back(node->num);
    preorder(answer, node->left);
    preorder(answer, node->right);
}
```

* postorder 후위순회
```c++
void postorder(vector<int> &answer, Node * node) {
    if(node == NULL) return;
    
    postorder(answer, node->left);
    postorder(answer, node->right);
    answer.push_back(node->num);
}
```

* 함수 실행
``` c++
preorder(answer[0], root);
postorder(answer[1], root);
```