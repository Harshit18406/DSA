/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode* slow = head;
        ListNode* fast = head;

        // Detect cycle
        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;

            // Cycle found
            if(slow == fast){

                ListNode* temp = head;

                while(temp != slow){

                    temp = temp->next;
                    slow = slow->next;
                }

                return temp;
            }
        }

        return NULL; 
    }
};