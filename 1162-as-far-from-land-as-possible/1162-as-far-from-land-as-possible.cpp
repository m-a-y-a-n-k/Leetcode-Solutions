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

    public:
        int maxDistance(vector<vector < int>> &grid)
        {
            int d = 0, md = -1;
            int n = size(grid), m = size(grid[0]);
            queue<pi> Q;

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
                        int i = P.first + dir[0],
                            j = P.second + dir[1];
                        if (i < 0 || i >= n || j < 0 || j >= m)
                        {
                            continue;
                        }
                        if (grid[i][j] != -1 &&
                            grid[i][j] > d
                       )
                        {
                            Q.push({ i,
                                j });
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