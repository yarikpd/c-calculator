#ifndef RPN_CALCULATOR_HISTORY_H
#define RPN_CALCULATOR_HISTORY_H
#include <list>

/**
 * @class History
 * @brief Manages a history of output strings for an RPN calculator.
 */
class History {
    static constexpr int OUTPUT_SIZE = 100;
    int max_size = 10;
    int current_size = 0;
    std::list<char*> history;

public:

    /**
     * @brief Destructor. Cleans up allocated memory for history entries.
     */
    ~History();

    /**
     * @brief Gets the maximum number of history entries.
     * @return Maximum size of the history.
     */
    int get_max_size() const;

    /**
 * @brief Sets the maximum number of history entries.
 *
 * If the new maximum size is less than the current number of entries,
 * older entries may be removed to fit the new limit.
 *
 * @param size New maximum size for the history.
 */
    void set_max_size(int size);

    /**
 * @brief Adds a new output string to the history.
 *
 * Stores the provided output string in the history. If the history exceeds
 * the maximum size, the oldest entry is removed.
 *
 * @param output Output string to add to the history.
 */
    void add(const char output[]);

    /**
 * @brief Prints all history entries to the standard output.
 *
 * Iterates through the stored history and outputs each entry.
 */
    void print() const;

    /**
 * @brief Clears all history entries.
 *
 * Removes all stored output strings from the history and frees associated memory.
 */
    void clear();
};


#endif //RPN_CALCULATOR_HISTORY_H