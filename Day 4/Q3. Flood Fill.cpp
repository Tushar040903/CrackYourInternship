void dfs(int sr, int sc, vector<vector<int>>& image,int oldcolor, int newcolor) {
        if(sr<0 || sr>=image.size() || sc <0 || sc >= image[0].size() || image[sr][sc] != oldcolor || image[sr][sc] == newcolor) {
            return ;
        }
        
        image[sr][sc] = newcolor;

        dfs(sr,sc-1,image,oldcolor,newcolor);
        dfs(sr,sc+1,image,oldcolor,newcolor);
        dfs(sr-1,sc,image,oldcolor,newcolor);
        dfs(sr+1,sc,image,oldcolor,newcolor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // unordered_map< pair<int,int>, bool> visited;
        int oldcolor = image[sr][sc];
        int newcolor = color;

        dfs(sr,sc,image,oldcolor,newcolor);

        return image;
    }