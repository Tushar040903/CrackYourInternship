
int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int area = 0;
        while(l < r) {
            int breadth = r-l;
            int h = min(height[l],height[r]);
            int currarea = h * breadth;
            area = max(area,currarea);

            if(height[l] < height[r]) l++;
            else r--;
        }

        return area;
    }