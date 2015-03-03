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

#include <gtest/gtest.h>
#include <pmcore/aes.h>
#include <stdio.h>

extern "C" {
    void PMAESShiftRows(PMAESBlock* block);
    void PMAESShiftRowsInv(PMAESBlock* block);
    uint8_t PMAESBlockByteAt(PMAESBlock* block, uint8_t row, uint8_t col);
    void PMAESBlockSetByteAt(PMAESBlock* block, uint8_t row, uint8_t col, uint8_t value);
    void PMAESMixColumnsInv(PMAESBlock* block);
    void PMAESMixColumns(PMAESBlock* block);
}

class PMTests : public ::testing::Test {
public:
    virtual void SetUp() {
        
    }
    
    virtual void TearDown() {
        
    }
};

extern "C" void PMAESBlockPrint(PMAESBlock* block) {
    //printf("0x");
    
    printf("%02X %02X %02X %02X\n%02X %02X %02X %02X\n%02X %02X %02X %02X\n%02X %02X %02X %02X\n", block->data[0], block->data[4], block->data[8], block->data[12], block->data[1], block->data[5], block->data[9], block->data[13], block->data[2], block->data[6], block->data[10], block->data[14], block->data[3], block->data[7], block->data[11], block->data[15]);
    printf("\n");
}

TEST_F(PMTests, BlockIndex) {
    PMAESBlock block = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};
    
    EXPECT_EQ(0, PMAESBlockByteAt(&block, 0, 0));
    EXPECT_EQ(1, PMAESBlockByteAt(&block, 1, 0));
    EXPECT_EQ(4, PMAESBlockByteAt(&block, 0, 1));
    EXPECT_EQ(14, PMAESBlockByteAt(&block, 2, 3));
    
    PMAESBlockSetByteAt(&block, 0, 0, 1);
    EXPECT_EQ(1, PMAESBlockByteAt(&block, 0, 0));
    
    PMAESBlockSetByteAt(&block, 0, 1, 1);
    EXPECT_EQ(1, PMAESBlockByteAt(&block, 0, 1));

    PMAESBlockSetByteAt(&block, 1, 0, 1);
    EXPECT_EQ(1, PMAESBlockByteAt(&block, 1, 0));
}

TEST_F(PMTests, ShiftRows) {
    PMAESBlock block = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};
    //PMAESBlockPrint(&block);
    
    PMAESBlock nblock;
    for (int k = 0; k < 16; k++) {
        block.data[k] = nblock.data[k];
    }
    
    PMAESShiftRows(&block);
    //PMAESBlockPrint(&block);
    
    PMAESShiftRowsInv(&block);
    //PMAESBlockPrint(&block);
    
    for (int k = 0; k < 16; k++) {
        ASSERT_EQ(block.data[k], nblock.data[k]);
    }
}

TEST_F(PMTests, MixColumns) {
    PMAESBlock block = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};
    //PMAESBlockPrint(&block);
    
    PMAESBlock nblock;
    for (int k = 0; k < 16; k++) {
        block.data[k] = nblock.data[k];
    }
    
    PMAESMixColumns(&block);
    //PMAESBlockPrint(&block);
    
    PMAESMixColumnsInv(&block);
    //PMAESBlockPrint(&block);
    
    for (int k = 0; k < 16; k++) {
        ASSERT_EQ(block.data[k], nblock.data[k]);
    }
}
