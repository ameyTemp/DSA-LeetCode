class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<int> maxCoins(amount+1,amount+1);
        //base case
        maxCoins[0]=0;
        //starting from 0 amount and calculating for final amount
        //bottom-up appraoch
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    maxCoins[i]=min(maxCoins[i],maxCoins[i-coins[j]]+1);
                }
            }
        }
        if(maxCoins[amount]>amount)
            return -1;
        return maxCoins[amount];
        
    }
};