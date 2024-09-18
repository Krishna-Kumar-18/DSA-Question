class Solution {
public:
    static bool myComp(int &a, int &b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);

        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) 
    {
    //     auto myComp = [](int &a, int &b)
    //     {
    //         string s1 = to_string(a);
    //         string s2 = to_string(b);

    //         return s1+s2>s2+s1;
    //     };

        sort(nums.begin(), nums.end(), myComp);

        string ans = "";

        int count = 0;
        for(auto i : nums)
        {
            ans += to_string(i);
            if(i==0)
            {
                count++;
            }
        }

        if(count==nums.size())
        {
            return "0";
        }

        return ans;
    }
};


                        // using Lambda Function

class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        auto myComp = [](int &a, int &b)
        {
            string s1 = to_string(a);
            string s2 = to_string(b);

            return s1+s2>s2+s1;
        };

        sort(nums.begin(), nums.end(), myComp);

        string ans = "";

        int count = 0;
        for(auto i : nums)
        {
            ans += to_string(i);
            if(i==0)
            {
                count++;
            }
        }

        if(count==nums.size())
        {
            return "0";
        }

        return ans;
    }
};