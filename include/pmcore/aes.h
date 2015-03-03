/*** ------------------------------------------------------------------------------ ***
*
* Copyright (C) 2015, Jack Maloney
*
* Permission to use, copy, modify, and/or distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*** ------------------------------------------------------------------------------ ***/

#include <stdint.h>

typedef struct sPMAESBlock PMAESBlock;
typedef struct sPMAESKey PMAESKey;
typedef struct sPMAESRoundKey PMAESRoundKey;
typedef struct sPMAESWord PMAESWord;

struct sPMAESBlock {
    uint8_t data[16];
};

struct sPMAESRoundKey {
    uint8_t data[16];
};

// Still columns of four, just eight rows
struct sPMAESKey {
    uint8_t data[32];
};

struct sPMAESWord {
    uint8_t data[4];
};

//PMAESBlock PMAESEncrypt(PMAESBlock pt, PMAESKey key);
