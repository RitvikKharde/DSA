class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int sum=0;
        if(row==0 && col==0){
            return mat[0][0];
        }
        for(int i=0;i<row;i++){
             //Primary diagonal
            sum+=mat[i][i];
            //Secondary diagonal
            sum += mat[i][row - 1 - i];
        }
        if(row%2!=0){
        sum=sum-mat[row/2][col/2];}
        
return sum;
    }
};