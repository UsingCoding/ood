#pragma once

namespace Common::Console
{
    class IOptionsEnumerator
    {
    public:
        virtual void ForEach(std::function<void(const std::string &, const std::optional<std::string> &)>) const = 0;
        virtual void ForEachReverse(std::function<void(const std::string &, const std::optional<std::string> &)>) const = 0;
    };
}
