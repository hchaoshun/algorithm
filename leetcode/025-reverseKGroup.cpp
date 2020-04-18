//以k为一组依次翻转
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//1. 链表分区为已翻转部分+待翻转部分+未翻转部分
//2. 需记录翻转链表前驱pred和后继succ，方便翻转完成后把已翻转部分和未翻转部分连接起来
//3. start 和end为起始翻转链表,最后长度不足k时退出
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy, *succ = &dummy;
        ListNode *start = nullptr, *end = nullptr;
        while (prev->next != nullptr) {
            end = prev;
            for (int i = 0; i < k && end != nullptr; i++)
                end = end->next;
            if (end == nullptr) break;
            start = prev->next;
            succ = end->next;
            end->next = nullptr;
            end = reverseList(start);
            prev->next = end;
            start->next = succ;
            prev = start;
            succ = prev; 
        }
        return dummy.next;
    }

    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};
