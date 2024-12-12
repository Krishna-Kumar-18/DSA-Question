                                                                // Done Using Sorting

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        sort(gifts.begin(), gifts.end());

        long long int n = gifts.size();

        while(k--)
        {
            gifts[n-1] = sqrt(gifts[n-1]);
            sort(gifts.begin(), gifts.end());
        }

        long long int sum = 0;

        for(auto i : gifts)
        {
            sum += i;
        }

        return sum;
    }
};







                                                                    // Using Priority Queue


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<int>pq;

        for(auto i : gifts)
        {
            pq.push(i);
        }

        int n = gifts.size();

        while(k--)
        {
            int ele = pq.top();
            pq.pop();

            ele = sqrt(ele);
            pq.push(ele);
        }

        long long int sum = 0;

        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};