struct TrieNode {
    TrieNode* children[10];
};

class Solution {
public:
    TrieNode* getTrieNode() {
        TrieNode* node = new TrieNode();

        for(int i=0; i<10; i++)
        {
            node->children[i] = nullptr;
        }

        return node;
    }

    void insert(int num, TrieNode* root)
    {
        TrieNode* crawl = root;
        string s = to_string(num);

        for(char ch : s)
        {
            int idx = ch - '0';
            if(!crawl->children[idx])
            {
                crawl->children[idx] = getTrieNode();
            }

            crawl = crawl->children[idx];
        }
    }

    int search(int num, TrieNode* root)
    {
        TrieNode* crawl = root;
        string s = to_string(num);

        int length = 0;
        for(char ch : s)
        {
            int idx = ch - '0';
            if(crawl->children[idx])
            {
                length++;
                crawl = crawl->children[idx];
            }
            else
            {
                break;
            }
        }

        return length;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        TrieNode* root = getTrieNode();

        for(int num : arr1)
        {
            insert(num, root);
        }

        int ans = 0;
        for(int num : arr2)
        {
            ans = max(ans, search(num, root));
        }

        return ans;
    }
};