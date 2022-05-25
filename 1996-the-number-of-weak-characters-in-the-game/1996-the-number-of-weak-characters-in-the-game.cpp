class Solution {
public:
    static bool comparator(vector<int>& a,vector<int>& b){
        return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(),properties.end(),comparator);
        vector<int> res;
        res.push_back(properties[0][1]);
        int count = 0;
        int maxNum = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(properties[i][1]<maxNum)
                count++;
            maxNum = max(maxNum,properties[i][1]);
        }
        return count;
    }
};