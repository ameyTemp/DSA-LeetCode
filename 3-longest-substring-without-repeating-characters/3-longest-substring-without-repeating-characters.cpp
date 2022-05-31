class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> arr(256,-1);
        for(int i=0,j=0;i<n;i++){
            if(arr[int(s[i])]!=-1){
                j=max(j,arr[int(s[i])]+1);
            }
            arr[int(s[i])]=i;
            ans = max(ans,i-j+1);
        }
        
        return ans;
    }
};