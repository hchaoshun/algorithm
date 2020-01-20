/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//用hash表存储新旧节点的对应关系是解决问题的关键
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node *bakHead = head;
        Node *newHead = new Node(head->val);
        Node *newBakHead = newHead;
        unordered_map<Node*, Node*> hmap;
        hmap[head] = newHead;
        while (head->next != nullptr) {
            newHead->next = new Node(head->next->val);
            head = head->next;
            newHead = newHead->next;
            hmap[head] = newHead;
        }
        Node *Old = bakHead;
        Node *New = newBakHead;
        while (Old != nullptr) {
            New->random = hmap[Old->random];
            New = New->next;
            Old = Old->next;
        }
        return newBakHead;
    }
};
