***************************************************************************************************************** Approach-01 (Recursion + Memoisation(i,j,k)) ***************************************************************************************************************************
class Solution
{
    public:
        int m, n, p;
    int t[101][101][201];
    bool solve(string s1, string s2, string s3, int i, int j, int k)
    {
        if (i == m && j == n && k == p)
        {
            return true;
        }
        if (k >= p)
        {
            return false;
        }

        if (t[i][j][k] != -1)
        {
            return t[i][j][k];
        }

        bool result = false;

        if (i < m && s1[i] == s3[k])
        {
            result = solve(s1, s2, s3, i + 1, j, k + 1);
        }

        if (result == true) return t[i][j][k] = true;

        if (j < n && s2[j] == s3[k])
        {
            result = solve(s1, s2, s3, i, j + 1, k + 1);
        }

        return t[i][j][k] = result;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        memset(t, -1, sizeof(t));
        m = s1.length();
        n = s2.length();
        p = s3.length();

        if ((m + n) != p)
        {
            return false;
        }

        return solve(s1, s2, s3, 0, 0, 0);
    }
};

***************************************************************************************************************** Approach-02 (Recursion + Memoisation (i,j)) ***************************************************************************************************************************
class Solution
{
    public:
        int m, n, p;
    int t[101][101];
    bool solve(string s1, string s2, string s3, int i, int j)
    {
        if (i == m && j == n && i+j == p)
        {
            return true;
        }
        if (i+j >= p)
        {
            return false;
        }

        if (t[i][j] != -1)
        {
            return t[i][j];
        }

        bool result = false;

        if (i < m && s1[i] == s3[i+j])
        {
            result = solve(s1, s2, s3, i + 1, j);
        }

        if (result == true) return t[i][j] = true;

        if (j < n && s2[j] == s3[i+j])
        {
            result = solve(s1, s2, s3, i, j + 1);
        }

        return t[i][j] = result;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        memset(t, -1, sizeof(t));
        m = s1.length();
        n = s2.length();
        p = s3.length();

        if ((m + n) != p)
        {
            return false;
        }

        return solve(s1, s2, s3, 0, 0);
    }
};
