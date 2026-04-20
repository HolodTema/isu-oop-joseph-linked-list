#include "josephus.hpp"
#include <chrono>
#include "LinkedList.hpp"

LinkedList<int> generateLinkedList(size_t size)
{
    LinkedList<int> linkedList;
    for (size_t i = size; i > 0; --i)
    {
        linkedList.add(i);
    }
    return linkedList;
}


int iosifTest(LinkedList<int>& linkedList, size_t step)
{
    size_t index = 0;
    
    while (linkedList.getSize() > 1)
    {
        index = (index + step - 1) % linkedList.getSize();
        linkedList.remove(index);
    }
    return linkedList.get(0);
}


void iosifTestBundle(const LinkedList<int>& sizes, size_t step, std::ostream& os)
{
    int answer = 0;
    long long time = 0;

    os << "N\t\t\tAnswer\t\t\tTime (microseconds)\n";

    for (int i = 0; i < sizes.getSize(); ++i)
    {
        LinkedList<int> generatedList = generateLinkedList(sizes.get(i));
        
        os << sizes.get(i) << "\t\t\t";
        
        auto startTime = std::chrono::high_resolution_clock::now();

        answer = iosifTest(generatedList, step);
        
        auto endTime = std::chrono::high_resolution_clock::now();
        auto durationMicros = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        time = durationMicros.count();
        
        os << answer << "\t\t\t";
        os << time << "\t\t\t\n";
    }
}

void iosifTestCli(std::istream& is, std::ostream& os)
{
    size_t n = 0;
    size_t step = 0;

    os  << "Flavius Josephus test CLI\n";
    os << "Enter N:\n";
    is >> n;
    os << "Enter step (k):\n";
    is >> step;

    os << "Starting test...\n";

    LinkedList<int> generatedList = generateLinkedList(n);
        
    auto startTime = std::chrono::high_resolution_clock::now();
    int answer = iosifTest(generatedList, step);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto durationMicros = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    long long time = durationMicros.count();

    os << "Answer: " << answer << "\n";
    os << "Time (microseconds): " << time << "\n";
}
        
