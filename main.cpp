#include <iostream>
#include <string>
#include <stdexcept>
#include "LinkedList.hpp"


void testAddAndGet() {
    std::cout << "Test add and get:\n";
    LinkedList<int> list;
    list.add(10);
    list.add(20);
    list.add(0, 30);
    list.add(1, 40);
    std::cout << "add/get test: ";
    for (size_t i = 0; i < list.getSize(); ++i) {
        std::cout << list.get(i) << " ";
    }
    std::cout << "\n";
    std::cout << "##########\n\n";
}

void testRemove() {
    std::cout << "Test remove:\n";
    LinkedList<std::string> list;
    list.add("first");
    list.add("second");
    list.add("third");
    list.remove(1);
    std::cout << "remove test: ";
    for (size_t i = 0; i < list.getSize(); ++i) {
        std::cout << list.get(i) << " ";
    }
    std::cout << "\n";
    list.remove(0);
    std::cout << "after remove head: ";
    for (size_t i = 0; i < list.getSize(); ++i) {
        std::cout << list.get(i) << " ";
    }
    std::cout << "\n";
    std::cout << "##########\n\n";
}

void testOutOfBounds() {
    std::cout << "Test out of bounds:\n";
    LinkedList<double> list;
    list.add(1.1);
    list.add(2.2);
    try {
        list.get(5);
    } catch (const std::runtime_error& e) {
        std::cout << "out of bounds get: " << e.what() << "\n";
    }
    try {
        list.add(3, 3.3);
    } catch (const std::runtime_error& e) {
        std::cout << "out of bounds add: " << e.what() << "\n";
    }
    try {
        list.remove(2);
    } catch (const std::runtime_error& e) {
        std::cout << "out of bounds remove: " << e.what() << "\n";
    }
    std::cout << "##########\n\n";
}

void testCopyConstructor() {
    std::cout << "Test copy constructor:\n";
    LinkedList<int> original;
    original.add(100);
    original.add(200);
    original.add(300);
    LinkedList<int> copy = original;

    std::cout << "Original: " << original << "\n";
    std::cout << "Copy: " << copy << "\n\n";

    copy.remove(0);
    std::cout << "original after copy modify: ";
    for (size_t i = 0; i < original.getSize(); ++i) {
        std::cout << original.get(i) << " ";
    }
    std::cout << "\n";
    std::cout << "copy: ";
    for (size_t i = 0; i < copy.getSize(); ++i) {
        std::cout << copy.get(i) << " ";
    }
    std::cout << "\n";
    std::cout << "##########\n\n";
}

void testMoveConstructor() {
    std::cout << "Test move constructor:\n";
    LinkedList<int> source;
    source.add(42);
    source.add(84);

    LinkedList<int> destination = std::move(source);
    std::cout << "source size after move: " << source.getSize() << "\n";
    std::cout << "destination content: " << destination << "\n";

    std::cout << "##########\n\n";
}

void testCopyAssignmentOperator() {
    std::cout << "Test copy assignment operator:\n";
    LinkedList<char> a;
    a.add('A');
    a.add('B');

    LinkedList<char> b;
    b = a;

    std::cout << "a after copy assignment operator: " << a << "\n";
    std::cout << "b after copy assignment operator: " << b << "\n\n";

    b.add('C');

    std::cout << "a: " << a << "\n";
    std::cout << "b after adding one more element: " << b << "\n";
    std::cout << "##########\n\n";
}

void testMoveAssignmentOperator() {
    std::cout << "Test move assignment:\n";
    LinkedList<int> x;
    x.add(1);
    x.add(2);
    LinkedList<int> y;
    y.add(3);
    y = std::move(x);
    std::cout << "x size after move assign: " << x.getSize() << "\n";
    std::cout << "y: ";
    for (size_t i = 0; i < y.getSize(); ++i) {
        std::cout << y.get(i) << " ";
    }
    std::cout << "\n";
    std::cout << "##########\n\n";
}

int main() {
    testAddAndGet();
    testRemove();
    testOutOfBounds();
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignmentOperator();
    testMoveAssignmentOperator();
    return 0;
}
