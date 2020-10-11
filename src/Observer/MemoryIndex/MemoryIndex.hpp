#pragma once

template<class T>
class MemoryIndex
{
private:
    T m_index;
    bool m_changed = false;
public:
    MemoryIndex() = default;
    MemoryIndex(T index): m_index(index) {}

    void SetIndex(T index)
    {
        if (m_index == index)
        {
            return;
        }

        m_index = index;
        m_changed = true;
    }

    bool IsChanged() const
    {
        return m_changed;
    }

    void ResetState()
    {
        m_changed = false;
    }

    operator T() const
    {
        return m_index;
    }
};
