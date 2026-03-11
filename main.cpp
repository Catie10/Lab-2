#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

void addWord(Node*& head, string word) {
    Node* newNode = new Node;
    newNode->data = word;
    newNode->next = NULL;

if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void undo(Node*& head) {
    if (head == NULL) {
        cout << "List is empty. Nothing to undo.\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    string input;

    while (true) {
        cout << "Enter a word (UNDO to remove last, EXIT to quit): ";
        cin >> input;

        if (input == "EXIT") {
            break;
        }
        else if (input == "UNDO") {
            undo(head);
        }
        else {
            addWord(head, input);
        }

        display(head);
    }

    return 0;
}
