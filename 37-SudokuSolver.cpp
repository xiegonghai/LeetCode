class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        int m= board.size();
        if(m==0)return;
        int n = board[0].size();
        if(solveSudoku_inner(board,m,n))cout<<"succeed"<<endl;
    }
    /*深度搜索,如果找到一个解则返回*/
    bool solveSudoku_inner(vector<vector<char> >  &board,int m,int n) {
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(board[i][j]=='.'){
                    for(int k=0;k<9;++k){
                        board[i][j]=k+'1';
                        char c= k+'1';
                        if(isvalid(board,i,j)&&solveSudoku_inner(board,m,n))return true;
                        board[i][j]='.';
                    }
                    return false;
                }
        return true;
    }
    /*判定当前数独格局是否有效*/
    bool isvalid(const vector<vector<char> > &b,int x,int y){
        int i,j;
        for(i=0;i<9;++i)
            if(i!=x&&b[i][y]==b[x][y])return false;
        for(j=0;j<9;++j)
            if(j!=y&&b[x][j]==b[x][y])return false;
        for(i=3*(x/3);i<3*(x/3+1);++i)
            for(j=3*(y/3);j<3*(y/3+1);++j)
                if((i!=x||j!=y)&&b[i][j]==b[x][y])return false;
        return true;
    }
};