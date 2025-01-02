class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        vector<int>prefix;
        vector<int>ans;

        int count = 0;
        for(int i=0; i<words.size(); i++)
        {
            string temp = words[i];
            if(temp[0]=='a' || temp[0]=='e' || temp[0]=='i' || temp[0]=='o' || temp[0]=='u')
            {
                if(temp[temp.length()-1]=='a' || temp[temp.length()-1]=='e' || temp[temp.length()-1]=='i' || temp[temp.length()-1]=='o' || temp[temp.length()-1]=='u')
                {
                    count++;
                    prefix.push_back(count);
                }
                else
                {
                    prefix.push_back(count);
                }
            }
            else
            {
                prefix.push_back(count);
            }
        }

        for(int i=0; i<queries.size(); i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];

            if(start == 0)
            {
                ans.push_back(prefix[end]);
            }
            else
            {
                ans.push_back(prefix[end] - prefix[start-1]);
            }
        }

        for(auto i : prefix)
        {
            cout << i << " ";
        }
        cout << endl;

        return ans;
    }
};