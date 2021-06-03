// 52. N-Queens II LEETCODE

class Solution {
    
    int cnt=0;
    
bool isSafe(vector<vector<int>> & board , int i, int j, int n){
    
    if(i>=n || j>=n) return false;
    
    // search column;
    for(int row=0;row<i;row++){
        if(board[row][j]==1) return false;
    }
    
    // check for left diagonal
    int x=i;
    int y=j;
    
    while(x>=0 && y>=0){
        if(board[x][y]==1) return false;
        
        x--;
        y--;
    }
    
    // check for right diagonal
    
    x=i;
    y=j;
    
    while(x>=0 && y<n){
        
        if(board[x][y]==1) return false;
        x--;
        y++;
    }
    
    return true;
}
    
  bool  solveNQueen(vector<vector<int>> &board, int i, int n){
      
      // base case
      if(i==n){
          cnt++;
          return false;
      }
      
      // recursive case 
      
      for(int j=0;j<n;j++){
          
          if(isSafe(board,i,j,n)){
              // assumption
              board[i][j]=1;
              bool isPossible=solveNQueen(board,i+1,n);
              
              if(isPossible) return true;
              
              // backtrack
              board[i][j]=0;
          }
      }
      
      return false;
      
  } 
    
public:
    int totalNQueens(int n) {
        cnt=0;
        
        vector<vector<int>> board;
        for(int i=0;i<n;i++){
            vector<int> t(n,0);
            board.push_back(t);
        }
        
        solveNQueen(board,0,n);
        
        return cnt;
    }
};