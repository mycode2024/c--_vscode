// 203.移除链表元素  
//https://leetcode.cn/problems/remove-linked-list-elements/

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Remove_linked_list_elements{
public:
    ListNode* removeElements(ListNode* head, int val) {

        while (head != nullptr && head->val == val) {
            ListNode* point_node = head;
            head = head->next;
            delete point_node;
            point_node = nullptr;
        }
        
        ListNode* temp_node = head;
        while (temp_node != nullptr && temp_node->next != nullptr) {
            if (temp_node->next->val == val) {
                ListNode* point_node = temp_node->next;
                temp_node->next = point_node->next;
                delete point_node;
                point_node = nullptr;
            } else {
                temp_node = temp_node->next;
            }
        }
        return head;
    }
};