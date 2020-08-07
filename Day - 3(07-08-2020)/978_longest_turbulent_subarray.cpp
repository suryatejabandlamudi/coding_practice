// https://leetcode.com/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        
        
        int max_len = 1, curr_len =1;
        bool turbulent  = true;
        if(A.size()==1)
            return 1;
        
        for(int i=1; i< A.size(); i++)
        {
            if(A[i] > A[i-1])
            {
                if(i==1 || A[i-1] < A[i-2])
                {
                    curr_len++;
                }
                else
                    curr_len = 2;
            }
            
            else if(A[i] < A[i-1])
            {
                if(i==1 || A[i-1] > A[i-2])
                {
                    curr_len++;
                }
                else
                    curr_len = 2;
            }
            
            else if(A[i] == A[i-1])
                curr_len = 1;
            
            if(max_len < curr_len)
                max_len=curr_len;
            // cout<<"flag = "<<flag<<" prev_flag = "<<prev_flag;
            //cout<<" curr_len = "<<curr_len<<" Ai ="<<A[i]<<" Ai-1 ="<<A[i-1]<<endl;
        }
        
        return max_len;
        
        
    }
};