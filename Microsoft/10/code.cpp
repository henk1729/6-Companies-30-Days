class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> numsRef=nums;
        sort(nums.begin(), nums.end());
        int l=nums.size(), r=-1;
        for (int i=0; i<nums.size(); i++){
            if(nums[i]!=numsRef[i]){
                l=i;
                break;
            }
        }
        for (int i=0; i<nums.size(); i++){
            if(nums[nums.size()-1-i]!=numsRef[nums.size()-1-i]){
                r=nums.size()-1-i;
                break;
            }
        }

        return max(0, r-l+1);
    }
};
