//
//  hellu.h
//  CodeGolf
//
//  Created by Ian McLinden on 4/16/17.
//  Copyright © 2017 Ian McLinden. All rights reserved.
//

// Define a file run test for each external script

static char * test_hellu() {
    printf("test_hellu():");
    char outstr[strlen(hellu)*sizeof(char)+10];
    memset(outstr, 0,strlen(hellu)*sizeof(char)+10 );
    
    int run = CAPTURE_RUN_OUTPUT(outstr, "golfs/hellu.py", PYTHON2_PATH);
    ASSERT_SUCCESS("File did not run successfully", run);
    ASSERT_NOT_NULL("Output was null", outstr);
    ASSERT_STRING_NOT_EMPTY("Output was empty", outstr);
    ASSERT_STRING_N_EQUAL("File did not have correct output", hellu, outstr, strlen(hellu));

    return SUCCESS;
}
