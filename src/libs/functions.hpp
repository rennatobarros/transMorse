#include "global.hpp"

//string pttomorse(){

//}

//string morsetopt(){

//}

void clear_screen(){
    #if defined WIN32
    system("cls");
    #else
    system("clear");
    #endif
}