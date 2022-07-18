class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> arr;
        int len = tasks.size();
        for(int i=0;i<len;i++){
             arr[tasks[i]]++;
        }
        int count=0;  //max count
        int c=0;      //elements with max count
        for(auto i:arr){
            if(i.second>count)
                count=i.second;
        }
        for(auto i:arr){
            if(i.second==count)
                c++;
        }
        int ans = count*c;
        // cout<<ans<<endl;
        // cout<<(n-c+1)*(count-1)<<endl;
        if(c-1<n)
            ans+=(n-c+1)*(count-1);
        return max(ans,len);
    }
};