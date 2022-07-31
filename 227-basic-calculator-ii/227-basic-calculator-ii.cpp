class Solution {
public:
    int calculate(string str) {
        int n = str.length();
        stack<int> s;
        int currnum = 0;
        char op = '+';
        for(int i=0;i<n;i++){
            
            char num = str[i];
             // cout<<num<<endl;
            if(isdigit(num)){
                currnum = (currnum*10) + (num-'0');
                // cout<<currnum<<endl;
            }
            if(!isdigit(num) and !iswspace(num) or i==n-1){
                if(op=='-'){
                    s.push(-currnum);
                }
                else if(op=='+'){
                    // cout<<currnum<<endl;
                    s.push(currnum);
                }
                else if(op=='*'){
                    int a = s.top();
                    s.pop();
                    s.push(a*currnum);
                }
                else if(op=='/'){
                    // cout<<op<<endl;
                    int a = s.top();
                    cout<<a<<endl;
                    s.pop();
                    s.push(a/currnum);
                }
                op=num;
                currnum=0;
            } 
        }
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};