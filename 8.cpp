#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }

    void onesComplement()
    {
        Node *current = tail;
        while (current)
        {
            current->data = 1 - current->data;
            current = current->prev;
        }
    }

    void twosComplement()
    {
        onesComplement();
        int carry = 1;
        Node *current = tail;
        while (current)
        {
            current->data += carry;
            carry = current->data / 2;
            current->data %= 2;
            current = current->prev;
        }
    }

    DoublyLinkedList add(DoublyLinkedList &other)
    {
        DoublyLinkedList result;
        int carry = 0;
        Node *current1 = tail, *current2 = other.tail;

        while (current1 || current2 || carry)
        {
            int sum = (current1 ? current1->data : 0) + (current2 ? current2->data : 0) + carry;
            result.insertEnd(sum % 2);
            carry = sum / 2;

            if (current1)
                current1 = current1->prev;
            if (current2)
                current2 = current2->prev;
        }

        return result;
    }
};

int main()
{
    DoublyLinkedList binaryNum1, binaryNum2, result;

    cout << "Enter binary number 1: ";
    int num1;
    cin >> num1;

    cout << "Enter binary number 2: ";
    int num2;
    cin >> num2;

    while (num1 > 0)
    {
        binaryNum1.insertEnd(num1 % 10);
        num1 /= 10;
    }

    while (num2 > 0)
    {
        binaryNum2.insertEnd(num2 % 10);
        num2 /= 10;
    }

    cout << "Binary number 1: ";
    binaryNum1.display();

    cout << "Binary number 2: ";
    binaryNum2.display();

    binaryNum1.onesComplement();
    cout << "1's complement of binary number 1: ";
    binaryNum1.display();

    binaryNum2.twosComplement();
    cout << "2's complement of binary number 2: ";
    binaryNum2.display();

    result = binaryNum1.add(binaryNum2);
    cout << "Sum of binary numbers: ";
    result.display();

    return 0;
}
