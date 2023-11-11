#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    // Get two iterators within the vector
    std::vector<int>::iterator beginIterator = numbers.begin();
    std::vector<int>::iterator endIterator = numbers.end();

    // Calculate the distance between the iterators
    int distance = std::distance(beginIterator, find(numbers.begin(), numbers.end(), 30));

    std::cout << "The distance between begin and end iterators: " << distance << std::endl;

    return 0;
}

