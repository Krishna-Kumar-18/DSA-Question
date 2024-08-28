class Solution {
  public:
    int countNodesinLoop(struct Node *head) 
    {
        Node* slow = head;
        Node* fast = head->next;
        
        while(slow!=fast)
        {
            if(fast==NULL || fast->next==NULL)
            {
                return 0;
            }
            else 
            {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        
        int ans = 0;
        fast = fast->next;
        ans++;
        
        while(slow!=fast)
        {
            ans++;
            fast = fast->next;
        }
        
        return ans;
    }
};