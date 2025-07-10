#include "list.h"

void demo () {
    vector<int> arr = {1,2,3,4,5};

    List list;
    Node* head = list.create_list(arr);

    list.list_insert(head, 12,87);

    list.list_print(head);

    list.list_destory(head);
    
    list.list_print(head);
}

int main () {
    vector<int> arr = {2, 1, 3, 4, 5, 120, 12};
    Bubble_Sort sort;
    sort.solution(arr);
    sort.print_info(arr);
    return 0;
}

