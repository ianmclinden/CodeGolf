//
//  deciph4r4ng.h
//  CodeGolf
//
//  Created by Ian McLinden on 4/14/17.
//  Copyright © 2017 Ian McLinden. All rights reserved.
//

// https://codegolf.stackexchange.com/questions/115709/lets-do-some-deciph4r4ng

void deciph4r4ng(char *s) {
    // Pretty
    //	int i,k;
    //	for(;(k=s[++i]);) {
    //		if (k>47 && k<58)
    //			s[i] = s[i-k+47];
    //	}
    
    // Flat
    int i,k;for(;(k=s[++i]);)if(k>47&&k<58)s[i]=s[i-k+47];
}

char * test_one_deciph4r4ng(char *msg, char *crypt, char *pt) {
    char temp[strlen(crypt)];
    strcpy(temp, crypt);
    
    deciph4r4ng(temp);
    ASSERT_NOT_NULL(msg, temp);
    ASSERT_STRING_NOT_EMPTY(msg, temp);
    ASSERT_STRING_EQUAL(msg, temp, pt);
    return SUCCESS;
}

static char * test_deciph4r4ng() {
    printf("test_deciph4r4ng():");
    
    char *result = test_one_deciph4r4ng("error, deciph4r4ng 1", crypto_1, plaintext_1);
    if (result) return result;
    
    result = test_one_deciph4r4ng("error, deciph4r4ng 2", crypto_2, plaintext_2);
    if (result) return result;

    result = test_one_deciph4r4ng("error, deciph4r4ng 3", crypto_3, plaintext_3);
    if (result) return result;

    result = test_one_deciph4r4ng("error, deciph4r4ng 4", crypto_4, plaintext_4);
    if (result) return result;

    result = test_one_deciph4r4ng("error, deciph4r4ng 5", crypto_5, plaintext_5);
    if (result) return result;

    result = test_one_deciph4r4ng("error, deciph4r4ng 6", crypto_6, plaintext_6);
    if (result) return result;

    result = test_one_deciph4r4ng("error, deciph4r4ng 7", crypto_7, plaintext_7);
    if (result) return result;

    result = test_one_deciph4r4ng("error, deciph4r4ng 8", crypto_8, plaintext_8);
    if (result) return result;

    return SUCCESS;
}
