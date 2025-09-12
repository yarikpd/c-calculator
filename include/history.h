#ifndef RPN_CALCULATOR_HISTORY_H
#define RPN_CALCULATOR_HISTORY_H
#include <list>

class History {
    static constexpr int OUTPUT_SIZE = 100;
    int max_size = 10;
    int current_size = 0;
    std::list<char*> history;

public:
    ~History();
    int get_max_size() const;
    void set_max_size(int size);
    void add(const char output[]);
    void print() const;
    void clear();
};


#endif //RPN_CALCULATOR_HISTORY_H