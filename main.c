#include<stdio.h>

//functions: encrypt substitution cipher, decrypt substitution cipher, decrypt rotation cipher CIPHER TEXT ONLY, decrypt substitution cipher CIPHER TEXT ONLY
void rotate_encrypt (char x[], int k); //function to encrypt using rotation cipher
void rotate_decrypt (char x[], int k); //function to decrypt using rotation cipher
void substitute_encryptM (char x[]);
void substitute_decryptM (char x[]);

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
    
/*    int k=-15; //decryption key
    
    rotate_encrypt (x, k); //calls function to encrypt using rotation cipher
    
    k=k-(k*2); //changes encryption key to decode phrase
    
    rotate_decrypt(x, k); //calls function to decrypt using rotation cipher  */
    
    
    substitute_encryptM (x); //calls function to encrypt using substitution cipher
    substitute_decryptM (x); //calls function to decrypt using substitution cipher
  
    
    return 0; 
}






















void rotate_encrypt (char x[], int k) {
    //this loop will encrypt a rotation cipher
    if(k<26 && k>-26) { //ensures encryption key is valid
        int y=0; //loop counter
        while(x[y]!=NULL) { //loop that will continue until the end of the string
            if(x[y]>64 && x[y]<91) { //ensures only letters are having their ascii changed
                x[y]=x[y]+k;  //encodes the letter by shunting it according to the encryption key (k)
                if(x[y]<65) { //if encryption shunts to below of letter range, this will shunt to end of letter range
                    x[y]=x[y]+26;
                }
                if(x[y]>90) { //if encryption shunts to above of letter range, this will shunt to beginning of letter range
                    x[y]=x[y]-26;
                }
                y++;  //increments loop counter to encode the next letter
            }
            else {  //if ascii value is not for a letter, this will print it unchanged
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
                x[y]=x[y]+k;   //decodes the letter by shunting it according to the decryption key (k)
                if(x[y]>90) { //if encryption shunts to above of letter range, this will shunt to beginning of letter range
                    x[y]=x[y]-26;
                }
                if(x[y]<65) { //if decryption shunts to below of letter range, this will shunt to end of letter range
                    x[y]=x[y]+26;
                }
                y++;   //increments loop counter to decode the next letter
            }
            else {  //if ascii value is not for a letter, this will print it unchanged
                y++; //increments loop counter to decode next letter
            }
        }
        printf("%s\n", x); //prints decoded phrase
    }
    else { //if encryption key isnt valid, prints error message
        printf("error: invalid decryption key\n");
    }
}








void substitute_encryptM (char x[]) {
    int y=0;
    char A[2] = {'A'}; char B[2] = {'B'}; char C[2] = {'C'}; char D[2] = {'D'}; char E[2] = {'E'}; char F[2] = {'F'}; char G[2] = {'G'};
    char H[2] = {'H'}; char I[2] = {'I'}; char J[2] = {'J'}; char K[2] = {'K'}; char L[2] = {'L'}; char M[2] = {'M'}; char N[2] = {'N'};
    char O[2] = {'O'}; char P[2] = {'P'}; char Q[2] = {'Q'}; char R[2] = {'R'}; char S[2] = {'S'}; char T[2] = {'T'}; char U[2] = {'U'}; 
    char V[2] = {'V'}; char W[2] = {'W'}; char X[2] = {'X'}; char Y[2] = {'Y'}; char Z[2] = {'Z'}; 
    
    while (x[y]!=NULL) {
        if(x[y]==A[0]) {
            x[y]=P[0];
        }
        else if(x[y]==B[0]) {
            x[y]=H[0];
        }
        else if(x[y]==C[0]) {
            x[y]=Q[0];
        }
        else if(x[y]==D[0]) {
            x[y]=G[0];
        }
        else if(x[y]==E[0]) {
            x[y]=I[0];
        }
        else if(x[y]==F[0]) {
            x[y]=U[0];
        }
        else if(x[y]==G[0]) {
            x[y]=M[0];
        }
        else if(x[y]==H[0]) {
            x[y]=E[0];
        }
        else if(x[y]==I[0]) {
            x[y]=A[0];
        }
        else if(x[y]==J[0]) {
            x[y]=Y[0];
        }
        else if(x[y]==K[0]) {
            x[y]=L[0];
        }
        else if(x[y]==L[0]) {
            x[y]=N[0];
        }
        else if(x[y]==M[0]) {
            x[y]=O[0];
        }
        else if(x[y]==N[0]) {
            x[y]=F[0];
        }
        else if(x[y]==O[0]) {
            x[y]=D[0];
        }
        else if(x[y]==P[0]) {
            x[y]=X[0];
        }
        else if(x[y]==Q[0]) {
            x[y]=J[0];
        }
        else if(x[y]==R[0]) {
            x[y]=K[0];
        }
        else if(x[y]==S[0]) {
            x[y]=R[0];
        }
        else if(x[y]==T[0]) {
            x[y]=C[0];
        }
        else if(x[y]==U[0]) {
            x[y]=V[0];
        }
        else if(x[y]==V[0]) {
            x[y]=S[0];
        }
        else if(x[y]==W[0]) {
            x[y]=T[0];
        }
        else if(x[y]==X[0]) {
            x[y]=Z[0];
        }
        else if(x[y]==Y[0]) {
            x[y]=W[0];
        }
        else if(x[y]==Z[0]) {
            x[y]=B[0];
        }
        else {
        }
        y++;
    }
    printf("%s\n", x);
}




