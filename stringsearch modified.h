#ifndef STRINGSEARCH_H
#define STRINGSEARCH_H

#include <string>

class StringSearch {
public:
    StringSearch(std::string s, std::string t);

    void search();
    bool found() const;
    int index() const;

private:
    std::string str;
    std::string target;
    bool is_found;
    int found_index;
};

#endif
