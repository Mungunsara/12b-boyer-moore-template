#include "search.h"

/* Bad-character хүснэгт байгуулах */
void bm_build_rightmost(const unsigned char *pattern, size_t m,
                        ptrdiff_t right[256])
{
    for (size_t c = 0; c < 256; ++c)
        right[c] = -1;

    for (size_t j = 0; j < m; ++j)
        right[pattern[j]] = (ptrdiff_t)j;
}

/* Boyer-Moore bad-character хайлт */
int search_all(const unsigned char *text, size_t n,
               const unsigned char *pattern, size_t m,
               match_fn emit, void *context)
{
    if (m == 0 || pattern == NULL || emit == NULL ||
        (n > 0 && text == NULL) || m > (size_t)PTRDIFF_MAX) {
        return SEARCH_BAD_ARGUMENT;
    }

    if (n == 0 || m > n)
        return SEARCH_OK;

    ptrdiff_t right[256];
    bm_build_rightmost(pattern, m, right);

    size_t s = 0;
    size_t last = n - m;

    while (s <= last) {
        size_t j = m;

        while (j > 0 && pattern[j - 1] == text[s + j - 1])
            --j;

        size_t shift;

        if (j == 0) {
            if (emit(s, context) != 0)
                return SEARCH_OUTPUT_ERROR;

            shift = 1;
        } else {
            size_t mismatch = j - 1;
            unsigned char c = text[s + mismatch];

            ptrdiff_t r = right[c];
            ptrdiff_t distance = (ptrdiff_t)mismatch - r;

            shift = distance > 0 ? (size_t)distance : 1;
        }

        if (shift > last - s)
            break;

        s += shift;
    }

    return SEARCH_OK;
}
