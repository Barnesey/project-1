#include<stdio.h>

//functions: encrypt rotation cipher, decrypt rotation cipher, encrypt substitution cipher, decrypt substitution cipher, decrypt rotation cipher CIPHER TEXT ONLY, decrypt substitution cipher CIPHER TEXT ONLY

int main() {
    char x[100]; //array to hold string
    sprintf(x, "ATTACK AT DAWN"); //prints the phrase to be encoded to the array "x"  above
    //sprintf(x, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"); //prints the phrase to be encoded to the array "x"  above
    
    int y=0; //loop counter
    
    //this loop will convert any inputs that are lower case letters to upper case letters
    while(x[y]!=NULL) { //loop that will continue until the end of the string
        if(x[y]<96 || x[y]>123) { //ensures only lower case letters are having their ascii changed
            y++; //increments loop counter
        } 
        else if(x[y]>96 && x[y]<123) { //ensures only lower case letters are having their ascii changed
            x[y]=x[y]-32; //changes lower case ascii to upper case ascii
            y++; //increments loop counter
        }
    }
    
    

    
    int k=-15; //encryption key
    
    
    //this loop will encrypt a rotation cipher
    if(k<26 && k>-26) { //ensures encryption key is valid
        y=0; //resets loop counter
        while(x[y]!=NULL) { //loop that will continue until the end of the string
            if(x[y]>64 && x[y]<91) { //ensures only letters are having their ascii changed
                printf("%d -> ", x[y]); //prints the letters ascii value e.g A prints 65
                x[y]=x[y]+k;  //encodes the letter by shunting it according to the encryption key (k)
                if(x[y]<65) { //if encryption shunts to below of letter range, this will shunt to end of letter range
                    x[y]=x[y]+26;
                }
                if(x[y]>90) { //if encryption shunts to above of letter range, this will shunt to beginning of letter range
                    x[y]=x[y]-26;
                }
                printf("%d\n", x[y]);  //prints new ascii value 
                y++;  //increments loop counter to encode the next letter
            }
            else {  //if ascii value is not for a letter, this will print it unchanged
                printf("%d\n", x[y]);
                y++;
            }
        }
        printf("%s\n", x); //prints encoded phrase
        }
    else { //if encryption key isnt valid, prints error message
        printf("error: invalid encryption key\n");
    }




    k=k-(k*2); //changes encryption key to decode phrase
    
    
    //this loop will decrypt a rotation cipher
    if(k<26 && k>-26) { //ensures encryption key is valid
        y=0; //resets loop couner
        while(x[y]!=NULL) {  //loop that will continue until the end of the string
            if(x[y]>64 && x[y]<91) {  //ensures only letters are having their ascii changed
                printf("%d -> ", x[y]);  //prints the letters ascii value e.g A prints 65
                x[y]=x[y]+k;   //decodes the letter by shunting it according to the decryption key (k)
                if(x[y]>90) { //if encryption shunts to above of letter range, this will shunt to beginning of letter range
                    x[y]=x[y]-26;
                }
                if(x[y]<65) { //if decryption shunts to below of letter range, this will shunt to end of letter range
                    x[y]=x[y]+26;
                }
                printf("%d\n", x[y]);   //prints new ascii value 
                y++;   //increments loop counter to decode the next letter
            }
            else {  //if ascii value is not for a letter, this will print it unchanged
                printf("%d\n", x[y]);
                y++; //increments loop counter to decode next letter
            }
        }
        printf("%s", x); //prints decoded phrase
    }
    else { //if encryption key isnt valid, prints error message
        printf("error: invalid decryption key\n");
    }
    
    
    
    
    
    
    return 0; 
}