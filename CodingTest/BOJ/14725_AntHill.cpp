#include <iostream>
#include <map>
#include <stack>

using namespace std;

struct Node
{
    int depth = -1;
    string food;
    map<string, Node*> leaf;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    
    Node root;
    for(int i = 0; i < N; ++i) {
        int K; cin >> K;
        Node* parent = &root;
        for(int j = 0; j < K; ++j) {
            string info; cin >> info;
            if(parent->leaf.find(info) == parent->leaf.end()){
                Node* newNode = new Node();
                newNode->depth = parent->depth + 1;
                newNode->food = info;
                parent->leaf[info] = newNode;
            }
            
            parent = parent->leaf[info];
        }
    }
    
    stack<Node*> stk;
    stk.push(&root);
    
    while(!stk.empty()) {
        Node* parent = stk.top();
        stk.pop();
        
        if(parent->depth >= 0) {
            for(int i = 0; i < parent->depth; ++i) {
                cout << "--";
            }
            cout << parent->food << "\n";
        }
        
        for(auto iter = parent->leaf.rbegin(); iter != parent->leaf.rend(); ++iter) {
            stk.push((*iter).second);
        }
    }
}