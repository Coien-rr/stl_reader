#include "2jjalloc.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    int ia[5] = {0, 1, 2, 3, 4};
    unsigned int i;
    std::vector<int, JJ::allocator<int>> iv(ia, ia + 5);

    for (unsigned int i = 0; i < iv.size(); ++i) {
        std::cout << iv[i] << std::ends;
    }
    return 0;
}
