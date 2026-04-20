#ifndef IOSIF_TESTS_HPP
#define IOSIF_TESTS_HPP

#include <chrono>
#include <iostream>
#include "LinkedList.hpp"

LinkedList<int> generateLinkedList(size_t size);

int iosifTest(LinkedList<int>& linkedList, size_t step);

void iosifTestBundle(const LinkedList<int>& sizes, size_t step, std::ostream& os);

void iosifTestCli(std::istream& is, std::ostream& os);

#endif
