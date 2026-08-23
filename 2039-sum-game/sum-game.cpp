class Solution {
public:
    bool sumGame(string num) {
        int n =num.size();

        int leftsum=0,rightsum=0;
        int leftQ=0,rightQ=0;

        for(int i=0;i<n/2;i++){
           if(num[i]=='?')
           leftQ++;
           else
           leftsum +=num[i] -'0';
        }

         for(int i=n/2;i<n;i++){
           if(num[i]=='?')
           rightQ++;
           else
           rightsum +=num[i] -'0';
        }

        if((leftQ +rightQ) %2)
        return true;

        return leftsum-rightsum !=(rightQ-leftQ) *9/2;
    }
};