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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* ans = new ListNode(0);
        ListNode* result = ans;

        while(head != NULL)
        {
            int count = k;
            ListNode* temp = new ListNode(0);
            ListNode* temp2 = temp;
            while(count>0 && head!=NULL)
            {
                temp->next = head;
                head = head->next;
                temp = temp->next;
                count--;
            }

            temp->next = NULL;

            if(count==0)
            {
                ListNode* curr = temp2->next;
                ListNode* prev = NULL;
                ListNode* forward;

                while(curr!=NULL)
                {
                    forward = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = forward;
                }

                while(prev!=NULL)
                {
                    ans->next = prev;
                    ans = ans->next;
                    prev = prev->next;
                }

            }
            else
            {
                ans->next = temp2->next;
                ans = ans->next;
            }
        }

        return result->next;
    }
};