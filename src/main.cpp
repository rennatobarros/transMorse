#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include "libs/functions.cpp"

int main(void)
{
    char file[20];
    char option;
    int repeat = 1;

    do{
        //clear_screen();

        cout << "Digite '1' para traduzir de português em código Morse.\nDigite '2' para traduzir de código Morse em português." << std::endl;
        cin >> option;

        if(option == '1'){
            cout << "Digite o texto para ser traduzido em Morse: " << endl;
            cin.get();
            getline(cin, pttext);
            //cout << pttext << endl;
            pttomorse(pttext, morse, alphabet);
        }else if(option == '2'){
            cout << "Digite o nome arquivo que será traduzido para português: " << endl;
            cin >> file;
            //morsetopt(file);
        }else{
            cout << "Oops!!! Opção inválida. Tente novamente..." << endl;
            cout << "Digite '1' para traduzir de português em código Morse.\nDigite '2' para traduzir de código Morse em português." << std::endl;
            cin >> option;
        }

        cout << "Gostaria de fazer outra tradução? '1' para continuar e '0' para sair. ";
        cin >> repeat;

    }while(repeat == 1);
    
    cout << "Programa finalizado! " << endl;
    
    return 0;
}