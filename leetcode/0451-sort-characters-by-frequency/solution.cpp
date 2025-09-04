class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c: s)
        {
            mp[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(const auto& item: mp)
        {
            pq.push({item.second, item.first});
        }
        string result = "";

        while(!pq.empty())
        {
            auto [freq, c] = pq.top();
            pq.pop();
            result.append(freq, c);
        }

        return result;
    }
};
