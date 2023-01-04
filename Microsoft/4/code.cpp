class Solution {
public:
    long long maxRotateFunction(vector<int>& nums) {
        long long totSum=0, maxSum=0, currSum=0;
        for(int i=0; i<nums.size(); i++){
            totSum+=nums[i];
            maxSum+=(i*nums[i]);
        }
        currSum=maxSum;

        for(int i=1; i<nums.size(); i++){
            currSum=currSum-totSum+nums.size()*nums[i-1];
            if(maxSum<currSum) maxSum=currSum;
        }

        return maxSum;
    }
};
