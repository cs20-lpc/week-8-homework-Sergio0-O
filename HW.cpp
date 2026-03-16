#include <iostream>
#include <string>
#include "StackFactory.hpp"

using namespace std;

int main()
{
    Stack<int>* listStack = StackFactory<int>::GetStack();
    Stack<int>* arrayStack = StackFactory<int>::GetStack(5);

    cout << "Testing LinkedListStack<int>" << endl;

    listStack->push(10);
    listStack->push(20);
    listStack->push(30);

    listStack->print();
    cout << "Length: " << listStack->getLength() << endl;
    cout << "Peek: " << listStack->peek() << endl;

    listStack->rotate(Stack<int>::RIGHT);
    listStack->print();

    listStack->rotate(Stack<int>::LEFT);
    listStack->print();

    listStack->pop();
    listStack->print();

    listStack->clear();
    cout << "Length after clear: " << listStack->getLength() << endl;
    cout << endl;

    cout << "Testing ArrayStack<int>" << endl;

    arrayStack->push(1);
    arrayStack->push(2);
    arrayStack->push(3);
    arrayStack->push(4);

    arrayStack->print();
    cout << "Length: " << arrayStack->getLength() << endl;
    cout << "Peek: " << arrayStack->peek() << endl;

    arrayStack->rotate(Stack<int>::RIGHT);
    arrayStack->print();

    arrayStack->rotate(Stack<int>::LEFT);
    arrayStack->print();

    arrayStack->pop();
    arrayStack->print();
    cout << endl;

    cout << "Testing LinkedListStack<string>" << endl;

    Stack<string>* stringStack = StackFactory<string>::GetStack();

    stringStack->push("A");
    stringStack->push("B");
    stringStack->push("C");

    stringStack->print();
    cout << "Peek: " << stringStack->peek() << endl;

    stringStack->pop();
    stringStack->print();
    cout << endl;

    cout << "Testing overflow on ArrayStack" << endl;

    Stack<int>* smallStack = StackFactory<int>::GetStack(2);

    smallStack->push(1);
    smallStack->push(2);

    try {
        smallStack->push(3);
    }
    catch (string e) {
        cout << e << endl;
    }

    delete listStack;
    delete arrayStack;
    delete stringStack;
    delete smallStack;

    return 0;
}
