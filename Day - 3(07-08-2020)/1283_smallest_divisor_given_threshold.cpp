// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int right = *max_element(nums.begin(), nums.end());
        int left = 1;
        
        while(left<right)
        {
            int middle = (left+right)/2;
            
            int sum =0;
            for(int num: nums)
            {
                sum += (num + middle - 1)/middle;
            }
            
            if(sum > threshold)
            {
                left = middle + 1 ;
            }
            else
                right = middle;
    
            
        }
        
        return left;
    }
    
};