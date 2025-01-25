class Solution {
  public:
    Node* findFirstNode(Node* head) 
    {
        Node* slow = head;
        Node* fast = head;
        
        bool flag = false;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                flag = true;
                break;
            }
        }
        
        if(flag)
        {
            Node* first_node = head;
            
            while(first_node != slow)
            {
                first_node = first_node->next;
                slow = slow->next;
            }
            
            return first_node;
        }
        
        return NULL;
    }
};