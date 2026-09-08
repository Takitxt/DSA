class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int count = 0;
        for(int i =0; i < nums.size(); i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i] == nums[j]){
                    count++;
                    break;
                }

            }
        }
        if(count!=0) return true;
        return false;
    }
};