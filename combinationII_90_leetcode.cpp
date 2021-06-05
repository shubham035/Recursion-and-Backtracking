// 90. Subsets II
//  space compexity ???
//  time complexity ????

/*


To solve this problem, it is helpful to first think how many subsets are there. If there is no duplicate element, the answer is simply 2^n, where n is the number of elements. This is because you have two choices for each element, either putting it into the subset or not. So all subsets for this no-duplicate set can be easily constructed:
num of subset

(1 to 2^0) empty set is the first subset
(2^0+1 to 2^1) add the first element into subset from (1)
(2^1+1 to 2^2) add the second element into subset (1 to 2^1)
(2^2+1 to 2^3) add the third element into subset (1 to 2^2)
....
(2^(n-1)+1 to 2^n) add the nth element into subset(1 to 2^(n-1))
Then how many subsets are there if there are duplicate elements? We can treat duplicate element as a spacial element. For example, if we have duplicate elements (5, 5), instead of treating them as two elements that are duplicate, we can treat it as one special element 5, but this element has more than two choices: you can either NOT put it into the subset, or put ONE 5 into the subset, or put TWO 5s into the subset. Therefore, we are given an array (a1, a2, a3, ..., an) with each of them appearing (k1, k2, k3, ..., kn) times, the number of subset is (k1+1)(k2+1)...(kn+1). We can easily see how to write down all the subsets similar to the approach above.

*/

// My solution but i think this uses more space than the optimal one  I think so 

class Solution {
    
    set<vector<int>> s;
    
        void solve(vector<int>& nums , vector<int>& output , int i ,int n){
            
            // base case :
                if(i==n){
                    sort(output.begin(),output.end());
                    if(s.find(output)==s.end() ){
                         s.insert(output);
                    }
                   
                    return;
                }
            // recursion
            
            vector<int>op1=output;
            vector<int>op2=output;
            op1.push_back(nums[i]);
            
            solve(nums,op1,i+1,n);
            solve(nums,op2,i+1,n);
        }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> output;
        int n=nums.size();
        
        solve(nums,output,0,n);
        
        vector<vector<int>>ans;
        for(auto x: s){
            ans.push_back(x);
        }
        return ans;
    }
};