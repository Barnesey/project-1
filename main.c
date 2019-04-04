#include<stdio.h>

//functions: encrypt substitution cipher, decrypt substitution cipher, decrypt rotation cipher CIPHER TEXT ONLY, decrypt substitution cipher CIPHER TEXT ONLY
void rotate_encrypt (char x[], int k);
void rotate_decrypt (char x[], int k);

int main() {
    char x[1000]; //array to hold string
    //sprintf(x, "ATTACK AT DAWN"); //prints the phrase to be encoded to the array "x"  above
    //sprintf(x, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"); //prints the phrase to be encoded to the array "x"  above
    sprintf(x, "HEROES ARE IMPORTANT. HEROES TELL US WHO WE WANT TO BE BUT WHEN THEY MADE THIS PARTICULAR HERO THEY DIDN'T GIVE HIM A GUN, THEY GAVE HIM A SCREWDRIVER TO FIX THINGS. THEY DIDN'T GIVE HIM A TANK OR A WARSHIP OR AN X-WING, THEY GAVE HIM A CALL BOX FROM WHICH YOU CAN CALL FOR HELP AND THEY DIDN'T GIVE HIM A SUPERPOWER OR A HEAT RAY, THEY GAVE HIM AN EXTRA HEART. AND THAT'S EXTRAORDINARY. THERE WILL NEVER COME A TIME WHEN WE DON'T NEED A HERO LIKE THE DOCTOR."); //prints the phrase to be encoded to the array "x"  above
    
    //this loop will convert any inputs that are lower case letters to upper case letters
    int y=0; //loop counter
    while(x[y]!=NULL) { //loop that will continue until the end of the string
        if(x[y]<96 || x[y]>123) { //ensures only lower case letters are having their ascii changed
            y++; //increments loop counter
        } 
        else if(x[y]>96 && x[y]<123) { //ensures only lower case letters are having their ascii changed
            x[y]=x[y]-32; //changes lower case ascii to upper case ascii
            y++; //increments loop counter
        }
    }
    
    int k=-15;
    
    rotate_encrypt (x, k);
    
    k=k-(k*2); //changes encryption key to decode phrase
    
    rotate_decrypt(x, k);
    
    
    
    return 0; 
}




void rotate_encrypt (char x[], int k) {
    //this loop will encrypt a rotation cipher
    if(k<26 && k>-26) { //ensures encryption key is valid
        int y=0; //loop counter
        while(x[y]!=NULL) { //loop that will continue until the end of the string
            if(x[y]>64 && x[y]<91) { //ensures only letters are having their ascii changed
//                printf( "%d -> ", x[y]); //prints the letters ascii value e.g A prints 65
                x[y]=x[y]+k;  //encodes the letter by shunting it according to the encryption key (k)
                if(x[y]<65) { //if encryption shunts to below of letter range, this will shunt to end of letter range
                    x[y]=x[y]+26;
                }
                if(x[y]>90) { //if encryption shunts to above of letter range, this will shunt to beginning of letter range
                    x[y]=x[y]-26;
                }
//                printf("%d\n", x[y]);  //prints new ascii value 
                y++;  //increments loop counter to encode the next letter
            }
            else {  //if ascii value is not for a letter, this will print it unchanged
//                printf("%d\n", x[y]);
                y++;
            }
        }
        printf("%s\n", x); //prints encoded phrase
        }
    else { //if encryption key isnt valid, prints error message
        printf("error: invalid encryption key\n");
    }
}





void rotate_decrypt (char x[], int k) {
    //this loop will decrypt a rotation cipher
    if(k<26 && k>-26) { //ensures encryption key is valid
        int y=0; //loop couner
        while(x[y]!=NULL) {  //loop that will continue until the end of the string
            if(x[y]>64 && x[y]<91) {  //ensures only letters are having their ascii changed
//                printf("%d -> ", x[y]);  //prints the letters ascii value e.g A prints 65
                x[y]=x[y]+k;   //decodes the letter by shunting it according to the decryption key (k)
                if(x[y]>90) { //if encryption shunts to above of letter range, this will shunt to beginning of letter range
                    x[y]=x[y]-26;
                }
                if(x[y]<65) { //if decryption shunts to below of letter range, this will shunt to end of letter range
                    x[y]=x[y]+26;
                }
//                printf("%d\n", x[y]);   //prints new ascii value 
                y++;   //increments loop counter to decode the next letter
            }
            else {  //if ascii value is not for a letter, this will print it unchanged
//                printf("%d\n", x[y]);
                y++; //increments loop counter to decode next letter
            }
        }
        printf("%s", x); //prints decoded phrase
    }
    else { //if encryption key isnt valid, prints error message
        printf("error: invalid decryption key\n");
    }
}