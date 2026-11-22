#ifndef SUBSTRING_SEARCH_H
#define SUBSTRING_SEARCH_H

#include <stddef.h>
#include <stdint.h>

typedef int (*match_fn)(size_t position, void *context);

enum {
    SEARCH_OK = 0,
    SEARCH_NO_MEMORY = 1,
    SEARCH_BAD_ARGUMENT = 2,
    SEARCH_OUTPUT_ERROR = 3,
    SEARCH_NOT_IMPLEMENTED = 4
};

/* m <= PTRDIFF_MAX; right нь 256 элементтэй массив.
 * right[c] нь pattern доторх c байтын хамгийн баруун индекс;
 * уг байт байхгүй бол -1. m > 0 үед pattern хүчинтэй байна.
 */
void bm_build_rightmost(const unsigned char *pattern, size_t m,
                        ptrdiff_t right[256]);

/* Бүх олдцын эхлэх байт индексийг өсөх дарааллаар emit-д дамжуулна.
 * Давхцсан олдцыг мөн бүртгэнэ. n, m нь байтаар өгсөн урт; NUL байт
 * текст болон pattern-ийн дотор байж болно. 0 < m <= PTRDIFF_MAX.
 * n > 0 үед text, үргэлж pattern болон emit хүчинтэй байх ёстой.
 * emit алдаа буцаавал шууд зогсоож SEARCH_OUTPUT_ERROR буцаана.
 */
int search_all(const unsigned char *text, size_t n,
               const unsigned char *pattern, size_t m,
               match_fn emit, void *context);

#endif
