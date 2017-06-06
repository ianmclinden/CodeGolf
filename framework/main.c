//
//  main.c
//  CodeGolf
//
//  Created by Ian McLinden on 4/14/17.
//  Copyright © 2017 Ian McLinden. All rights reserved.
//

#include <stdio.h>
#include "minunit.h"
#include "statics.h"
#include "external_golfs.h"
#include "deep_dish_pizza.h"
#include "enciph5r47g.h"
#include "deciph4r4ng.h"
#include "easter_egg.h"
#include "chunk_reverse.h"
#include "alternate_case.h"

/*
 * Main Test List -- Enable all tests you want to run here.
 */
static char * all_tests() {
    RUN_TEST(test_deep_dish_pizza);
    RUN_TEST(test_enciph5r47g);
    RUN_TEST(test_deciph4r4ng);
    RUN_TEST(test_easter_egg);
    RUN_TEST(test_hellu);
//    RUN_TEST(test_chunk_reverse);
//    RUN_TEST(test_alternate_case);
    return SUCCESS;
}

int main(int argc, char **argv) {
    printf("CodeGolf Automated Tests:\n------------------------\n");
    char *result = all_tests();
    
    printf("\n------------------------\nTests run: %d\n", tests_run);
    if (result != SUCCESS) {
        printf("A TEST FAILED: %s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    
    return result != SUCCESS;
}
