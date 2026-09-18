class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n =nums.size();

        sort(begin(nums),end(nums));

        vector<int> dp(n,1);
        vector<int> prev(n,-1);

        int last_chosen_index=0;
        int maxL=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                    if(dp[i]>maxL){
                        maxL=dp[i];
                        last_chosen_index=i;
                    }
                }
            }
        }
        vector<int> result;
        while(last_chosen_index !=-1){
            result.push_back(nums[last_chosen_index]);
            last_chosen_index=prev[last_chosen_index];
        }
        return result;
    }
};