#include "global.hpp"

void pttomorse(string pttext, string morse[], char alphabet[]){
    int length = pttext.length();
    string temp = " "; // String temporária para amarzenar o código traduzido.
    
    // Converte toda a string em letras minusculas
    transform(pttext.begin(), pttext.end(), pttext.begin(), ::toupper);

    
    for(i = 0; i < length; i++){
        for(j = 0; j < 36; j++){
            if(pttext[i] == alphabet[j]){
                //cout << morse[j] << " ";
                temp += morse[j] + " ";
                break;
            }
        }
    }
    cout << "TEXT: " << pttext << endl;
    cout << "MORSE CODE: " << temp << endl;
}

//string morsetopt(){

//}

void clear_screen(){
    #if defined WIN32
    system("cls");
    #else
    system("clear");
    #endif
}