class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        for(int i=0;i<cardPoints.size();i++){
            sum+=cardPoints[i];
        }
        if(n==k)
            return sum;
        int winSum=0;
        int minSum=INT_MAX;
        for(int i=0;i<n-k;i++){
            winSum+=cardPoints[i];
        }
        minSum = min(minSum,winSum);
        // cout<<minSum<<endl;
        int ind=0;
        for(int i=n-k;i<n;i++){
            winSum-=cardPoints[ind++];
            winSum+=cardPoints[i];
            minSum = min(minSum,winSum);
            // cout<<minSum<<" "<<winSum<<endl;
        }
        return sum-minSum;
    }
};  