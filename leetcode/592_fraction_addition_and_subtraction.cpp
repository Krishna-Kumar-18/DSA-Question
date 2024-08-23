class Solution {
public:
    string fractionAddition(string expression) 
    {
        int n = expression.length();
        int i = 0;

        int nume = 0;
        int deno = 1;

        while(i<n)
        {
            int curNume = 0;
            int curDeno = 0;

            bool isNeg = {expression[i] == '-'};

            if(expression[i]=='+' || expression[i]=='-')
            {
                i++;
            }

            while(i<n && isdigit(expression[i]))
            {
                int val = expression[i]-'0';
                curNume = (curNume*10) + val;
                i++;
            }

            i++;
            while(i<n && isdigit(expression[i]))
            {
                int val = expression[i]-'0';
                curDeno = (curDeno*10) + val;
                i++;
            }

            if(isNeg)
            {
                curNume *= -1;
            }

            nume = (nume*curDeno) + (deno*curNume);
            deno = deno*curDeno;
        }

        int gcd = abs(__gcd(nume, deno));

        nume /= gcd;
        deno /= gcd;

        return to_string(nume) + "/" + to_string(deno);
    }
};