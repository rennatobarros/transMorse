/**
 *  \file functions.cpp
 *  \brief Arquivo com as funções essenciais do programa.
 *
 */

#include "global.hpp" /** Variáveis globais. */

/** 
 * Função que traduz de Português para Morse
 *
 * \brief Função para traduzir de PT para Morse
 * @param pttext Texto digitado pelo usuário
 * @param morse[] Vetor de string com o alfabeto Morse
 * @param char[] Vetor de char com o alfabeto em Português
 * \return Nada
*/

void pttomorse(string pttext, string morse[], char alphabet[]){
    int i, j;
    
    ofstream myfile;// Arquivo a ser gerado.
    int length = pttext.length();
    string temp = ""; // String temporária para amarzenar o código traduzido.
    
    // Converte toda a string em letras minusculas.
    transform(pttext.begin(), pttext.end(), pttext.begin(), ::toupper);

    // Percorre cada letra da string recebida e faz a tradução.
    for(i = 0; i < length; i++){
        for(j = 0; j < 36; j++){
            if(pttext[i] == alphabet[j]){
                //cout << morse[j] << " ";
                temp += morse[j] + " ";
                break;
            }
        }
    }
    //cout << "Texto digitado: " << pttext << endl;
    //cout << "Texto traduzido: " << temp << endl;
    myfile.open("MorseCode.txt");
    myfile << temp << endl;
    myfile.close();
    cout << "Arquivo 'MorseCode.txt' gerado!!!!" << endl;
    cout << "Tradução finalizada..." << endl;
    
}


/** 
 * Função que traduz de Morse para Português
 *
 * \brief Função para traduzir de Morse para PT
 * @param file[] Nome do arquivo informado pelo usuário
 * @param morse[] Vetor de string com o alfabeto Morse
 * @param char[] Vetor de char com o alfabeto em Português
 * \return Nada
*/

void morsetopt(char file[], string morse[], char alphabet[]){
    ifstream myfile;// Arquivo a ser lido.
    myfile.open(strcat(file, ".txt"));

    // Variáveis para manipular o texto.
    string temp = "";
    string text = "";
    
    int index = 0;// Variável de controle.

    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,temp); // Variável temp recebe o texto do arquivo.
            int length = temp.length();
            //cout << temp;

            while(index < length){
                // Procura pela atual letra em morse.
                string letter = "";
                while(temp[index] != ' ' && index < length){
                    letter += temp[index++];
                }

                // Procura pela atual letra no alfabeto morse
                int position = 0;
                while(morse[position] != letter && position < 36){
                    position++;
                }
                text += 'A' + position;
                index++;
            }
        }
    }
    myfile.close();
    cout << "Seu arquivo traduzido é: " << endl;
    cout << text << endl;
    
}
/**
     *  \brief Função para limpar a tela
     *
     *  Essa função consegue limpar a tela do console em qualquer SO
     *
     *  \return Nada
     */

void clear_screen(){
    #if defined WIN32
    system("cls");
    #else
    system("clear");
    #endif
}