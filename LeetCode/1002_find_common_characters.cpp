// 1002. Find Common Characters || leet potd 5 june

class Solution {
public:
    // google amazon apple uber tripadvisor
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> map1;
        vector<string> answer;
        for (char ch : words[0]) {
            map1[ch]++;
        }
        // map<char, int>::iterator it;

        for (int j = 1; j < words.size(); j++) {
            unordered_map<char, int> map2;
            for (int i = 0; i < words[j].size(); i++) {
                char ch = words[j][i];
                map2[ch]++;
            }

            for (auto it = map1.begin(); it != map1.end();) {
                if (map2.find(it->first) != map2.end()) {
                    it->second = min(it->second, map2[it->first]);
                    ++it;
                } else {
                    it = map1.erase(it);
                }
            }
        }

         for (auto it = map1.begin(); it != map1.end(); ++it) {
            for (int i = 0; i < it->second; ++i) {
                answer.push_back(string(1, it->first));
            }
        }

        return answer;
    }
};