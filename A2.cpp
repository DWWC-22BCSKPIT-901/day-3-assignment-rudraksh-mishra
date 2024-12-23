#include <iostream>

using namespace std;

struct Node{
    int   data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

void i_reverse_list(Node& List) {
    Node* current = &List;
    Node* next    = nullptr;
    Node* prev    = nullptr;

    while (current != nullptr) {
        prev       = current;
        current    = current->next;
        prev->next = next;
        next       = prev;
    }
}

void r_reverse_list(Node* List) {
    if (List->next == nullptr || List == nullptr) { return; }

    Node* rest = List->next;

    r_reverse_list(rest);

    List->next->next = List;
    List->next       = nullptr;
    List = rest;
}

int main(int argc, char* argv[]) {
    Node N1(1);
    Node N2(2);
    Node N3(3);
    Node N4(4);

    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;
    N4.next = nullptr;

    Node* ptr = &N1;

    cout << "Original List             : ";
    while (ptr != nullptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;

    r_reverse_list(&N1);

    ptr = &N4;

    cout << "Recursively reversed List : ";
    while (ptr != nullptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
    
    i_reverse_list(N4);

    ptr = &N1;

    cout << "Iteratively reversed List : ";
    while (ptr != nullptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;

    return 0;
}