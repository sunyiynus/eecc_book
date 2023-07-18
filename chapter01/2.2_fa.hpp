#ifndef CHAPTER_2_2_FA_HPP
#define CHAPTER_2_2_FA_HPP 

#include <stdint.h>
#include <vector>

enum {Se = -1, S0 = 0, S1, S2, S3, S4, S5};
enum {We = -1, W0 = 0, W1, W2, W3, W4, W5};

using state_type = int32_t;
using stable_type = std::vector<std::vector<state_type>>;

template<typename INPUT_T>
struct StateTrans
{
    using classify_type = std::function<stable_type (const INPUT_T&)>;

    StateTrans() {}
    StateTrans(const StateTrans&)
    {
    }

    StateTrans(classify_type _f, const stable_type& _t):
        _f_aggreate(_f), _table(_t), _state(S0) {
        if (_table.empty() || _table[ZERO_INDEX].empty()) {
            _state = Se;
        }
    }

    void operator()(const INPUT_T& data)
    {
        state_type Wx = _f_aggreate(data);
        if (Wx <= We || Wx >= _table[ZERO_INDEX].size()) {
            _state = Se;
        } else {
            _state = _table[_state][Wx];
        }
    }

    const state_type state() const { return _state; }

private:
    constexpr static int ZERO_INDEX = 0;
    constexpr static int SE_OFFSET = 1;
private:
    state_type _state;
    stable_type _table;
    std::function<stable_type (const INPUT_T&)> _f_aggreate;
};


/* 

usage :

stable_type table = {
        {se, Se},
        {se, Se},
        {se, Se},
        {se, Se},
                    };
auto fn = [](const char& c) -> int { return W0; };
StateTrans<char> statetrans (fn, table);

*/


#endif
