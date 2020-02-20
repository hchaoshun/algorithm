//静态计数器
class Assist {
public:
    Assist() {
        n++;
        sum += n;
    }
    
    static void Reset() {
        n = 0;
        sum = 0;
    }
    
    static int GetSum() {
        return sum;
    }
private:
    static int sum;
    static int n;
};

int Assist::sum = 0;
int Assist::n = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Assist::Reset();
        Assist *ptr = new Assist[n];
        delete []ptr;
        return Assist::GetSum();
    }
};