void substitute_decryptM (char x[]) {
    int y=0;
    char A[2] = {'A'}; char B[2] = {'B'}; char C[2] = {'C'}; char D[2] = {'D'}; char E[2] = {'E'}; char F[2] = {'F'}; char G[2] = {'G'};
    char H[2] = {'H'}; char I[2] = {'I'}; char J[2] = {'J'}; char K[2] = {'K'}; char L[2] = {'L'}; char M[2] = {'M'}; char N[2] = {'N'};
    char O[2] = {'O'}; char P[2] = {'P'}; char Q[2] = {'Q'}; char R[2] = {'R'}; char S[2] = {'S'}; char T[2] = {'T'}; char U[2] = {'U'}; 
    char V[2] = {'V'}; char W[2] = {'W'}; char X[2] = {'X'}; char Y[2] = {'Y'}; char Z[2] = {'Z'}; 
    
    while (x[y]!=NULL) {
        if(x[y]==P[0]) {
            x[y]=A[0];
        }
        else if(x[y]==H[0]) {
            x[y]=B[0];
        }
        else if(x[y]==Q[0]) {
            x[y]=C[0];
        }
        else if(x[y]==G[0]) {
            x[y]=D[0];
        }
        else if(x[y]==I[0]) {
            x[y]=E[0];
        }
        else if(x[y]==U[0]) {
            x[y]=F[0];
        }
        else if(x[y]==M[0]) {
            x[y]=G[0];
        }
        else if(x[y]==E[0]) {
            x[y]=H[0];
        }
        else if(x[y]==A[0]) {
            x[y]=I[0];
        }
        else if(x[y]==Y[0]) {
            x[y]=J[0];
        }
        else if(x[y]==L[0]) {
            x[y]=K[0];
        }
        else if(x[y]==N[0]) {
            x[y]=L[0];
        }
        else if(x[y]==O[0]) {
            x[y]=M[0];
        }
        else if(x[y]==F[0]) {
            x[y]=N[0];
        }
        else if(x[y]==D[0]) {
            x[y]=O[0];
        }
        else if(x[y]==X[0]) {
            x[y]=P[0];
       }
        else if(x[y]==J[0]) {
            x[y]=Q[0];
        }
        else if(x[y]==K[0]) {
            x[y]=R[0];
        }
        else if(x[y]==R[0]) {
            x[y]=S[0];
       }
        else if(x[y]==C[0]) {
            x[y]=T[0];
        }
        else if(x[y]==V[0]) {
            x[y]=U[0];
        }
        else if(x[y]==S[0]) {
            x[y]=V[0];
        }
        else if(x[y]==T[0]) {
            x[y]=W[0];
        }
        else if(x[y]==Z[0]) {
            x[y]=X[0];
        }
        else if(x[y]==W[0]) {
            x[y]=Y[0];
        }
        else if(x[y]==B[0]) {
            x[y]=Z[0];
        }
        else {
        }
        y++;
    }
    printf("%s\n", x);
}