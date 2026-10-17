class Solution {
public:
  int digitSum(int num){
    int sum=0;
    while(num>0){
        sum +=num%10;
        num/=10;
    }
    return sum;
  }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++){
            arr.push_back({digitSum(nums[i]),i});
        }

        sort(arr.begin(),arr.end(),[&](auto a,auto b){
           if(a.first !=b.first){
            return a.first<b.first;
           }
           return nums[a.second] <nums[b.second];
        });

        vector<bool> visited(n,false);
        int swaps=0;

        for(int i=0;i<n;i++){
            if(visited[i] || arr[i].second==i){
                continue;
            }
            int cyclesize=0;
            int j=i;

            while(!visited[j]){
                visited[j]=true;
                j=arr[j].second;
                cyclesize++;
            }
            swaps +=cyclesize-1;
        }
        return swaps;

    }
};