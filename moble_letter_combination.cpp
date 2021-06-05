// 17. Letter Combinations of a Phone Number
// Leetcode

class Solution {
    unordered_map<char,string> mp;
    
    vector<string> v;
    int n;
    void solve(string digits , string output){
        
        // base case:
        if(digits==""){
            // we have to discard the cases where the length of output is not n as we have 
            // put n digits so we must got n charcters
            if(output.length()==n)
                v.push_back(output);
            return;
        }
        // recursive:
        vector<string> all_combination;
        all_combination.push_back(output);
        
        string op1=output;
        // all combination  of string possible are stored in all_combination
        // make every string possible store.
        for(auto x:mp[digits[0]]){
            string temp=op1;
            temp.push_back(x);
            all_combination.push_back(temp);
        }
        // delete the 0th index:
        digits.erase(0,1);
        for(auto every_str:all_combination){
            solve(digits,every_str);
        }
        
    }
    
public:
    vector<string> letterCombinations(string digits) {
       n=digits.size();
        if(n==0) return {};
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        string output="";
        
        solve(digits,output);
        return v;
    }
};