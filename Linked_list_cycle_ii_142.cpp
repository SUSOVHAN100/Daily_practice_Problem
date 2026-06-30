/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         bool flag = false;
//         while(fast!=nullptr && fast->next!=nullptr){
//             slow = slow->next;
//             fast = fast->next->next;

//             if(slow==fast){
//                 flag = true;
//                 break;
//             }
//         }
//         if(flag==false) return NULL;
//             else{
//             ListNode* temp = head;
//             while(temp!=slow){
//                 slow=slow->next;
//                 fast=fast->next;
//             }
//             return slow;
            
//         }
//     }
// };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                ListNode* slow = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};
