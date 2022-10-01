typedef pair<int, int> pi;

class Solution
{
    pi dirs[4] = {
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
            queue<pi> Q;
            vector<vector < int>> dp(n, vector<int> (m, INT_MAX));

            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < m; ++c)
                {
                    if (grid[r][c])
                    {
                        Q.push({ r,
                            c });
                    }
                }
            }

            while (!Q.empty())
            {
                int s = Q.size();
                d++;

                for (int x = 0; x < s; ++x)
                {
                    pi P = Q.front();
                    Q.pop();
                    for (auto &dir: dirs)
                    {
                        pi K = { P.first + dir.first,
                            P.second + dir.second
                        };
                        if (safe(K.first, K.second, n, m) &&
                            !grid[K.first][K.second] &&
                            dp[K.first][K.second] > d
                       )
                        {
                            Q.push({ K.first,
                                K.second });
                            dp[K.first][K.second] = d;
                        }
                    }
                }
            }

            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < m; ++c)
                {
                    if (!grid[r][c])
                    {
                        md = max(md, dp[r][c]);
                    }
                }
            }

            return md == INT_MAX ? -1 : md;
        }
};