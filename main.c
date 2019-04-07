#include<stdio.h>

//functions: encrypt substitution cipher, decrypt substitution cipher, decrypt rotation cipher CIPHER TEXT ONLY, decrypt substitution cipher CIPHER TEXT ONLY
void rotate_encrypt (char x[], int k); //function to encrypt using rotation cipher
void rotate_decrypt (char x[], int k); //function to decrypt using rotation cipher
void substitute_encryptM (char x[]);
void substitute_decryptM (char x[]);
void analysis (char x[]);
int frq[53]; // declares global array frq

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
    //substitute_decryptM (x); //calls function to decrypt using substitution cipher
    
    analysis (x);
    
    printf("\n\n");
    int count=1;
    while(count<53) {
        printf("%c: %d\n", frq[count-1], frq[count]);
        count++;
        count++;
    }
    
    
    
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














void analysis (char x[]) {
    //char x[1000] = {"EIKDIR PKI AOXDKCPFC. EIKDIR CINN VR TED TI TPFC CD HI HVC TEIF CEIW OPGI CEAR XPKCAQVNPK EIKD CEIW GAGF'C MASI EAO P MVF, CEIW MPSI EAO P RQKITGKASIK CD UAZ CEAFMR. CEIW GAGF'C MASI EAO P CPFL DK P TPKREAX DK PF Z-TAFM, CEIW MPSI EAO P QPNN HDZ UKDO TEAQE WDV QPF QPNN UDK EINX PFG CEIW GAGF'C MASI EAO P RVXIKXDTIK DK P EIPC KPW, CEIW MPSI EAO PF IZCKP EIPKC. PFG CEPC'R IZCKPDKGAFPKW. CEIKI TANN FISIK QDOI P CAOI TEIF TI GDF'C FIIG P EIKD NALI CEI GDQCDK."};
    //printf("%s\n", x);
    int y=0;
    char A[2] = {'A'}; char B[2] = {'B'}; char C[2] = {'C'}; char D[2] = {'D'}; char E[2] = {'E'}; char F[2] = {'F'}; char G[2] = {'G'};
    char H[2] = {'H'}; char I[2] = {'I'}; char J[2] = {'J'}; char K[2] = {'K'}; char L[2] = {'L'}; char M[2] = {'M'}; char N[2] = {'N'};
    char O[2] = {'O'}; char P[2] = {'P'}; char Q[2] = {'Q'}; char R[2] = {'R'}; char S[2] = {'S'}; char T[2] = {'T'}; char U[2] = {'U'}; 
    char V[2] = {'V'}; char W[2] = {'W'}; char X[2] = {'X'}; char Y[2] = {'Y'}; char Z[2] = {'Z'}; 
    int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0, o=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0, xn=0, yn=0, z=0;
    
    while (x[y]!=NULL) {
        if(x[y]>64 && x[y]<91) {
            if(x[y]==A[0]) {
                a++;
            }
            else if(x[y]==B[0]) {
                b++;
            }
            else if(x[y]==C[0]) {
                c++;
            }
            else if(x[y]==D[0]) {
                d++;
            }
            else if(x[y]==E[0]) {
                e++;
            }
            else if(x[y]==F[0]) {
                f++;
            }
            else if(x[y]==G[0]) {
                g++;
            }
            else if(x[y]==H[0]) {
                h++;
            }
            else if(x[y]==I[0]) {
                i++;
            }
            else if(x[y]==J[0]) {
                j++;
            }
            else if(x[y]==K[0]) {
                k++;
            }
            else if(x[y]==L[0]) {
                l++;
            }
            else if(x[y]==M[0]) {
                m++;
            }
            else if(x[y]==N[0]) {
                n++;
            }
            else if(x[y]==O[0]) {
                o++;
            }
            else if(x[y]==P[0]) {
                p++;
            }
            else if(x[y]==Q[0]) {
                q++;
            }
            else if(x[y]==R[0]) {
                r++;
            }
            else if(x[y]==S[0]) {
            s++;
            }
            else if(x[y]==T[0]) {
                t++;
            }
            else if(x[y]==U[0]) {
                u++;
            }
            else if(x[y]==V[0]) {
                v++;
            }
            else if(x[y]==W[0]) {
                w++;
            }
            else if(x[y]==X[0]) {
                xn++;
            }
            else if(x[y]==Y[0]) {
                yn++;
            }
            else if(x[y]==Z[0]) {
                z++;
            }
            else {
            }
        }
        y++;
    }
    y=0;
    frq[y]='A';
    y++;
    frq[y]=a;
    y++;
    frq[y]='B';
    y++;
    frq[y]=b;
    y++;
    frq[y]='C';
    y++;
    frq[y]=c;
    y++;
    frq[y]='D';
    y++;
    frq[y]=d;
    y++;
    frq[y]='E';
    y++;
    frq[y]=e;
    y++;
    frq[y]='F';
    y++;
    frq[y]=f;
    y++;
    frq[y]='G';
    y++;
    frq[y]=g;
    y++;
    frq[y]='H';
    y++;
    frq[y]=h;
    y++;
    frq[y]='I';
    y++;
    frq[y]=i;
    y++;
    frq[y]='J';
    y++;
    frq[y]=j;
    y++;
    frq[y]='K';
    y++;
    frq[y]=k;
    y++;
    frq[y]='L';
    y++;
    frq[y]=l;
    y++;
    frq[y]='M';
    y++;
    frq[y]=m;
    y++;
    frq[y]='N';
    y++;
    frq[y]=n;
    y++;
    frq[y]='O';
    y++;
    frq[y]=o;
    y++;
    frq[y]='P';
    y++;
    frq[y]=p;
    y++;
    frq[y]='Q';
    y++;
    frq[y]=q;
    y++;
    frq[y]='R';
    y++;
    frq[y]=r;
    y++;
    frq[y]='S';
    y++;
    frq[y]=s;
    y++;
    frq[y]='T';
    y++;
    frq[y]=t;
    y++;
    frq[y]='U';
    y++;
    frq[y]=u;
    y++;
    frq[y]='V';
    y++;
    frq[y]=v;
    y++;
    frq[y]='W';
    y++;
    frq[y]=w;
    y++;
    frq[y]='X';
    y++;
    frq[y]=xn;
    y++;
    frq[y]='Y';
    y++;
    frq[y]=yn;
    y++;
    frq[y]='Z';
    y++;
    frq[y]=z;
    y=0;
    int count=1;
    int counter=3;
    int temp;
    int temporary;
    int counta=0;
    int countb=53;
    
    /*while(count<53) {
        printf("%c: %d\n", frq[count-1], frq[count]);
        count++;
        count++;
    } */
    
    count=1;
    while(counta<100) {
        while (counter<countb) {
            if (frq[count] < frq[counter]) {
                temp = frq[count];
                frq[count] = frq[counter];
                frq[counter] = temp;
                temporary = frq[count-1];
                frq[count-1] = frq[counter-1];
                frq[counter-1] = temporary;
            }
            count++;
            count++;
            counter++;
            counter++;
        }
        count=1;
        counter=3;
        countb--;
        counta++;
    }
    
    
    /*printf("\n\n");
    count=1;
    while(count<53) {
        printf("%c: %d\n", frq[count-1], frq[count]);
        count++;
        count++;
    } */
    
}