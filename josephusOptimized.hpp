#ifndef IOSIF_TESTS_OPTIMIZED_HPP
#define IOSIF_TESTS_OPTIMIZED_HPP

#include <chrono>
#include <iostream>
#include "LinkedList.hpp"

LinkedList<int> generateLinkedListOptimized(size_t size);

int josephusTestOptimized(LinkedList<int>& linkedList, size_t step);

void josephusTestBundleOptimized(const LinkedList<int>& sizes, size_t step, std::ostream& os);

void josephusTestCliOptimized(std::istream& is, std::ostream& os);

#endif
