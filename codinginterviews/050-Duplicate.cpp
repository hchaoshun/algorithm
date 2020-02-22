//要做到o(n)的时间复杂度使用hash表，用空间换时间
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        bool result = false;
        *duplication = -1;
        unordered_map<int, int> num_count;
        for (int i = 0; i < length; i++) {
            num_count[numbers[i]]++;
            if (num_count[numbers[i]] == 2) {
                result = true;
                *duplication = numbers[i];
                break;
            }
        }
        return result;
    }
};
