class Solution {
public:
    static bool comparator(string s1,string s2){
        return s1.length()<s2.length();
    }
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        sort(strs.begin(),strs.end(),comparator);
        int n = strs.size();    
        int len = strs[0].length();
        for(int i=0;i<len;i++){
            for(int j=1;j<n;j++){
                if(strs[0][i]!=strs[j][i])
                    return res;
            }
            res+=strs[0][i];
        }
        return res;
    }
};