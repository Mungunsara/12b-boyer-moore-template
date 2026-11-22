#include "search.h"

/* TODO 1: bad-character дүрмийн right хүснэгтийг байгуул.
 * Байхгүй байт бүрт -1; байвал хамгийн сүүлийн индексийг хадгална.
 * Зорилт: O(256+m) хугацаа.
 */
void bm_build_rightmost(const unsigned char *pattern, size_t m,
                        ptrdiff_t right[256])
{
    (void)pattern;
    (void)m;
    for (size_t c = 0; c < 256; ++c)
        right[c] = -1;
    /* TODO: pattern-ийг ашиглан хүснэгтээ гүйцээ. */
}

/* TODO 2: Boyer-Moore-ийн bad-character хувилбарыг хэрэгжүүл.
 *
 * - search.h дахь оролт болон буцаах утгын гэрээг мөрдөнө.
 * - Pattern-ийг баруунаас зүүн тийш харьцуулна.
 * - Үл таарсан тэмдэгт болон right хүснэгтээр шилжилтээ тооцно.
 * - Алхам үргэлж эерэг байна; size_t-ийн хасалт/нэмэлтийн хязгаарыг
 *   шалгана. m>n үед n-m гэж тооцохоос өмнө буцна.
 * - Бүтэн match бүрт emit(start, context) дуудна. Давхцсан олдцыг
 *   хадгалахын тулд бүтэн match-ийн дараа нэг байрлалаар шилжинэ.
 *
 * Энэ лабораторид good-suffix дүрэм шаардахгүй.
 * Бэлтгэл O(256+m), хайлтын хамгийн муу хугацаа O(n*m).
 * Нэмэлт санах ой O(256). Emit-ийн өөрийн ажлыг хугацаанд оруулаагүй.
 * main() аль хэдийн -i сонголтын нормчлолыг хийсэн байна.
 */
int search_all(const unsigned char *text, size_t n,
               const unsigned char *pattern, size_t m,
               match_fn emit, void *context)
{
    (void)text;
    (void)n;
    (void)pattern;
    (void)m;
    (void)emit;
    (void)context;
    return SEARCH_NOT_IMPLEMENTED;
}
