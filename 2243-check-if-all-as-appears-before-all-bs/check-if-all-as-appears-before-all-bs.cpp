class Solution {
public:
    bool checkString(string s) {
        bool findB=false;

        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                findB=true;
            }

            if(s[i]=='a' && findB){
                return false;
            }
        }
        return true;
    }
};