class Solution {
public:
    static bool comparator(vector<int>& a,vector<int>& b){
        return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        vector<int> res;
        sort(envelopes.begin(),envelopes.end(),comparator);
        res.push_back(envelopes[0][1]);
        int n = envelopes.size();
        for(int i=1;i<n;i++){
            if(envelopes[i][1]>res.back()){
                res.push_back(envelopes[i][1]);
            }else{
                int ind  = lower_bound(res.begin(),res.end(),envelopes[i][1])-res.begin();
                res[ind] = envelopes[i][1];
            }
        }
        return res.size();
    }
};