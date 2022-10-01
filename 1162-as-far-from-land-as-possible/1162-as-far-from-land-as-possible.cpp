typedef pair<int, int> pi;

class Solution
{
    int dirs[4][2] = {
		{ -1, 0 },
        { 1,
            0 },
        { 0,
            -1 },
        { 0,
            1 }
    };

    bool safe(int x, int y, int n, int m)
    {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    public:
        int maxDistance(vector<vector < int>> &grid)
        {
            int d = 0, md = -1;
            int n = size(grid), m = size(grid[0]);
            queue<vector < int>> Q;

            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < m; ++c)
                {
                    if (grid[r][c])
                    {
                        grid[r][c] = -1;
                        Q.push({ r,
                            c });
                    }
                    else
                    {
                        grid[r][c] = INT_MAX;
                    }
                }
            }

            while (!Q.empty())
            {
                int s = Q.size();
                d++;

                for (int x = 0; x < s; ++x)
                {
                    auto P = Q.front();
                    Q.pop();
                    for (auto &dir: dirs)
                    {
                        int i = P[0] + dir[0],
                            j = P[1] + dir[1];
                        if (safe(i, j, n, m) &&
                            grid[i][j] != -1 &&
                            grid[i][j] > d
                       )
                        {
                            Q.push({ i, j });
                            grid[i][j] = d;
                        }
                    }
                }
            }

            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < m; ++c)
                {
                    if (grid[r][c] != -1)
                    {
                        md = max(md, grid[r][c]);
                    }
                }
            }

            return md == INT_MAX ? -1 : md;
        }
};