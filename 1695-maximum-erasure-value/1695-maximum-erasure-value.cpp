class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> ind(10001,-1);
        int n = nums.size();
        vector<int> sums(n);
        sums[0]=nums[0];
        for(int i=1;i<n;i++){
            sums[i]=sums[i-1]+nums[i];
            // cout<<sums[i]<<endl;
        }
        int sum = 0;
        int maxsum=0;
        int latest=-1;
        for(int i=0;i<n;i++){
            if(ind[nums[i]]>latest){
                if(latest!=-1)
                    sum+=sums[latest];
                latest=ind[nums[i]];
                sum-=sums[ind[nums[i]]];
            }
            sum+=nums[i];
            ind[nums[i]]=i;
            maxsum=max(sum,maxsum);
            // cout<<sum<<" "<<maxsum<<" "<<nums[i]<<endl;
        }
        return maxsum;
    }
};