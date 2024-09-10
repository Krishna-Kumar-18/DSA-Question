class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* curr = head;
        ListNode* nextNode = head->next;

        while(nextNode)
        {
            ListNode* gcd = new ListNode(__gcd(curr->val, nextNode->val));

            curr->next = gcd;
            gcd->next = nextNode;

            curr = nextNode;
            nextNode = nextNode->next;
        }
        
        return head;
    }
};