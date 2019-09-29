#pragma once

#include "midi.h"
#include <algorithm>

using std::min;
using std::max;

class sequence_t
{
public:
    static const uint8_t max_len = 64;

    uint8_t length() const
    {
        return m_len;
    }

    void length(uint8_t len)
    {
        m_len = max<uint8_t>(1, min(len, max_len));
        m_pos = max<uint8_t>(m_pos, len - 1);
    }

    midi_t value()
    {
        midi_t v = m_seq[m_pos];
        if (++m_pos >= m_len)
            m_pos = 0;
        return v;
    }

    void reset()
    {
        m_pos = 0;
    }

    midi_t *ptr(uint8_t pos)
    {
        return &m_seq[pos];
    }

private:
    midi_t   m_seq[max_len]; 
    uint8_t  m_len;
    uint8_t  m_pos;
};

