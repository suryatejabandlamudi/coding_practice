// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int cur = 0;
        int prev = 0;
        int prev2 = 0;        
        int startIndex = 0;
        
        while(i < n){
            cur = nums[i];
            startIndex = i - 1;
            while(i < n - 1 && nums[i] == nums[i+1]) cur += nums[i++];  
            
            if(startIndex >= 0 && nums[i] > nums[startIndex] + 1) cur += prev;
            else cur = max(cur + prev2, prev);            
            
            prev2 = prev;
            prev = cur;
            i++;
        }    
        return cur;     
    }
    
};