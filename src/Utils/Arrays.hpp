#pragma once

#include <memory>

namespace Arrays
{
    template<class Container, typename InputIterator, typename Callback>
    std::unique_ptr<Container> Map(InputIterator first, InputIterator end, Callback func)
    {
        auto container = std::make_unique<Container>();

        for (; first != end; ++first)
            container.insert(func(*first));
    }
}
