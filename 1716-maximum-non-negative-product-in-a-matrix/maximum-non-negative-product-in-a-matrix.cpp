// recursion and memorization 

// class Solution {
// public:
// int m,n;
// typedef long long ll;
// int MOD=1e9+7;
// vector<vector<pair<ll,ll>>> dp;
//    pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid){
//       if(i==m-1 && j==n-1){
//         return {grid[i][j],grid[i][j]};
//       }

//       ll maxval=LLONG_MIN;
//       ll minval=LLONG_MAX;

//       if(dp[i][j]!= make_pair(LLONG_MIN,LLONG_MAX)){
//         return dp[i][j];
//       }

//       if(i+1<m){
//         auto[downmax,downmin]=solve(i+1,j,grid);
//         maxval=max({maxval,grid[i][j]*downmax,grid[i][j]*downmin});
//         minval=min({minval,grid[i][j]*downmax,grid[i][j]*downmin});
//       }

//       if(j+1<n){
//         auto[rightmax,rightmin]=solve(i,j+1,grid);
//         maxval=max({maxval,grid[i][j] *rightmax,grid[i][j] * rightmin});
//         minval=min({minval,grid[i][j] *rightmax,grid[i][j] * rightmin});
//       }
      

//       return dp[i][j]={maxval,minval};
//    }
//     int maxProductPath(vector<vector<int>>& grid) {
//         m=grid.size();
//         n=grid[0].size();
//       dp=vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX}));
//        auto[maxProd,minProd]= solve(0,0,grid);
//        return maxProd <0 ?-1:maxProd%MOD;
//     }
// };


// BOTTOM UP APPROACH

class Solution {
public: 
typedef long long ll;
int MOD=1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<pair<ll,ll>>> dp(m,vector<pair<ll,ll>>(n));

        dp[0][0]={grid[0][0],grid[0][0]};

        for(int j=1;j<n;j++){
            dp[0][j].first=dp[0][j-1].first *grid[0][j];
            dp[0][j].second=dp[0][j-1].second *grid[0][j];
        }

        for(int i=1;i<m;i++){
            dp[i][0].first=dp[i-1][0].first*grid[i][0];
             dp[i][0].second=dp[i-1][0].second*grid[i][0];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ll upmax=dp[i-1][j].first;
                ll upmin=dp[i-1][j].second;

                ll leftmax=dp[i][j-1].first;
                ll leftmin=dp[i][j-1].second;

                dp[i][j].first=max({upmax*grid[i][j],upmin*grid[i][j],leftmax*grid[i][j],leftmin*grid[i][j]});

                dp[i][j].second=min({upmax*grid[i][j],upmin*grid[i][j],leftmax*grid[i][j],leftmin*grid[i][j]});
            }
        }

        auto [maxProd,minProd]=dp[m-1][n-1];
        return maxProd<0?-1:maxProd%MOD;
    
    }
};