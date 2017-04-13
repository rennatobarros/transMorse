using namespace std;

// Array de char com todo o alfabeto e os números decimais.
char alphabet[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
                    'Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6',
                    '7','8','9','0'};

// Array de string com todo o alfabeto e os números decimais.
string morse[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", 
                    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

string pttext; //String que recebe o texto em PT a ser traduzido.