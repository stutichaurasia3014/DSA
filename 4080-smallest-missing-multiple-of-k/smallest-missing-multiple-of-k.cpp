class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int expected=k;

        for(int num:nums){
            if(num<expected)
            continue;

            if(num==expected)
            expected +=k;

            else if(num>expected)
            break;

        }

        return expected;
    }
};