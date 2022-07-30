class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> m(n);
        m[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>m[i+1]){
                m[i]=prices[i];
            }else{
                m[i]=m[i+1];
            }
            // cout<<m[i]<<endl;
        }
        int maxPro = 0;
        for(int i=0;i<n;i++){
            maxPro = max(maxPro,m[i]-prices[i]);
            // cout<<m[i]-prices[i]<<endl;
        }
        return maxPro;
    }
};