//707. 设计链表
//https://leetcode.cn/problems/design-linked-list/description/

#include <iostream>
using namespace std;

//单链表版本
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList{
public:
    MyLinkedList() {
        this->head = new ListNode();
    }
    
    int get(int index) {
        int count_index = 0;
        ListNode* temp_node = this->head;
        if (head != nullptr) {
            while (temp_node != nullptr && count_index != index) {
                temp_node = temp_node->next;
                count_index++;
            }
            if (temp_node == nullptr) {
                return -1;
            } else {
                if (count_index == index) {
                    return temp_node->val;
                }
            }
        }
        return -1;
    }
    
    void addAtHead(int val) {
        
    }
    
    void addAtTail(int val) {
        
    }
    
    void addAtIndex(int index, int val) {
        
    }
    
    void deleteAtIndex(int index) {
        
    }
private:
    ListNode* head;
    int size;
};