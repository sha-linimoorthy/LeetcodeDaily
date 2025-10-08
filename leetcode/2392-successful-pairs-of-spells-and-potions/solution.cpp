class Solution {
public:
    int binarySearch(int spell, const vector<int>& potions, long long success) {
        int l = 0;
        int r = potions.size() - 1;
        while(l<=r) {
            int mid = (l+r) / 2;
            if((long long)potions[mid] * (long long)spell >=success) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return potions.size() - l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> answer;
        sort(potions.begin(), potions.end());
        int count = 0;
        for(int spell : spells){
            count = binarySearch(spell, potions, success);
            answer.push_back(count);
        }
        return answer;
    }
};
