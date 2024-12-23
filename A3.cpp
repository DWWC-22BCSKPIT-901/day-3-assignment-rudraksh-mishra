#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

int list_to_num(Node* List) {
    int retval = 0;
    int k = 0;

    while (List != nullptr) {
        retval += List->data * pow(10, k);
        k++;
        List = List->next;
    }

    return retval;
}

Node* num_to_list(int num) {
    if (num == 0) {
        return new Node(0);
    }

    Node* retval = new Node(num % 10);
    num /= 10;
    Node* ptr = retval;

    while (num > 0) {
        Node* t = new Node(num % 10);
        ptr->next = t;
        ptr = t;
        num /= 10;
    }

    return retval;
}

int main(int argc, char* argv[]) {
    Node L1(2);
    Node L2(4);
    Node L3(3);

    L1.next = &L2;
    L2.next = &L3;

    Node M1(5);
    Node M2(6);
    Node M3(4);

    M1.next = &M2;
    M2.next = &M3;

    Node* ptr = &L1;
    while (ptr != nullptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL + ";

    ptr = &M1; 
    while (ptr != nullptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL = ";

    ptr = num_to_list(list_to_num(&L1) + list_to_num(&M1));
    
    while (ptr != nullptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;

    return 0;
}
