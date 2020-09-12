/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//dfs
//用一个hash map存储旧节点和新节点的对应关系，
//如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> record;
        return dfs(node, record);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& record) {
        if (node == nullptr) return nullptr;
        if (record.find(node) != record.end()) return record[node];
        Node* new_node = new Node(node->val);
        record[node] = new_node;
        for (Node* n : node->neighbors) {
            new_node->neighbors.push_back(dfs(n, record));
        }
        return new_node;
    }
};

//bfs 用一个队列存储old节点
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> record;
        Node* new_node = new Node(node->val);
        record[node] = new_node;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node *top_node = q.front();
            q.pop();
            //将old节点的neighbors拷贝到new节点的neighbors
            for (auto n : top_node->neighbors) {
                if (record.find(n) == record.end()) {
                    record[n] = new Node(n->val);
                    q.push(n);
                }
                record[top_node]->neighbors.push_back(record[n]);
            }
        }
        return record[node];
    }
};
