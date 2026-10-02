/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* t = head;
        ListNode* before;
        if(left == right){
            return head;
        }
        int pos = 1;
        
        while(t!=nullptr and pos < left ){
                before = t;
                t = t->next;
                pos++;
                continue;
            }
        
        int count = right - left + 1;
        ListNode* curr = t;
        ListNode* prev = nullptr;
        while(count!=0){
            ListNode* nex = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            count--;
        }
        t->next = curr;
        if(before == nullptr){
            return prev;
        }
        before->next=prev;
        return head;
    }
};