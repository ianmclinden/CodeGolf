//
//  alternate_case.h
//  CodeGolf
//
//  Created by Ian McLinden on 5/27/17.
//  Copyright © 2017 Ian McLinden. All rights reserved.
//

// https://codegolf.stackexchange.com/questions/122783/alternate-the-case

void alternate_case(char *s) {
    // ASCII letter range
    // A - Z = 65 - 90  01000001 - 01011010
    // a - z = 97 - 122 01100001 - 01111010
    // TODO
}

char * test_one_alternate_case(char *msg, char *str, char *str2) {
    char temp[strlen(str)];
    strcpy(temp, str);
    
    alternate_case(temp);
    ASSERT_NOT_NULL(msg, temp);
    ASSERT_STRING_NOT_EMPTY(msg, temp);
    ASSERT_STRING_EQUAL(msg, temp, str2);
    return SUCCESS;
}

static char * test_alternate_case() {
    printf("test_alternate_case():");
    char * result = test_one_alternate_case("error, alternate_case 1", ac_pre_1, ac_post_1);
    if (result) return result;
    
    result = test_one_alternate_case("error, alternate_case 2", ac_pre_2, ac_post_2);
    if (result) return result;
    
    result = test_one_alternate_case("error, alternate_case 3", ac_pre_3, ac_post_3);
    if (result) return result;
    
    result = test_one_alternate_case("error, alternate_case 4", ac_pre_4, ac_post_4);
    if (result) return result;
    
    result = test_one_alternate_case("error, alternate_case 5", ac_pre_5, ac_post_5);
    if (result) return result;
    
    result = test_one_alternate_case("error, alternate_case 6", ac_pre_6, ac_post_6);
    if (result) return result;
    
    result = test_one_alternate_case("error, alternate_case 7", ac_pre_7, ac_post_7);
    if (result) return result;
    
    return SUCCESS;
}
