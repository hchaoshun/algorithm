class Solution {
public:
     #define MAX_LEN (sizeof(int) * 8)
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2) return;
        int XOR = data[0];
        for (int i = 1; i < data.size(); i++) {
            XOR ^= data[i];
        }
        
        int tmp = 1, index = 0;
        for (; index < MAX_LEN; index++) {
            // == 优先级高于&
            if ((XOR & tmp) == tmp)
                break;
            tmp <<= 1;
        }
        if (index == MAX_LEN) return;
        *num1 = 0, *num2 = 0;
        for (int i = 0; i < data.size(); i++) {
            if (IS_BIT(data[i], index) == 1)
                *num1 ^= data[i];
            else 
                *num2 ^= data[i];
        }
    }
    
private:
    bool IS_BIT(int num, int index) {
        num >>= index;
        return (num & 1 == 1);
    }
    
};

