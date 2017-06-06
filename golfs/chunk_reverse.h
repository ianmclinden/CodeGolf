//
//  chunk_reverse.h
//  CodeGolf
//
//  Created by Ian McLinden on 4/16/17.
//  Copyright © 2017 Ian McLinden. All rights reserved.
//

// https://codegolf.stackexchange.com/questions/116550/reverse-a-string-by-chunks

void chunk_reverse(char *s, int n) {
    // TODO : 
}

char * test_one_chunk_reverse(char *msg, char *str, int n, char *rev) {
    char temp[strlen(str)];
    strcpy(temp, str);
    
    chunk_reverse(temp, n);
    ASSERT_NOT_NULL(msg, temp);
    ASSERT_STRING_NOT_EMPTY(msg, temp);
    ASSERT_STRING_EQUAL(msg, temp, rev);
    return SUCCESS;
}

static char * test_chunk_reverse() {
    printf("test_chunk_reverse():");
    char * result = test_one_chunk_reverse("error, chunk_reverse 1", cr_fwd_n2_1, 2, cr_rev_n2_1);
    if (result) return result;
    
    test_one_chunk_reverse("error, chunk_reverse 2", cr_fwd_n3_2, 3, cr_rev_n3_2);
    if (result) return result;

    test_one_chunk_reverse("error, chunk_reverse 3", cr_fwd_n3_3, 3, cr_rev_n3_3);
    if (result) return result;

    test_one_chunk_reverse("error, chunk_reverse 4", cr_fwd_n2_4, 2, cr_rev_n2_4);
    if (result) return result;

    test_one_chunk_reverse("error, chunk_reverse 5", cr_fwd_n1_5, 1, cr_rev_n1_5);
    if (result) return result;

    test_one_chunk_reverse("error, chunk_reverse 6", cr_fwd_n2_6, 2, cr_rev_n2_6);
    if (result) return result;

    test_one_chunk_reverse("error, chunk_reverse 7", cr_fwd_n2_7, 2, cr_rev_n2_7);
    if (result) return result;

    test_one_chunk_reverse("error, chunk_reverse 8", cr_fwd_n50_8, 50, cr_rev_n50_8);
    if (result) return result;

    return SUCCESS;
}
