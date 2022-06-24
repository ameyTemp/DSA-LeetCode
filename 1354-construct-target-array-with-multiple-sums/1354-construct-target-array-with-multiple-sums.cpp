class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> arr;
        long long sum=0;
        for(int i=0;i<target.size();i++){
            sum+=target[i];
            arr.push(target[i]);
        }
        cout<<sum<<endl;
        bool pos = true;
        while(pos){
            int temp = arr.top();
            sum -=temp;
            if(temp==1 or sum==1){
                return true;
            }
            // cout<<sum<<endl;
            if(temp<sum or sum==0 or temp%sum==0)
                return false;
            temp%=sum;
            sum+=temp;
            // cout<<newNum<<endl;
            arr.pop();
            arr.push(temp);
        }
        for(int i=0;i<target.size();i++){
            if(arr.top()!=1)
                return false;
            arr.pop();
        }
        return true;
    }
};