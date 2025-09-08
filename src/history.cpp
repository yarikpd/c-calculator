#include "history.h"
#include <iostream>
#include <cstring>

int History::get_max_size() const {
    return max_size;
}

void History::set_max_size(const int size) {
    max_size = size;
    while (current_size > max_size) {
        history.pop_front();
        --current_size;
    }
}

void History::add(const char output[]) {
    if (current_size == max_size) {
        history.pop_front();
        --current_size;
    }
    std::array<char, OUTPUT_SIZE> entry{};
    std::strncpy(entry.data(), output, OUTPUT_SIZE - 1);
    entry[OUTPUT_SIZE - 1] = '\0';
    history.push_back(entry);
    ++current_size;
}

void History::print() const {
    for (const auto& entry : history) {
        std::cout << entry.data() << std::endl;
    }
}

void History::clear() {
    history.clear();
    current_size = 0;
}