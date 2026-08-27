class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n =friends.size();

        vector<bool> visited(n,false);
        queue<int> que;

        que.push(id);
        visited[id]=true;

        while(level--){
            int size=que.size();

            while(size--){
                int curr=que.front();
                que.pop();

                for(int friendid:friends[curr]){
                    if(!visited[friendid]){
                        visited[friendid]=true;
                        que.push(friendid);
                    }
                }
            }
        }


        unordered_map<string,int> freq;

        while(!que.empty()){
            int person=que.front();
            que.pop();

            for(string video:watchedVideos[person]){
                freq[video]++;
            }
        }
        vector<string> ans;

        for(auto &it:freq){
            ans.push_back(it.first);
        }

        sort(ans.begin(),ans.end(),[&](string& a,string& b){
            if(freq[a]==freq[b])
            return a<b;

            return freq[a]<freq[b];
        });

        return ans;
    }
};