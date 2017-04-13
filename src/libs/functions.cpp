#include "global.hpp"

void pttomorse(string pttext, string morse[], char alphabet[]){
    ofstream myfile;
    int length = pttext.length();
    string temp = ""; // String temporária para amarzenar o código traduzido.
    
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
    //cout << "Texto digitado: " << pttext << endl;
    //cout << "Texto traduzido: " << temp << endl;
    myfile.open("MorseCode.txt");
    myfile << temp << endl;
    myfile.close();
    cout << "Tradução finalizada..." << endl;
    
}

void morsetopt(char file[], string morse[], char alphabet[]){
    int index = 0;
    
    ifstream myfile;
    myfile.open(strcat(file, ".txt"));
    
    string temp = "";
    string text = "";

    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,temp);
            int length = temp.length();
            cout << temp;

            while(index < length){
                // Procura pela atual letra em morse
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
    cout << text << endl;
    //cout << endl;
    myfile.close();
    
}

void clear_screen(){
    #if defined WIN32
    system("cls");
    #else
    system("clear");
    #endif
}