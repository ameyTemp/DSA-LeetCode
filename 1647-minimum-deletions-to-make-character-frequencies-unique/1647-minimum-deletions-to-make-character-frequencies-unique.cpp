class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26,0);
        for(char ch:s){
            count[ch-'a']++;
        }
        unordered_map<int,int> exist;
        for(int i:count){
            if(i!=0){
                exist[i]++;
            }
        }
        int ans=0;
        sort(count.begin(),count.end());
        for(int i=25;i>=0;i--){
            // cout<<count[i]<<exist[count[i]]<<endl;
            int temp = count[i];
            if(count[i]!=0 and exist[count[i]]>1){
                while(exist[temp]>=1 and temp!=0){
                    temp--;
                    ans++;
                }
                exist[count[i]]--;
                exist[temp]++;
            }
        }
        return ans;
    }
};