#include "josephusOptimized.hpp"
#include <chrono>
#include "LinkedList.hpp"

LinkedList<int> generateLinkedListOptimized(size_t size)
{
    LinkedList<int> linkedList;
    for (size_t i = size; i > 0; --i)
    {
        linkedList.add(i);
    }
    return linkedList;
}


int josephusTestOptimized(LinkedList<int>& linkedList, size_t step)
{
    LinkedList<int>::Iterator it = linkedList.begin();

    while (linkedList.getSize() > 1)
    {
        for (size_t i = 0; i < (step-1); ++i) {
            ++it;
        }
        it.removeCurrentAndStepForward();
    } 
    return linkedList.get(0);
}


void josephusTestBundleOptimized(const LinkedList<int>& sizes, size_t step, std::ostream& os)
{
    int answer = 0;
    long long time = 0;

    os << "Optimized Josephus test for LinkedList\n";
    os << "N\t\t\tAnswer\t\t\tTime (microseconds)\n";

    for (int i = 0; i < sizes.getSize(); ++i)
    {
        LinkedList<int> generatedList = generateLinkedListOptimized(sizes.get(i));
        
        os << sizes.get(i) << "\t\t\t";
        
        auto startTime = std::chrono::high_resolution_clock::now();

        answer = josephusTestOptimized(generatedList, step);
        
        auto endTime = std::chrono::high_resolution_clock::now();
        auto durationMicros = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        time = durationMicros.count();
        
        os << answer << "\t\t\t";
        os << time << "\t\t\t\n";
    }
}

void josephusTestCliOptimized(std::istream& is, std::ostream& os)
{
    size_t n = 0;
    size_t step = 0;

    os  << "Flavius Josephus test CLI (Optimized for Linked list)\n";
    os << "Enter N:\n";
    is >> n;
    os << "Enter step (k):\n";
    is >> step;

    os << "Starting test...\n";

    LinkedList<int> generatedList = generateLinkedListOptimized(n);
        
    auto startTime = std::chrono::high_resolution_clock::now();
    int answer = josephusTestOptimized(generatedList, step);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto durationMicros = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    long long time = durationMicros.count();

    os << "Answer: " << answer << "\n";
    os << "Time (microseconds): " << time << "\n";
}
        
