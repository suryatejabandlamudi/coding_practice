// https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0)
            return 1;
        
        int res = 0;
        int memory[n+1];
        memory[0] = 0;
        memory[1] = 10;
        res += memory[1];
        for(int i = 2; i<=n; i++)
        {
            if(i==2)
                memory[i] = (memory[i-1]-1) * (10-i+1);
            else
                 memory[i]= (memory[i-1] * (10-i+1));
            res += memory[i];
        }
        return res;
    }
};