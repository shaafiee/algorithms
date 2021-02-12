class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        if (s.size() == 0 && t.size() == 0) {
            return true;
        }
        if (s.size() == 1 && t.size() == 1) {
            if (s[0] == t[0]) {
                return true;
            }
        }
        //int matchesFound = 0;
        vector<unsigned char> sweight;
        vector<unsigned char> tweight;
        //for (int i = 0; i < 123; i++) {
        //    sweight.push_back(i);
        //    tweight.push_back(i);
        //}
        //bool accounted;
        sweight.resize(124);
        tweight.resize(124);
        for (int i = 0; i < s.size(); i++) {

            sweight[s[i]]++;           
            tweight[t[i]]++;           
        }
        for (int i = 97; i < 123; i++) {
            if (sweight[i] != tweight[i]) {
                return false;
            }
        }
        
        return true;
    }

};
