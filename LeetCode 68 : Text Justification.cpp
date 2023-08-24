class Solution
{
    public:
        int MAX_WIDTH;
    string findLine(int i, int j, int fixed_space, int extra_space, vector<string> &words)
    {
        string s;

        for (int k = i; k < j; k++)
        {
            s += words[k];

            if (k == j - 1)
            {
                continue;
            }

            for (int j = 0; j < fixed_space; j++)
            {
                s += " ";
            }

            if (extra_space > 0)
            {
                s += " ";
                extra_space--;
            }
        }

        while (s.length() < MAX_WIDTH)
        {
            s += " ";
        }

        return s;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        MAX_WIDTH = maxWidth;
        int n = words.size();
        vector<string> result;

        int i = 0;
        while (i < n)
        {
            int letterCount = words[i].length();
            int j = i + 1;
            int spacesCount = 0;

            while (j < n && letterCount + words[j].length() + 1 + spacesCount <= maxWidth)
            {
                letterCount += words[j].length();
                spacesCount += 1;
                j++;
            }

            int remaining_spaces = maxWidth - letterCount;

            int fixed_space = spacesCount == 0 ? 0 : remaining_spaces / spacesCount;
            int extra_space = spacesCount == 0 ? 0 : remaining_spaces % spacesCount;

            if (j == n)	// means last line 
            {
                fixed_space = 1;
                extra_space = 0;
            }

            result.push_back(findLine(i, j, fixed_space, extra_space, words));
            i = j;
        }

        return result;
    }
};
