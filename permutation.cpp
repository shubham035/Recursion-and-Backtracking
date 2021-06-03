#include<bits/stdc++.h>
using namespace std;

void solve(string s , int i){
    if(s[i]=='\0'){
        cout<<s<<",";
        return;
    }
    for(int j=i;j<s.size();j++){
        swap(s[i],s[j]);
        solve(s,i+1);

        // backtracking
        swap(s[i],s[j]);
    }

}

int main(){

    string s;
    cin>>s;

    solve(s,0);

    return 0;
}








// leetcode submission:
// 46. Permutations

class Solution {
    
    vector<vector<int> >ans;
    
    void solve(vector<int>&v, int i){
        
        if(i==v.size()){
            ans.push_back(v);
            return;
        }
        
        for(int j=i;j<v.size();j++){
            swap(v[i],v[j]);
            solve(v,i+1);
            // backtracking process since array is pass by refrence array gets changed after
            // function call solve() so now to work as recursion tree suggests we must 
            // redo the changes we had done 
            swap(v[i],v[j]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        ans.clear();
        solve(nums,0);
        return ans;
    }
};


