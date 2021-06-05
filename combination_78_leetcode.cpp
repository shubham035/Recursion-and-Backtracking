// 78 LEETCODE combination
class Solution {
    vector<vector<int>> v;
    
    void solve(vector<int> &nums, vector<int> output,int i,int n ){
        
        // base case 
            if(i==n){
                v.push_back(output);
                return;
            }
        // recursive  block
        vector<int> op1=output;
        vector<int> op2=output;
        op1.push_back(nums[i]);
        
        solve(nums,op1,i+1,n);
        solve(nums,op2,i+1,n);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        int n=nums.size();
        
        solve(nums,output,0,n);
        return v;
    }
};