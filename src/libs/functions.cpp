#include "global.hpp"

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

void morsetopt(char file[], string morse[], char alphabet[]){
    ifstream myfile;// Arquivo a ser lido.
    myfile.open(strcat(file, ".txt"));

    // Variáveis para manipular o texto.
    string temp = "";
    string text = "";
    
    int index;// Variável de controle.

    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,temp); // Variável temp recebe o texto do arquivo.
            int length = temp.length();
            //cout << temp;

            for(index = 0; index < length; index++){
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
                text += alphabet[index] + position;
                index++;
            }
        }
    }
    myfile.close();
    cout << "Seu arquivo traduzido é: " << endl;
    cout << text << endl;
    
}

void clear_screen(){
    #if defined WIN32
    system("cls");
    #else
    system("clear");
    #endif
}