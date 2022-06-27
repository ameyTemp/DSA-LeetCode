class Solution {
public:
    int minPartitions(string n) {
        int len = n.length();
        int ans=0;
        for(int i=0;i<len;i++){
            // cout<<n[i]-'0'<<endl;
            if(n[i]-'0'>ans)
                ans=n[i]-'0';
        }
        return ans;
    }
};