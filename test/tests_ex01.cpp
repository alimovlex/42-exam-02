#include <gtest/gtest.h>
#include <array>
#include <algorithm>
#include <cstdlib>
#include "tests.h"

TEST(ex02, ft_split)
{
    char arr[] = "Hello World together";
    std::array<std::string, 3> checker = {"Hello", "World", "together"};
    std::array<std::string, 3>::iterator itr;
    char** str = ft_split(arr);
    char** start = str;
    int i = 0;

    for (itr = checker.begin(), i = 0; itr != checker.end() && i < 3; ++itr, ++i)
        ASSERT_EQ(str[i], *itr);

    while(*str)
    {
        //std::cout << *str << std::endl;
        free(*str);
        str++;
    }
    free(start);

}

