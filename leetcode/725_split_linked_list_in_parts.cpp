class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*>ans; 

        ListNode* temp = head;
        int count = 0;

        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }

        int size = count/k;
        int rem = count%k;
        ListNode* prev = NULL;
        ListNode* curr = head;

        int next_start = size + (rem>0 ? 1 : 0);
        if(rem>0)
        {
            rem--;
        }

        for(int i=0; i<count; i++)
        {
            if(i==next_start)
            {
                prev->next = NULL;
                ans.push_back(curr);
                next_start += size + (rem>0 ? 1 : 0);
                if(rem>0)
                {
                    rem--;
                }
            }
            
            prev=curr;
            curr=curr->next;
            if(i==0)
            {
                ans.push_back(head);
            }
        }

        while(ans.size()<k)
        {
            ans.push_back(NULL);
        }

        return ans;
    }
};