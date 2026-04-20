#ifndef IOSIF_TESTS_HPP
#define IOSIF_TESTS_HPP

#include <chrono>
#include <iostream>
#include "LinkedList.hpp"

LinkedList<int> generateLinkedList(size_t size);

int josephusTest(LinkedList<int>& linkedList, size_t step);

void josephusTestBundle(const LinkedList<int>& sizes, size_t step, std::ostream& os);

void josephusTestCli(std::istream& is, std::ostream& os);

#endif
