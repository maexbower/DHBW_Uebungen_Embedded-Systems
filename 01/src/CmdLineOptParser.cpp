//
// Created by max on 09.03.17.
//


#include "../include/OptParser.h"

bool CmdLineOptParser::Parse ( int argc , char * argv [])
{
    bool returnval = true;
    for(int i = 0; i < argc; i++) {
        if (argv[i][0] != '-') {
            //Überspringe ungültiges Argument - vor allem der Programmpfad in argv[0].
            continue;
        } else {
            //Prüfe ob info im gleichen Argv liegt.
            if (argv[i][2] == '\0') {
                //Wert befindet sich in nächstem argv
                //Prüfe ob es noch ein weiteres argv gibt.
                if (argc > i + 1) {
                    //Prüfe ob im nächsten Argv wieder ein Parameter beginnt.
                    if (argv[i + 1][0] == '-') {
                        returnval &= Option(argv[i][1], "");
                    }else{
                        returnval &= Option(argv[i][1], argv[i+1]);
                        //Überspringe nächstes, da bereits verarbeitet
                        i++;
                    }
                } else {
                    //Kein weiteres Argv vorhanden.
                    returnval &= Option(argv[i][1], "");
                }
            }else{
                //info befindet sich im gleichen Argv
                if(argv[i][2] == '=')
                {
                    returnval &= Option(argv[i][1], &argv[i][3]);
                }else{
                    returnval &= Option(argv[i][1], &argv[i][2]);
                }
            }
        }

    }
    return returnval;
}
bool CmdLineOptParser::Option ( const char c, const char * info)
{
    //gibt nur false zurück, wenn entweder c nicht gesetzt ist oder wenn info leer ist
    return !(c == '\0' || info[0] == '\0');
}
