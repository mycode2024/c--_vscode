#include <iostream>
#include <vector>
using namespace std;

class TwoPoint{//27.移除数据
public:
    int removeElement(vector<int>& nums, int val) {//自己写的，时间复杂度O（n）
        if (nums.empty()) return 0; // 处理空数组
        
        auto begin_ = nums.begin();
        auto end_ = nums.end() - 1; // 指向最后一个元素
        
        while (begin_ <= end_) {
            if (*begin_ == val) {
                if (*end_ != val) {
                    swap(*begin_, *end_); // 交换元素
                    begin_++;
                    end_--;
                } else {
                    end_--; // 右指针左移
                }
            } else {
                begin_++; // 左指针右移
            }
        }
        
        return begin_ - nums.begin(); // 计算有效长度
    }
   
    int twoPointers(vector<int>& nums,int val) {//双指针法
        int num = nums.size();
        int slowPoint = 0;
        for (int fastPoint = 0; fastPoint < num; fastPoint++) {
            if (nums[fastPoint] != val) {
                nums[slowPoint] = nums[fastPoint];
                slowPoint++;
            }
        }
        return slowPoint;
    }
};

void demo () {
    TwoPoint temp;
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    int index = temp.twoPointers(vec, 5);
    
    cout << "index=" << index << endl;
}

int main ()
{
    return 0;
}
