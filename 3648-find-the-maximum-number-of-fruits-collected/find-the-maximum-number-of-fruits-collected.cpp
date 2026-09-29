class Solution {
public:
int n;
vector<vector<int>> dp;
 int childCollect(vector<vector<int>>& fruits){
    int count=0;
    for(int i=0;i<n;i++){
        count +=fruits[i][i];
    }
    return count;
 }

 int child2Collect(int i,int j,vector<vector<int>> &fruits){
    if(i>=n||j>=n){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 0;
    }
    
    if(i==j || i>j){
        return 0;
    }
    if(dp[i][j] !=-1){
        return dp[i][j];
    }

    int bottomLeft=fruits[i][j] + child2Collect(i+1,j-1,fruits);
    int bottomDown=fruits[i][j] + child2Collect(i+1,j,fruits);
    int bottomRight=fruits[i][j] + child2Collect(i+1,j+1,fruits);

    return dp[i][j]=max({bottomLeft,bottomDown,bottomRight});
 }

  int child3Collect(int i,int j,vector<vector<int>> &fruits){
    if(i>=n||j>=n){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 0;
    }

    if(i==j || i<j){
        return 0;
    }
    if(dp[i][j] !=-1){
        return dp[i][j];
    }
    
    int bottomLeft=fruits[i][j] + child3Collect(i-1,j+1,fruits);
    int bottomDown=fruits[i][j] + child3Collect(i,j+1,fruits);
    int bottomRight=fruits[i][j] + child3Collect(i+1,j+1,fruits);

    return dp[i][j]= max({bottomLeft,bottomDown,bottomRight});
 }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        dp.resize(n,vector<int>(n,-1));

        int c1=childCollect(fruits);

        int c2=child2Collect(0,n-1,fruits);

        int c3=child3Collect(n-1,0,fruits);

        return c1+c2+c3;
    }
};