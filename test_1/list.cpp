#include "list.h"

//包含空头结点的链表
Node *List::create_list(vector<int>& arr)
{
    Node* head = new Node(0);
    Node* point_ = head;
    for (int i= 0; i < arr.size(); i++) {
        Node* temp_node = new Node(0);
        temp_node->val = arr[i];
        point_->next = temp_node;
        point_ = point_->next;
    }
    point_ = nullptr;
    return head;
}

void List::list_insert(Node* head, int val, int index)
{
    Node* temp_node = head;
    int count = 0;
    while (count != index-1 && temp_node->next != nullptr)
    {
        count++;
        temp_node = temp_node->next;
    }
    if (count == index - 1) {
        Node* node = new Node(val);
        node->next = temp_node->next;
        temp_node->next = node;
    } else {
        cout << "插入位置无效" << endl;
    }
}

void List::list_print(Node *head)
{
    if (head == nullptr) {
        cout << "链表无数据" <<endl;
    } else {
        Node* point_ = head->next;
        while (point_ != nullptr)
        {
            cout << point_->val << "->" ;
            point_ = point_->next;
        }
        cout << "nullptr" <<endl;
    } 
}

void List::list_destory(Node*& head)
{
    Node* pre_node = head;
    Node* next_node = (head)->next;
    while (pre_node != nullptr && next_node != nullptr) {
        delete pre_node;
        pre_node = next_node;
        next_node = next_node->next;
    }
    delete pre_node;
    head = nullptr;
}

void Bubble_Sort::solution(vector<int> &arr)
{
    int num = arr.size();
    for (int i = 1; i< num; i++) {
        for (int j = i; j < num; j++) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            } 
        }
    }
}
