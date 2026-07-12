class Solution {
public:
    int rows , cols ;
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int index){
        if(index == word.size())
        return true;
        

        if(row<0 || col<0 || row>=rows || col >= cols)
        return false;

        if(board[row][col]!=word[index])
        return false;

        char temp = board[row][col];
        board[row][col] = '#';
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int k = 0; k< 4; k++){
            int nr = row+dr[k];
            int nc = col + dc[k];

            if(dfs(board, word , nr , nc , index+1))
            return true;

        }

        board[row][col] = temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
         rows= board.size();
         cols = board[0].size();
        for(int i =0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(dfs( board , word , i , j ,0))
                return true;
            }
        }

        return false ;
        
    }
};