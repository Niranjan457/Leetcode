class Solution {

     private: bool check(int val, vector<vector<int>>&matrix,int k )
     {    int n = matrix.size();
          int m = matrix[0].size();
             int row=n-1;
             int col = 0;
             int count = 0;
             while(row>=0 && col<m)
             {
                if(matrix[row][col]<=val)
                {
                    count= count+row+1;
                    col++;
                }
                else
                {
                    row--;
                }

             }
             return count>=k;

     }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {


        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        int result = matrix[n-1][m-1];

        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,matrix,k))
            {
                result = mid;
                high=mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return result;
        
    }
};