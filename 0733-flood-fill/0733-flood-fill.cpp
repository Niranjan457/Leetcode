class Solution {
     private:
     void dfs(int r, int c , vector<vector<int>>&ans,vector<vector<int>>&image,int initial_color,int color,int*delr,int*delc)
     {       int n = image.size();
             int m = image[0].size();
               ans[r][c]=color;

              //travers all the neighbours

              for(int i=0;i<4;i++)
              {
                int neighr=r+delr[i];
                int neighc=c+delc[i];
                if(neighr>=0 && neighr<n && neighc>=0 && neighc<m && image[neighr][neighc]==initial_color && ans[neighr][neighc]!=color)
                {
                    dfs(neighr,neighc,ans,image,initial_color,color,delr,delc);
                }
              }


     }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int initial_color=image[sr][sc];
        vector<vector<int>>ans=image;

           int delr[]={-1,1,0,0};
           int delc[]={0,0,-1,1};
        dfs(sr,sc,ans,image,initial_color,color,delr,delc);
        return ans;
    }
    //tc : O(n*m) *4 
    //sc: O(n*m)+O(n*m)
};