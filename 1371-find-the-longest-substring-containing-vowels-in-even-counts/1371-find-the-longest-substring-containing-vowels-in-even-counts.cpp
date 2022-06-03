class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        map<int,int> arr;
        int parity=0;       //00000 
        int ans =0;
        arr[0]=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                parity^=1<<0;
            }else if(s[i]=='e'){
                parity^=1<<1;
            }else if(s[i]=='i'){
                parity^=1<<2;
            }else if(s[i]=='o'){
                parity^=1<<3;
            }else if(s[i]=='u'){
                parity^=1<<4;
            }
            
            if(arr.count(parity)){
                ans=max(ans,i-arr[parity]);
            }else{
                arr[parity]=i;
            }
        }
        return ans;
        
    }
};