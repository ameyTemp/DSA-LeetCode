class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        int len=0;
        map<int,int> present;
        for(int i=0;i<n;i++){
            present[nums[i]]=1;
        }
        int prev=INT_MIN;
        int ans=0;
        bool last=false;
        for(auto i:present){
            // cout<<ans<<i.first<<prev<<endl;
            if(i.second==1 and prev!=i.first-ans){
                prev=i.first;
                ans=1;
            }else if(i.second==1 and prev==i.first-ans){
                ans++;
            }
            len=max(ans,len);
        }
        return len;
    }
};