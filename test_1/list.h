#pragma once
#include <vector>
#include <iostream>
using namespace std;

typedef struct Node
{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
} Node;

class List {
public:
    //1.创建链表
    Node* create_list(vector<int>& arr);
    //2.链表插入
    void list_insert(Node* head, int val, int index);
    //3.链表遍历
    void list_print(Node* head);

};