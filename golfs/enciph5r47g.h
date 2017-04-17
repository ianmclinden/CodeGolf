//
//  enciph5r47g.h
//  CodeGolf
//
//  Created by Ian McLinden on 4/14/17.
//  Copyright © 2017 Ian McLinden. All rights reserved.
//
#include <string.h>

// https://codegolf.stackexchange.com/questions/115742/lets-do-some-enciph5r47g

void enciph5r47g(char *s) {
    // Pretty
    //	int i,j;
    //	for(i=strlen(s)-1; s[i]; i--)
    //		for(j=i-1; s[j] && i-j < 11; j--)
    //			if (s[i] == s[j]) {
    //				s[i] = 47+i-j;
    //				break;
    //			}
    
    // Flat
    int i,j;for(i=strlen(s)-1;s[i];i--)for(j=i-1;s[j]&&i-j<11;j--)if(s[i]==s[j]){s[i]=47+i-j;break;}
}

char * test_one_enciph5r47g(char *msg, char *pt, char *crypt) {
    char temp[strlen(pt)];
    strcpy(temp, pt);
    
    enciph5r47g(temp);
    ASSERT_NOT_NULL(msg, temp);
    ASSERT_STRING_NOT_EMPTY(msg, temp);
    ASSERT_STRING_EQUAL(msg, temp, crypt);
    return SUCCESS;
}

static char * test_enciph5r47g() {
    printf("test_enciph5r47g():");
    char * result = test_one_enciph5r47g("error, enciph5r47g 1", plaintext_1, crypto_1);
    if (result) return result;

    result = test_one_enciph5r47g("error, enciph5r47g 2", plaintext_2, crypto_2);
    if (result) return result;

    result = test_one_enciph5r47g("error, enciph5r47g 3", plaintext_3, crypto_3);
    if (result) return result;

    result = test_one_enciph5r47g("error, enciph5r47g 4", plaintext_4, crypto_4);
    if (result) return result;

    result = test_one_enciph5r47g("error, enciph5r47g 5", plaintext_5, crypto_5);
    if (result) return result;

    result = test_one_enciph5r47g("error, enciph5r47g 6", plaintext_6, crypto_6);
    if (result) return result;

    result = test_one_enciph5r47g("error, enciph5r47g 7", plaintext_7, crypto_7);
    if (result) return result;

    result = test_one_enciph5r47g("error, enciph5r47g 8", plaintext_8, crypto_8);
    if (result) return result;

    return SUCCESS;
}
