#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//双指针法，力扣26，27

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class TwoPoint{//双指针法
public:
    int removeElement(vector<int>& nums, int val) {//27.移除元素，自己写的，时间复杂度O（n）
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
   
    int twoPointers(vector<int>& nums,int val) {//27.移除元素
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

    int removeDuplicates(vector<int>& nums) {//26.删除有序数组中的重复项
        int slowPoint = 1; 
        for (int fastPoint = 1; fastPoint < nums.size(); fastPoint++) {
            if (nums[fastPoint] != nums[fastPoint - 1]) {
                nums[slowPoint] = nums[fastPoint];
                slowPoint++;
            }
         }
         return slowPoint;
    }
 
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* fastPoint = head;
        ListNode* slowPoint = head;

        while (fastPoint != nullptr && fastPoint->next != nullptr) {
            if (fastPoint->next->val != val) {
                fastPoint = fastPoint->next;
                slowPoint = slowPoint->next;
            } else {
                fastPoint = fastPoint->next;
                slowPoint->next = fastPoint->next;
                delete fastPoint;
                fastPoint = slowPoint->next;
            }
           //cout << slowPoint->val << " -> ";
        }

        return head;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int min_count = numeric_limits<int>::max();
        int temp_count = 0;
        int sum = 0;
        bool skip_flag = false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                temp_count++;
                if (sum >= target) {
                    sum = 0;
                    if (min_count > temp_count) {
                        min_count = temp_count;
                    }
                    temp_count = 0;
                    skip_flag = true;
                    break;
                }
            }
            if (i == 0 && !skip_flag) {
                min_count = 0;
                break;
            }
            sum = 0;
            temp_count = 0;
        }
        return min_count;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
         int index = 0;
         int count = 0;
        for (int i= 1; i <= n*n; i++) {
            matrix[index][count++] = i;
            if (count % n == 0) {
                count = 0;
                index++;
            }
        }
        return matrix;
    }

};

// 生成从 start 到 end 的递增链表
ListNode* createIncreasingList(int start, int end) {
    if (start > end) return nullptr;
    ListNode* head = new ListNode(start);
    ListNode* curr = head;
    for (int i = start + 1; i <= end; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    return head;
}
// 打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
int main ()
{
    TwoPoint twoPoint;
    vector<int> arr = {5,1,3,5,10,7,4,9,2,8};
    int length = twoPoint.minSubArrayLen(15,arr);
    cout << "length = " << length << endl;
    return 0;
}
