class Solution {
public:
        vector<vector<vector<int>>> tempHolder;
        vector<vector<bool>> marked;
        vector<vector<int>> preMarked;

    bool getArea(vector<vector<int>>& grid, int& left, int &right, int& top, int& bottom, int& currentMarker, int cy, int cx) {
                
        if (preMarked[cy][cx] != currentMarker && preMarked[cy][cx] > 0) {
            return false;
        }
        if (grid[cy][cx] == 0) {
            return false;
        }
        
        if (cy < top) top = cy;
        if (cy > bottom) bottom = cy;
        if (cx < left) left = cx;
        if (cx > right) right = cx;
        
        if (grid[cy][cx] == 1) {
            preMarked[cy][cx] = currentMarker;
        }

        if (cx > 0 && grid[cy][cx - 1] == 1 && preMarked[cy][cx - 1] < 1) {
            getArea(grid, left, right, top, bottom, currentMarker, cy, cx - 1);
        }        
        if (cx < grid[cy].size() - 1 && grid[cy][cx + 1] == 1 && preMarked[cy][cx + 1] < 1) {
            getArea(grid, left, right, top, bottom, currentMarker, cy, cx + 1);
        }        
        if (cy > 0 && grid[cy - 1][cx] == 1 && preMarked[cy - 1][cx] < 1) {
            getArea(grid, left, right, top, bottom, currentMarker, cy - 1, cx);
        }        
        if (cy < grid.size() - 1 && grid[cy + 1][cx] == 1 && preMarked[cy + 1][cx] < 1) {
            getArea(grid, left, right, top, bottom, currentMarker, cy + 1, cx);
        }        
        
        return true;        
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int islandCount = 0;
        int contiguous = 0;

        if (grid.size() == 1 && grid[0].size() == 1) {
            if (grid[0][0] == 0) {
                return 0;
            } else {
                return 1;
            }
        }

        if (grid.size() == 1 && grid[0].size() == 2) {
            if (grid[0][0] == 0 && grid[0][1] == 0) {
                return 0;
            } else {
                return 1;
            }
        }
        
        if (grid.size() == 2 && grid[0].size() == 2) {
            if (grid[0][0] == 1 && grid[0][1] == 0 && grid[1][0] == 0 && grid[1][1] == 1) {
                return 1;                
            } else if (grid[0][0] == 0 && grid[0][1] == 1 && grid[1][0] == 1 && grid[1][1] == 0) {
                return 1;                
            } else if (grid[0][0] == 0 && grid[0][1] == 0 && grid[1][0] == 0 && grid[1][1] == 0) {
                return 0;
            } else {
                return 1;
            }
        }
        int row = 0;
        int col = 0;
        preMarked.resize(grid.size());
        for (int i = 0; i < preMarked.size(); i++) {
            preMarked[i].resize(grid[i].size());
        }
        int left, right, top, bottom;
        int currentMarker = 0;
        
        while (row < grid.size()) {
            bool matched = false;
            while (col < grid[row].size()) {
                if (preMarked[row][col] < 1 && grid[row][col] == 1) {
                    currentMarker++;
                    top = row;
                    bottom = row;
                    left = col;
                    right = col;

                    getArea(grid, left, right, top, bottom, currentMarker, row, col);

                    tempHolder.resize(tempHolder.size() + 1);
                    tempHolder[tempHolder.size() - 1].resize(bottom - top + 1);
                    
                    for (int i = top; i <= bottom; i++) {
                        for (int j = left; j <= right; j++) {
                            if (preMarked[i][j] == currentMarker) {
                                tempHolder[tempHolder.size() - 1][i - top].push_back(1);
                            } else {
                                tempHolder[tempHolder.size() - 1][i - top].push_back(0);
                            }
                        }
                    }
                    int incorrectRows = 0;
                    matched = false;
                    if (tempHolder.size() > 1) {
                        for (int i = 0; i < tempHolder.size() - 1; i++) {
                            if (tempHolder[i].size() == tempHolder[tempHolder.size() - 1].size() && tempHolder[i][0].size() == tempHolder[tempHolder.size() - 1][0].size()) {
                                incorrectRows = 0;
                                for (int j = 0; j < tempHolder[i].size(); j++) {
                                        for (int m = 0; m < tempHolder[i][j].size(); m++) {
                                            if (tempHolder[i][j][m] != tempHolder[tempHolder.size() - 1][j][m]) {
                                                incorrectRows++;
                                            }
                                        }
                                }
                                if (incorrectRows == 0) {
                                    matched = true;
                                    break;
                                }
                            }
                        }
                        if (matched) {
                            tempHolder.erase(tempHolder.begin() + (tempHolder.size() - 1));
                        }
                    }
                        
                }
                col++;
            }
            row++;
            col = 0;
        }
        return tempHolder.size();
    }
};
