class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> count;
        int n = words.size();
        int ans=0;
        bool same=false;
        for(int i=0;i<n;i++){   
            count[words[i]]++;
        }
        for(int i=0;i<n;i++){
            if(words[i][0]==words[i][1] and count[words[i]]%2==1 and !same){
                same=true;
                count[words[i]]--;
            }
            string rev = "";
            rev+=words[i][1];
            rev+=words[i][0];
            // cout<<rev<<" "<<words[i]<<" "<<count[words[i]]<<" "<<count[rev]<<endl;
            if(count[words[i]]>0 and count[rev]>0){
                if(words[i]!=rev){
                    int minval = min(count[words[i]],count[rev]);
                    ans+=4*minval;
                    count[words[i]]-=minval;
                    count[rev]-=minval;
                }
                if(words[i]==rev and count[words[i]]!=1){
                    ans+=2*(count[words[i]] - count[words[i]]%2);
                    count[words[i]]=0;
                }
            }
        }
        if(same)
            ans+=2;
        
        return ans;
    }
};