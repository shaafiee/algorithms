class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> tempVec;
        vector<vector<string>> result;
        int outer = 0;
        int inner = 0;
        bool found;
        while (strs.size() > 0) {
            tempVec.clear();
            tempVec.push_back(strs[0]);
            outer = 1;
            while (outer < strs.size()) {
                found = false;
                if (strs[0].size() == strs[outer].size()) {
                    found = true;
                    int tempArray[26] = {0};
                    for (auto character: strs[0]) ++tempArray[character - 'a'];
                    for (auto character: strs[outer]) --tempArray[character - 'a'];
                    for (auto tempItem: tempArray) {
                        if (tempItem != 0) {
                            found = false;
                            break;
                        }
                    }
                }
                if (found) {
                    tempVec.push_back(strs[outer]);
                    strs.erase(strs.begin() + outer);
                    outer--;
                }
                outer++;
            }
            strs.erase(strs.begin() + 0);
            if (tempVec.size() > 0) {
                result.push_back(tempVec);
            }
        }
        return result;
    }
};
