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
    
    ListNode *getMid(ListNode *head){
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != nullptr){
            slow = slow->next;
        }
        return slow;
        
        
        
    }
    
    ListNode *reverseLL(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nxt;
        
        while(curr != nullptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        if(head == nullptr){
            return false;
        }
        
        ListNode *mid = getMid(head);
        ListNode *rev = reverseLL(mid);
        
        ListNode *p1 = head;
        ListNode *p2 = rev;
        
        while( p2 != nullptr){
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        
        return true;
    }
};