class Solution {
public:
    //Non Dynamic Programming Solution
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            int l = i,r=i;
            //for odd length palindromes
            while(l>=0 and r<n and s[l]==s[r]){
                count++;
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 and r<n and s[l]==s[r]){
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
    };