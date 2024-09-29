#include <stdio.h>
#include <string.h>

int isalpha(char string[]);
int occ(char string[]);


int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Usage: .\\substitutioncipher.exe {input key} \n");
        return 1;

    } else if (strlen(argv[1]) != 26){
        printf("Error 1: Key must be exactly 26 characters \n");
        return 1;

    } else if (!isalpha(argv[1])){
        printf("Error 2: Key Characters must only contain alphabetic characters \n");
        return 1;
    
    }else if (!occ(argv[1])){
        printf("Error 3: Each key Characters must only occur once");
        return 1;
    } else {
        printf("%s is completely valid \n", argv[1]);
    }

    //Validity Check done -> Encrypting
    char plaintext[200];
    char ciphertext[200];
    int sub;
    printf("Plaintext: ");

    fgets(plaintext, sizeof(plaintext), stdin); 
    plaintext[strcspn(plaintext, "\n")] = '\0';

    int lentext = strlen(plaintext);

    printf("%i\n", lentext);
    
    
    for(int i = 0; i < lentext; i++){
        char cc = plaintext[i];
        

        if(cc >= 'A' && cc <= 'Z'){
            sub = cc - 'A';
            if(argv[1][sub] >= 'a'){
                    ciphertext[i] = argv[1][sub] - 32;
                } else {
                 ciphertext[i] = argv[1][sub];
                }
        } else if (cc >= 'a' && cc<= 'z'){
            sub = cc - 'a';
                if(argv[1][sub] <= 'Z'){
                    ciphertext[i] = argv[1][sub] + 32;
                } else {
                 ciphertext[i] = argv[1][sub];
                }
        } else {
            ciphertext[i] = cc;
        }
    }
// end of ciphering
    ciphertext[lentext] = '\0';

    printf("Ciphertext: %s", ciphertext);    
    
}

//isalpha
int isalpha(char string[]){
    int len = strlen(string);
    
    if(len == 0){
        return 0;
    } 

    for(int i = 0; i < len; i++){
        if((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122)){
            continue;
        } else 
            return 0;
        }

        return 1;
    }

//occurence checker
int occ(char string[]){
    
    int len = strlen(string);

    int i;

    for(i = 1; i < len; i++){
        for(int j = 0; j < i; j++){
            if(string[i] == string[j]){
                return 0;
            }
        }
    }

    return 1;
    
}
