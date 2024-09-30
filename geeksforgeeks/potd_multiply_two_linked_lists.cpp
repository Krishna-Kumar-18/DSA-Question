class solution {
  public:
    long long mod = 1e9+7;
    long long multiplyTwoLists(Node *first, Node *second) 
    {
        long long num_1 = 0, num_2 = 0;
        
        while(first!=NULL)
        {
            num_1 = num_1*10 + (first->data);
            num_1 = num_1%mod;
            first = first->next;
        }
        
        while(second!=NULL)
        {
            num_2 = num_2*10 + (second->data);
            num_2 = num_2%mod;
            second = second->next;
        }
        
        long long ans = num_1*num_2;
        ans = ans%mod;
        
        return ans;
    }
};