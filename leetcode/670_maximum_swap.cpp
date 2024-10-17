class Solution {
public:
    int maximumSwap(int num) {
        if(num<=10) return num;

        string digits=to_string(num);
        int n=digits.size();

        int maxval_idx=n-1;
        int swap_left=-1;
        int swap_right=n-1;

        for(int i=n-2;i>=0;--i){
            if(digits[maxval_idx]<digits[i]){
                maxval_idx = i;
            } else if(digits[maxval_idx]>digits[i]){
                swap_right = maxval_idx;
                swap_left = i;
            }
        }
        if(swap_left!=-1)
            swap(digits[swap_left],digits[swap_right]);
        return stoi(digits);
    }
};