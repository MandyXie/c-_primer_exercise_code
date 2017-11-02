#include <vector>
#include <algorithm>
#include "Exercise_13.31.test.h"

int main(void)
{
    HasPtr s{ "s" }, a{ "a" }, c{ "c" };
    std::vector<HasPtr> vec{ s, a, c };
    std::sort(vec.begin(), vec.end());

    for (auto const& elem : vec) elem.show();
    return 0;
}
