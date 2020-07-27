class SubrectangleQueries {
public:
    struct record {
        int r1, c1, r2, c2, v;
    };
    vector <record> p;
    vector <vector <int>> rect;

    SubrectangleQueries(vector<vector<int>>& rectangle) {
        p.clear();
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        p.push_back((record){row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for (int i = p.size() - 1; ~i; -- i)
            if(p[i].r1 <= row && row <= p[i].r2 && p[i].c1 <= col && col <= p[i].c2)
                return p[i].v;
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
