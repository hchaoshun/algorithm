class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if (str.size() == 0 || str.size() > 9) return result;
        sort(str.begin(), str.end());
        do {
            result.push_back(str);
        } while (my_permutation(str.begin(), str.end()));
        auto iter = unique(result.begin(), result.end());
        result.erase(iter, result.end());
        return result;
    }

private:
    template <typename Iter>
    static bool my_permutation(Iter begin, Iter end) {
        const auto rbegin = reverse_iterator<Iter>(end);
        const auto rend = reverse_iterator<Iter>(begin);
        
        auto pivot = next(rbegin);
        while (pivot != rend && *pivot >= *prev(pivot)) ++pivot;
        if (pivot == rend) {
            reverse(rbegin, rend);
            return false;
        }
        
        auto change = find_if(rbegin, pivot, [pivot](const int c) {
            return c > *pivot;
        });
        swap(*pivot, *change);
        reverse(rbegin, pivot);
        return true;
    }
};
