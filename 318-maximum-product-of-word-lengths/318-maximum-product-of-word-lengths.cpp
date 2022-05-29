class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans=0;
        string  count[n];
        for(int i=0;i<n;i++){
            string temp = string(26,'0'); 
            for(int j=0;j<words[i].length();j++){
                // cout<< words[i][j]-'a'<<" ";
                temp[words[i][j]-'a']='1';
            }
            count[i] = temp;
            // cout<<temp<<endl;
            // cout<<endl;
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int x=i+1;x<n;x++){
                for(int j=0;j<26;j++){
                    if(count[i][j]=='1' and count[x][j]=='1'){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    int temp=words[i].length()*words[x].length();
                    ans =  max(ans,temp);
                }
                flag=true;
            }
            
        }
        return ans;
        
    }
};