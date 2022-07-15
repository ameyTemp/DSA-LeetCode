class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i=0,j=0;
        while(i<=n and j<=n){
            while(i<n and start[i]=='_') i++;
            while(j<n  and target[j]=='_') j++;
            
            if(i==n || j==n)
                return i==n && j==n;
            
            if(start[i]!=target[j])
                return false;
            if(start[i]=='L'){
                if(j>i) return false;
            }else{
                if(j<i)  return false;
            }
            i++;
            j++;
        }
        return true;
        
    }
};