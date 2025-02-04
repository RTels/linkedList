#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class linkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    linkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~linkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "Empty";
        }
        else {
            while (temp) {
                cout << temp->value << " ";
                temp = temp->next;
            }
        }

    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;

        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;

        Node* temp = head;
        if (length == 1) {head = nullptr; tail = nullptr;}
        else {
            head = head->next;
            delete temp;
            length--;
        }
    }

    void deleteLast() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head->next = nullptr;
            tail->next = nullptr;
        }
        else {
            Node* pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length --;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    Node* get(int index) {
        if (index >= length) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;

    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) {prepend(value); return true;}
        if (index == length) {append(value); return true;}

        Node* newNode = new Node(value);
        Node* temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) {deleteFirst(); return;}
        if (index == length - 1) deleteLast();

        else {
            Node* prev = get(index - 1);
            Node* temp = prev->next;
            prev->next = temp->next;
            delete temp;
            length--;
        }

    }

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* after = nullptr; Node* before = nullptr;
        for (int i = 0; i < length; i++) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }

    }



};

int main() {
    //prints for testing
    //linkedList* myLL = new linkedList(1);
    //myLL->append(5);
    //myLL->append(7);
    //myLL->append(9);
    //myLL->printList(); cout << "\n";
    //myLL->reverse();
    //myLL->printList();
    return 0;
}

















