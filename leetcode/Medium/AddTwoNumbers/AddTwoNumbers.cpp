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

#include <iostream>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;

        while (1) {
            int num1 = 0, num2 = 0;
            
            if (l1 != nullptr) {
                num1 = l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                num2 = l2->val;
                l2 = l2->next;
            }
            
            int sum = num1 + num2 + curr->val;
            curr->val = sum % 10;
                        
            
            if (l1 == nullptr && l2 == nullptr) {
                if (sum / 10 == 1) curr->next = new ListNode(1);
                break;
            }
                
            curr->next = new ListNode(sum / 10);
            curr = curr->next;

        }
        
        return head;
        
    }
};