#include "StringSearch.h"
StringSearch::StringSearch(std::string s, std::string t) : str(s), target(t), is_found(false), found_index(-1) {}

void StringSearch::search() {
    size_t pos = str.find(target);
    if (pos != std::string::npos) {
        is_found = true;
        found_index = static_cast<int>(pos);
    }
}

bool StringSearch::found() const {
    return is_found;
}

int StringSearch::index() const {
    return found_index;
}
