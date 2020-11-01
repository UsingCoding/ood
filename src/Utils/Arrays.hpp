#pragma once

#include <memory>
#include "Strings.hpp"

namespace Arrays
{
    template<class Container, typename InputIterator, typename Callback>
    std::unique_ptr<Container> Map(InputIterator first, InputIterator end, Callback func)
    {
        auto container = std::make_unique<Container>();

        for (; first != end; ++first)
            container.insert(func(*first));
    }

    template<typename InputIterator>
    std::string Join(InputIterator first, InputIterator end, const std::string & glue)
    {
        Strings::Concatenator concatenator;

        for (; first != end; ++first)
        {
            if (first + 1 == end)
            {
                concatenator << *first;
                break;
            }

            concatenator << *first << glue;
        }

        return concatenator;
    }
}
