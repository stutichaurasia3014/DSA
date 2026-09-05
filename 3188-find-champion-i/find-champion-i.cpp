class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n =grid.size();
        for(int i=0;i<n;i++){
          int wins=0;
          for(int j=0;j<n;j++){
            wins +=grid[i][j];
          }

          if(wins ==n-1){
            return i;
          }
        }
        return -1;
    }
};