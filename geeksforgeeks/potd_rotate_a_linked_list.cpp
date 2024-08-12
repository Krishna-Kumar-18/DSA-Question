class Solution {
  public:
    Node* rotate(Node* head, int k) 
    {
        Node* temp = head;
        
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        
        temp->next = head;
        
        while(--k)
        {
            head = head->next;
        }
        
        Node* ans = head->next;
        head->next = NULL;

        return ans;
        
    }
};
