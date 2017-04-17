//
//  minunit.h
//  CodeGolf
//
//  Created by Ian McLinden on 4/15/17.
//  Copyright © 2017 Ian McLinden. All rights reserved.
//

#ifndef minunit_h
#define minunit_h


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SUCCESS (0)
#define FAILURE (-1)

// Based on Jera's MinUnit C Test Framework -- http://www.jera.com/techinfo/jtns/jtn002.html
#define ASSERT(message, test) do { int result=test; printf("%s",(result?"+":"-")); if (!result) return message; } while (0)
#define ASSERT_SUCCESS(msg,var)                         ASSERT(msg, var==SUCCESS)
#define ASSERT_FAILURE(msg,var)                         ASSERT(msg, var!=SUCCESS)
#define ASSERT_NULL(msg,var)                            ASSERT(msg, var==NULL)
#define ASSERT_NOT_NULL(msg,var)                        ASSERT(msg, var!=NULL)

// Integer
#define ASSERT_INT_EQUAL(msg,var1,var2)                 ASSERT(msg, var1==var2)
#define ASSERT_INT_NOT_EQUAL(msg,var1,var2)             ASSERT(msg, var1!=var2)

// String
#define ASSERT_STRING_EMPTY(msg,str)                    ASSERT(msg, strlen(str)==0)
#define ASSERT_STRING_NOT_EMPTY(msg,str)                ASSERT(msg, strlen(str)>0)
#define ASSERT_STRING_EQUAL(msg,str1,str2)              ASSERT(msg, strcmp(str1,str2)==0)
#define ASSERT_STRING_NOT_EQUAL(msg,str1,str2)          ASSERT(msg, strcmp(str1,str2s)!=0)
#define ASSERT_STRING_N_EQUAL(msg,str1,str2,len)        ASSERT(msg, strncmp(str1,str2,len)==0)
#define ASSERT_STRING_N_NOT_EQUAL(msg,str1,str2,len)    ASSERT(msg, strncmp(str1,str2,len)!=0)

#define RUN_TEST(test) do { char *message = test(); tests_run++; printf("\n"); if (message) return message; } while (0)

// Redirect prints for testing
#define CAPTURE_RUN_OUTPUT(out,name,lang) test_file(name,lang,out)
#define CAPTURE_PRINT_OUTPUT(out,func,args...) ({int ret,std_save=capture(out); func(args); ret=uncapture(std_save); ret;})

extern int tests_run;
int tests_run = 0;

int test_file(char *f_name, char *ex_lang, char *f_output) {    
    char filepath[(strlen(ex_lang)+strlen(" ./")+strlen(f_name))*sizeof(char)];
    sprintf(filepath, "%s ./%s",ex_lang,f_name);

    FILE *fp = popen(filepath, "r");
    if (fp == NULL) {
        printf("\nFailed to run %s.",f_name);
        return FAILURE;
    }

    while (fgets(filepath, (int)sizeof(filepath)-1, fp) != NULL) {
        if (sprintf(f_output+strlen(f_output),"%s", filepath) < 0) {
            printf("\nFailed to write to output string.");
            return FAILURE;
        }
    }
    
    pclose(fp);
    return SUCCESS;
}

int capture(char *f_output) {
    fflush(stdout); //clean everything first
    int stdout_save = dup(STDOUT_FILENO); //save the stdout state
    if (stdout_save == -1) return FAILURE;
    if ( freopen("NUL", "a", stdout) == NULL ) return FAILURE; //redirect stdout to null pointer
    if ( setvbuf(stdout, f_output, _IOFBF, 1024) ) return FAILURE; //set buffer to stdout
    return stdout_save;
}

int uncapture(int stdout_save) {
    if (stdout_save==FAILURE) {
        return FAILURE;
    }
    if ( freopen("NUL", "a", stdout) == NULL ) return FAILURE; //redirect stdout to null again
    if ( dup2(stdout_save, STDOUT_FILENO) == -1) return FAILURE; //restore the previous state of stdout
    remove("NUL");
    return SUCCESS;
}

#endif /* minunit_h */
