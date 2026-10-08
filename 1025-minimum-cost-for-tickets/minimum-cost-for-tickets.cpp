// class Solution {
// public:
// int dp[366];
// int solve(vector<int>& days, vector<int>& costs, int n, int i){
//     if(i>=n){
//         return 0;
//     }
    
//     if(dp[i]!=-1){
//         return dp[i];
//     }
//     int cost1=costs[0]+solve(days,costs,n,i+1);
    
//     // day2
//     int j=i;
//     int maxday=days[i]+7;
//     while(j<n && days[j]<maxday){
//         j++;
//     }
//     int cost2=costs[1]+solve(days,costs,n,j);

//     // day3 
//     j=i;
//     maxday=days[i]+30;
//     while(j<n && days[j]<maxday){
//         j++;
//     }
//     int cost3=costs[2]+solve(days,costs,n,j);

//     return dp[i]= min({cost1,cost2,cost3});

// }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n=days.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(days,costs,n,0);
//     }
// };




// BOTTOM UP APPROACH 

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        unordered_set<int> st(begin(days),end(days));

        int last_day=days.back();

        vector<int> dp(last_day+1,0);
        dp[0]=0;

        for(int i=1;i<=last_day;i++){
            if(st.find(i) == st.end()){
                dp[i]=dp[i-1];
                continue;
            }
            dp[i]=INT_MAX;

            int day1_pass=costs[0]+dp[max(i-1,0)];

            int day7_pass=costs[1]+dp[max(i-7,0)];

            int day30_pass=costs[2]+dp[max(i-30,0)];

            dp[i]=min({day1_pass,day7_pass,day30_pass});


        }
        return dp[last_day];
    }
};