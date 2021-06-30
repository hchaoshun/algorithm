//堆排序策略
class Solution {
public:
    void Insert(int num) {
        //偶数插入min_n，奇数插入max_n
        if (((max_n.size() + min_n.size()) & 1) == 0) {
            //如果插入的元素比大顶堆堆顶的元素小，说明此元素属于max_n，此时应该插入
            //大顶堆，然后将大顶堆堆顶元素弹出插入min_n.
            //否者此元素属于min_n，直接插入min_n即可
            if (max_n.size() > 0 && num < max_n[0]) {
                max_n.push_back(num);
                push_heap(max_n.begin(), max_n.end(), less<int>());
                num = max_n[0];
                pop_heap(max_n.begin(), max_n.end(), less<int>());
                max_n.pop_back();
            }
            min_n.push_back(num);
            push_heap(min_n.begin(), min_n.end(), greater<int>());
        } else {
             //如果插入的元素比小顶堆堆顶的元素大，说明此元素属于min_n，此时应该插入
            //小顶堆，然后将小顶堆堆顶元素弹出插入max_n.
            //否者此元素属于max_n，直接插入max_n即可
            if (min_n.size() > 0 && num > min_n[0]) {
                min_n.push_back(num);
                push_heap(min_n.begin(), min_n.end(), greater<int>());
                num = min_n[0];
                pop_heap(min_n.begin(), min_n.end(), greater<int>());
                min_n.pop_back();
            }
            max_n.push_back(num);
            push_heap(max_n.begin(), max_n.end(), less<int>());
        }
    }

    double GetMedian() { 
        if (((max_n.size() + min_n.size()) & 1) == 0) {
            return (max_n[0] + min_n[0]) / 2.0;
        } else {
            return min_n[0] * 1.0;
        }
    }
protected:
    //规定 0 <= min_n.size() - max_n.size() <= 1
    //前n/2部分所有元素小于后n/2部分
    vector<int> max_n; //前n/2部分大顶堆
    vector<int> min_n; //后n/2部分小顶堆

};

class Solution {
public:
    void Insert(int num) {
        if ((q1.size() + q2.size()) & 1 == 1) {
            if (num < q2.top()) {
                q1.push(num);
            } else {
                q1.push(q2.top());
                q2.pop();
                q2.push(num);
            }
        } else {
            if (q1.empty() || num > q1.top()) {
                q2.push(num);
            } else {
                q2.push(q1.top());
                q1.pop();
                q1.push(num);
            }
        }
    }

    double GetMedian() {
        if ((q1.size() + q2.size()) & 1 == 1) {
            return q2.top();
        } else {
            return (q1.top() + q2.top()) * 1.0 / 2;
        }
    }

private:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
};
