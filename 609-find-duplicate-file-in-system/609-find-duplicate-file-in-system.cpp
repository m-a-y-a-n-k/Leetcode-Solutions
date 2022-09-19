class Solution
{
    public:
        vector<vector < string>> findDuplicate(vector<string> &paths)
        {
            vector<vector < string>> dups;
            unordered_map<string, vector < string>> same;

            for (string path: paths)
            {

                stringstream stream(path);
                string s, dir;
                getline(stream, dir, ' ');
                while (getline(stream, s, ' '))
                {
                    int cs = s.find('('), ce = s.find(')');
                    string loc = dir + '/' + s.substr(0, cs);
                    string content = s.substr(cs + 1, ce - cs - 1);
                    same[content].push_back(loc);
                }
            }

            for (auto[content, files]: same)
            {
                if (files.size() > 1)
                {
                    dups.push_back(files);
                }
            }

            return dups;
        }
};