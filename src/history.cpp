#include "history.h"
#include <iostream>

History::~History() {
    clear();
}

int History::get_max_size() const {
    return max_size;
}

void History::set_max_size(const int size) {
    max_size = size;
    while (current_size > max_size) {
        delete[] history.front();
        history.pop_front();
        --current_size;
    }
}

void History::add(const char output[]) {
    if (current_size == max_size) {
        delete[] history.front();
        history.pop_front();
        --current_size;
    }
    const auto entry = new char[OUTPUT_SIZE];
    int i = 0;
    while (output[i] != '\0' && i < OUTPUT_SIZE - 1) {
        entry[i] = output[i];
        ++i;
    }
    entry[i] = '\0';
    history.push_back(entry);
    ++current_size;
}

void History::print() const {
    for (const char* entry : history) {
        std::cout << entry << std::endl;
    }
}

void History::clear() {
    for (const char* entry : history) {
        delete[] entry;
    }
    history.clear();
    current_size = 0;
}