class Solution {
  public:
    int getMiddle(Node* head) 
    {
        Node* temp = head;
        
        int len = 0;
        while(temp!=NULL)
        {
            temp = temp->next;
            len++;
        }
        
        
        len = len/2;
        
        while(len--)
        {
            head = head->next;
        }
        
        return head->data;
    }
};