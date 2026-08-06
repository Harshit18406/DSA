class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int cnt = 0;
        ListNode* temp = head;

        // Count total nodes
        while(temp){
            cnt++;
            temp = temp->next;
        }

        // If first node needs to be deleted
        if(cnt == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int node = cnt - n;

        temp = head;

        // Go to previous node
        for(int i = 1; i < node; i++){
            temp = temp->next;
        }

        ListNode* delNode = temp->next;

        temp->next = temp->next->next;

        delete delNode;

        return head;
    }
};