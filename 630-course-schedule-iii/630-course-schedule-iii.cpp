class Solution {
public:
    static bool comparator(vector<int> v1,vector<int> v2){
        return v1[1]<v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        sort(courses.begin(), courses.end(),comparator);
        priority_queue<int> q;
        int sum = 0;
        for(auto i : courses) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};