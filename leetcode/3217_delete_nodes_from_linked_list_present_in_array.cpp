class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        map<int, int>mp;

        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        ListNode* temp = head;
        ListNode* newHead = temp;
        ListNode* prev = NULL;
        while(temp && mp[temp->val]>0)
        {
            prev = temp;
            temp = temp->next;
        }
        newHead = temp;

        while(temp)
        {
            if(mp[temp->val]>0)
            {
                prev->next = temp->next;
                temp = temp->next;
            }
            else 
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return newHead;
    }
};