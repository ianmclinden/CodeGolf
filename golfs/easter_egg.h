//
//  easter_egg.h
//  CodeGolf
//
//  Created by Ian McLinden on 4/15/17.
//  Copyright © 2017 Ian McLinden. All rights reserved.
//

// https://codegolf.stackexchange.com/questions/116477/make-me-an-easter-egg

void g(f) {
    char e[] = {f,f,f,f};
    printf("  __\n /%.2s\\\n/%.4s\\\n|%.4s|\n\\____/\n",e,e,e);
}

char * test_one_easter_egg(char c, char *expected) {
    char output[strlen(expected)*sizeof(char)];
    memset(output, 0, strlen(expected)*sizeof(char));
    
    ASSERT_SUCCESS("easter_egg did not run successfully", CAPTURE_PRINT_OUTPUT(output, g, c));
    ASSERT_NOT_NULL("easter_egg output was null", output);
    ASSERT_STRING_NOT_EMPTY("easter_egg output was empty", output);
    ASSERT_STRING_N_EQUAL("easter_egg did not have correct output", expected, output, strlen(expected));
    
    return SUCCESS;
}

static char * test_easter_egg() {
    printf("test_easter_egg():");
    
    char *result = test_one_easter_egg('-',easter_egg_dash);
    if (result) return result;
    
    result = test_one_easter_egg('%',easter_egg_percent);
    if (result) return result;
    
    result = test_one_easter_egg('~',easter_egg_tilde);
    if (result) return result;
    
    result = test_one_easter_egg('&',easter_egg_ampersand);
    if (result) return result;
    
    result = test_one_easter_egg('#',easter_egg_pound);
    if (result) return result;
    
    result = test_one_easter_egg(' ',easter_egg_space);
    if (result) return result;
    
    return SUCCESS;
}
