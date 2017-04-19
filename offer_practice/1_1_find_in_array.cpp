class Solution {
    public:
        bool Find(int target, vector<vector<int> > array) {
            if (array.empty())
                return false;

            bool found = false;
            int row = array.size();
            int col = array[0].size();
            int i = row - 1, j = 0;

            while ( i >= 0 && j < col )
            {
                if (array[i][j] == target)
                {
                    found = true;
                    break;
                }
                else if(array[i][j] < target)
                    ++j;
                else
                    --i;
            }

            return found;
        }
};
