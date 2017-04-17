//
//  deep_dish_pizza.h
//  CodeGolf
//
//  Created by Ian McLinden on 4/14/17.
//  Copyright © 2017 Ian McLinden. All rights reserved.
//
#include <string.h>

// https://codegolf.stackexchange.com/questions/115408/pizza-pizza-deep-dish-pizza

void deep_dish_pizza(n) {
//    int l = n*3+6;
//    int i;
//    char u[l];
//
//    // Initialize u[] with a full line of underscores,
//    for (;i<l;)
//        u[i++] = '_';
//
//    // Make sure the string ends in a valid way
//    u[l] = i = 0;
//
//    /* Print the crust 'top'
//     * l-4 dashes are needed because '/\/\'
//     * %.*s notation to pad (l-4) bytes of the underscore string
//     */
//    printf("/\\%.*s/\\\n", l-4,u);
//
//    /* Print n rows of just 'walls' \ \  / /
//     * each row has i=0++ leading spaces,
//     * and each row has n*3-(2i) center spaces
//     */
//    for(; i<n; i++)
//        printf("%*s\\ \\%*.s/ /\n", i,"", n*3-(2*i), "");
//
//    /* Print i spaces, '\ \', n underlines, '/ /'
//     * then i+1 spaces, '\', n+2 underlines, and '/'
//     */
//    printf("%*.s\\ \\%.*s/ /\n%*.s\\%.*s/\n",i,"",n,u,i+1,"",n+2,u);
    
    int i,l=n*3+6;;char u[l];for(i=0;i<l;)u[i++]='_';u[l]=i=0;printf("/\\%.*s/\\\n", l-4,u);for(;i<n;i++)printf("%*s\\ \\%*.s/ /\n",i,"",n*3-(2*i),"");printf("%*.s\\ \\%.*s/ /\n%*.s\\%.*s/\n",i,"",n,u,i+1,"",n+2,u);

}

char * test_one_deep_dish_pizza(int n, char *expected) {
    char output[strlen(expected)*sizeof(char)];
    
    ASSERT_SUCCESS("deep_dish_pizza did not run successfully", CAPTURE_PRINT_OUTPUT(output, deep_dish_pizza, n));
    ASSERT_NOT_NULL("deep_dish_pizza output was null", output);
    ASSERT_STRING_NOT_EMPTY("deep_dish_pizza output was empty", output);
    ASSERT_STRING_N_EQUAL("deep_dish_pizza did not have correct output", expected, output, strlen(expected));
    
    return SUCCESS;
}

static char * test_deep_dish_pizza() {
    printf("test_deep_dish_pizza():");
    
    char *result = test_one_deep_dish_pizza(1, deep_dish_pizza_1);
    if (result) return result;
    
    result = test_one_deep_dish_pizza(2, deep_dish_pizza_2);
    if (result) return result;
    
    result = test_one_deep_dish_pizza(3, deep_dish_pizza_3);
    if (result) return result;
    
    result = test_one_deep_dish_pizza(4, deep_dish_pizza_4);
    if (result) return result;
    
    result = test_one_deep_dish_pizza(5, deep_dish_pizza_5);
    if (result) return result;
    
    result = test_one_deep_dish_pizza(6, deep_dish_pizza_6);
    if (result) return result;
    
    result = test_one_deep_dish_pizza(7, deep_dish_pizza_7);
    if (result) return result;
    
    result = test_one_deep_dish_pizza(8, deep_dish_pizza_8);
    if (result) return result;
    
    return SUCCESS;
}
