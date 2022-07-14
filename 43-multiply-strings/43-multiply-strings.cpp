class Solution {
public:
    string sum(vector<vector<int>> result){
        vector<int> ans = result.back();
        result.pop_back();
        vector<int> newans;
        for(vector<int> res:result){
            newans.clear();
            int carry=0;
            for(int i=0;i<ans.size() || i<res.size();i++){
                int digit1 = i<ans.size() ? ans[i] : 0;
                int digit2 = i<res.size() ? res[i] : 0;
                
                int add = digit1+digit2+carry;
                carry = add/10;
                
                newans.push_back(add%10);
            }
            if(carry){
                newans.push_back(carry);
            }
            ans=newans;
        }
        string answer;
        for(int num:ans){
            answer.push_back(num+'0');
        }
        return answer;
        
    }
    vector<int> multiplyDigit(string num1,string num2,int num){
        vector<int> result(num,0);
        int carry=0;
        for(int i=0;i<num1.length();i++){
            int multiply = (num1[i]-'0')*(num2[num]-'0')+carry;
            carry = multiply/10;
            result.push_back(multiply%10);
        }
        if(carry){
            result.push_back(carry);
        }
        return result;
    }
    
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0")
            return "0";
        vector<vector<int>> result;
        int n = num1.length();
        int m = num2.length();
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i=0;i<m;i++){
            result.push_back(multiplyDigit(num1,num2,i));
        }
        
        string ans = sum(result);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};