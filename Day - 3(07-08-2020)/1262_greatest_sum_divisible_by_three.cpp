// https://leetcode.com/problems/greatest-sum-divisible-by-three/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        vector<int> memory(3,0);
        vector<int> memory_copy(3,0);
        
        for(int i=0; i<nums.size(); i++)
        {
            memory_copy = memory;
            for(int sum: memory_copy)
                memory[(nums[i] + sum) % 3] = max((nums[i]+sum) , memory[(nums[i] + sum) % 3]);
        }
        return memory[0]; 
    }
};