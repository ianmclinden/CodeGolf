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

static char * test_deep_dish_pizza() {
    printf("test_deep_dish_pizza():\n");
    int i;
    for (i=1; i<=8; i++) {
        printf("==== Pizza: N=%i ====\n",i);
        deep_dish_pizza(i);
    }
    return SUCCESS;
}
