class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int ind = 1;
        int i = 0;
        ans.push_back(intervals[0]);
        while(ind<n){
            if((intervals[ind][0]<=ans[i][1] and intervals[ind][0]>=ans[i][0])){
                ans[i][0] = min(ans[i][0],intervals[ind][0]);
                ans[i][1] = max(ans[i][1],intervals[ind][1]);
            }else{
                ans.push_back(intervals[ind]);
                i++;
            }
            ind++;
        }
        return ans;
    }
};