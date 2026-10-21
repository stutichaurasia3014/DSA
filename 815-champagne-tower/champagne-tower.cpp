// recursion and memorization

// class Solution {
// public:
//     double dp[101][101];

//     double solve(int poured, int i, int j) {
//         if (i < 0 || j < 0 || i < j) {
//             return 0.0;
//         }

//         if (i == 0 && j == 0) {
//             return poured;
//         }

//         if (dp[i][j] != -1.0) {
//             return dp[i][j];
//         }

//         double up_left = (solve(poured, i - 1, j - 1) - 1.0) / 2.0;
//         double up_right = (solve(poured, i - 1, j) - 1.0) / 2.0;

//         if (up_left < 0.0) {
//             up_left = 0.0;
//         }

//         if (up_right < 0.0) {
//             up_right = 0.0;
//         }

//         return dp[i][j] = up_left + up_right;
//     }

//     double champagneTower(int poured, int query_row, int query_glass) {
//         for (int i = 0; i < 101; i++) {
//             for (int j = 0; j < 101; j++) {
//                 dp[i][j] = -1.0;
//             }
//         }

//         return min(1.0, solve(poured, query_row, query_glass));
//     }
// };


// bottom up approach


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(101,vector<double>(101,0.0));

        dp[0][0]=poured;

        for(int row=0;row<=query_row;row++){
            for(int col=0;col<=row;col++){
                double extra =(dp[row][col]-1)/2.0;
                if(extra >0){
                 dp[row+1][col] +=extra;
                 dp[row+1][col+1] +=extra;
                }
               
            }
        }
        return min(1.0,dp[query_row][query_glass]);
    }
};
