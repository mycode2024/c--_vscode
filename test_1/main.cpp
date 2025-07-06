#include "list.h"

int main () {
    vector<int> arr = {1,2,3,4,5};

    List list;
    Node* head = list.create_list(arr);
    list.list_insert(head, 12,87);

    list.list_print(head);

    return 0;
}

