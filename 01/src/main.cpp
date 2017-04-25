#include <iostream>
#include "../include/OptParser.h"
int main( int argc , char * argv []) {
    CmdLineOptParser parser;
    if(parser.Parse(argc, argv))
    {
        fprintf(stdout, "Parse erfolgreich!\n");
    }else{
        fprintf(stdout, "Parse nicht erfolgreich!\n");
    }
    return 0;
}
