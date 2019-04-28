#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//functions: decrypt rotation cipher CIPHER TEXT ONLY, decrypt substitution cipher CIPHER TEXT ONLY
void rotate_encrypt (char x[], int k); //function to encrypt using rotation cipher
void rotate_decrypt (char x[], int k); //function to decrypt using rotation cipher
void substitute_encryptM (char x[]); //function to encrypt using substitution cipher - manual selection of key
void substitute_decryptM (char x[]); //function to decrypt using substitution cipher - manual selection of key
void analysis (char x[]); //analyses frequency of letters in a string for statistical decryption
void substitute_decrypt_analysis (); //function to decrypt using substitution cipher statistically
void rotate_decrypt_brute (); //function to decrypt rotation cipher
int frq[53]; // declares global array frq to hold the frequency of letters for statistical decryption
char str[1000]; //global array to hold string
char x[1000]; //global array to hold string

void cleanup (); //function just to clean up main REPLACE WHEN FINISHED!!!!!!!!!!!!!

int main() {
    FILE *input;
    input=fopen("input.txt", "r");
    fscanf(input, "%[^\n]", &x);
    
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
    sprintf(str, "%s", x);
    
    
    int interface;
    int k;
    printf("  Select an option then press <enter>.\n1: Encrypt using a rotation cipher.\n2: Decrypt using rotation cipher (known key).\n3: Encrypt using substitution cipher.\n4: Decrypt using substitution cipher (known key).\n5: Decrypt substitution cipher analytically.\n6: Decrypt rotation cipher with brute force and some analysis.\n");
    scanf("%d", &interface);
    switch(interface) {
        case 1: printf("enter key\n"); scanf("%d", &k); rotate_encrypt (x, k); break; //calls function to encrypt using rotation cipher
        case 2: printf("enter key\n"); scanf("%d", &k); rotate_decrypt (x, k); break; //calls function to decrypt using rotation cipher 
        case 3: substitute_encryptM (x); break; //calls function to encrypt using substitution cipher
        case 4: substitute_decryptM (x); break; //calls function to decrypt using substitution cipher
        case 5: substitute_decrypt_analysis (); break; //calls function to decrypt using substitution cipher statistically
        case 6: rotate_decrypt_brute (); break; //calls function to decrypt rotation cipher using brute force method
        default: printf("invalid input\n"); break;
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
        FILE *output;
        output=fopen("output.txt", "w");
        fprintf(output, "%s", x); 
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
        FILE *output;
        output=fopen("output.txt", "w");
        fprintf(output, "%s", x); 
    }
    else { //if encryption key isnt valid, prints error message
        printf("error: invalid decryption key\n");
    }
}








void substitute_encryptM (char x[]) {
    int y=0;
    int z=0;
    char key[27] = {"PHQGIUMEAYLNOFDXJKRCVSTZWB"}; //key for encryption
    char alpha[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //alphabet for comparison
    while(x[z]!=NULL) { //loop continues until end of message
        while(y<=26) { //this loop will continue through the alphabet
            if(x[z]==alpha[y]) { //changes the letter according to the key. e.g. 'A' becomes 'P', 'B' becomes 'H', etcetera
                x[z]=key[y];
                break; //breaks out of the first while loop
            }
            y++; //increments counter if the letter of the message being checked doesnt become the letter of the key being checked
        }
        y=0; //resets loop counter/alphabet counter to restart inner loop
        z++; //increments for this loop and to check the next letter of the message
    } 
    printf("%s\n", x);
    FILE *output;
    output=fopen("output.txt", "w");
    fprintf(output, "%s", x);
}




void substitute_decryptM (char x[]) {
    int y=0;
    int z=0;
    char key[27] = {"PHQGIUMEAYLNOFDXJKRCVSTZWB"}; //key for decryption
    char alpha[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //alphabet for comparison
    while(x[z]!=NULL) { //loop continues until end of message
        while(y<=26) { //this loop will continue through the alphabet
            if(x[z]==key[y]) { //changes the letter according to the key. e.g. 'P' becomes 'A', 'H' becomes 'B', etcetera
                x[z]=alpha[y];
                break; //breaks out of the first while loop
            }
            y++; //increments counter if the letter of the message being checked doesnt become the letter of the key being checked
        }
        y=0; //resets loop counter/alphabet counter to restart inner loop
        z++; //increments for this loop and to check the next letter of the message
    } 
    printf("%s\n", x); //prints decrypted message
    FILE *output;
    output=fopen("output.txt", "w");
    fprintf(output, "%s", x);
}














void analysis (char x[]) {
    //char x[1000] = {"EIKDIR PKI AOXDKCPFC. EIKDIR CINN VR TED TI TPFC CD HI HVC TEIF CEIW OPGI CEAR XPKCAQVNPK EIKD CEIW GAGF'C MASI EAO P MVF, CEIW MPSI EAO P RQKITGKASIK CD UAZ CEAFMR. CEIW GAGF'C MASI EAO P CPFL DK P TPKREAX DK PF Z-TAFM, CEIW MPSI EAO P QPNN HDZ UKDO TEAQE WDV QPF QPNN UDK EINX PFG CEIW GAGF'C MASI EAO P RVXIKXDTIK DK P EIPC KPW, CEIW MPSI EAO PF IZCKP EIPKC. PFG CEPC'R IZCKPDKGAFPKW. CEIKI TANN FISIK QDOI P CAOI TEIF TI GDF'C FIIG P EIKD NALI CEI GDQCDK."}; //here  for writing separately commented out when put into function
    //printf("%s\n", x);
    int y=0;
    //creating a bunch of strings containing one letter each for analysis
    char A[2] = {'A'}; char B[2] = {'B'}; char C[2] = {'C'}; char D[2] = {'D'}; char E[2] = {'E'}; char F[2] = {'F'}; char G[2] = {'G'};
    char H[2] = {'H'}; char I[2] = {'I'}; char J[2] = {'J'}; char K[2] = {'K'}; char L[2] = {'L'}; char M[2] = {'M'}; char N[2] = {'N'};
    char O[2] = {'O'}; char P[2] = {'P'}; char Q[2] = {'Q'}; char R[2] = {'R'}; char S[2] = {'S'}; char T[2] = {'T'}; char U[2] = {'U'}; 
    char V[2] = {'V'}; char W[2] = {'W'}; char X[2] = {'X'}; char Y[2] = {'Y'}; char Z[2] = {'Z'}; 
    //creates a bunch of integers to track frequency
    int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0, o=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0, xn=0, yn=0, z=0;
    
    while (x[y]!=NULL) { //continues until end of message
        if(x[y]>64 && x[y]<91) { //keeps track of letters only (uses ascii)
            if(x[y]==A[0]) { //if the character is "A", increments "a"
                a++;
            }
            else if(x[y]==B[0]) { //if the character is "B", increments "b"
                b++;
            }
            else if(x[y]==C[0]) { //etcetera
                c++;
            }
            else if(x[y]==D[0]) { //etcetera
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
        y++; //increments y to continue loop
    }
    y=0;
    frq[y]='A'; //assigns "A", to frq[0]
    y++;
    frq[y]=a; //assigns how many times "A" appears to frq[1]
    y++;
    frq[y]='B'; //assigns "B", to frq[2]
    y++;
    frq[y]=b; //assigns how many times "B" appears to frq[3]
    y++;
    frq[y]='C'; //etcetera
    y++;
    frq[y]=c; //etcetera
    y++;
    frq[y]='D'; //etcetera
    y++;
    frq[y]=d; //etcetera
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
    //declares/resets integers to order frq
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
    while(counta<100) { //repeats for 100 iterations
        while (counter<countb) { //
            if (frq[count] < frq[counter]) { //checks which number is bigger
                //assigns the greater number sooner in the array
                temp = frq[count]; 
                frq[count] = frq[counter];
                frq[counter] = temp;
                //assigns corresponding letters also sooner in the array
                temporary = frq[count-1];
                frq[count-1] = frq[counter-1];
                frq[counter-1] = temporary;
            }
            //increments counters twice to allow for the letters
            count++;
            count++;
            counter++;
            counter++;
        }
        //resets counters to repeat loop
        count=1;
        counter=3;
        countb--;
        counta++; //increments counter for this loop
    }
    
    
    /*printf("\n\n");
    count=1;
    while(count<53) {
        printf("%c: %d\n", frq[count-1], frq[count]);
        count++;
        count++;
    } */
    
}









void substitute_decrypt_analysis () {
    //decrypts message statistically
    char alph[27] = {"ETAOINSHRDLUCMWFGYPBVKJXQZ"}; //alphabet in order of most common letters
    //char test[27] = {"IPCEKADFGTNOWMRQSVXZHULBJY"}; //most common letters of encrypted moffat to check code
    analysis (x); //calls analysis function for frequency of letters
    int y=1;
    /*printf("\n\n");
    while (y<53) {
        printf("%c: %d\n", frq[y-1], frq[y]);
        y++;
        y++;
    } */
    
    y=0;
    int i=0;
    int z=0;
    int a=0;
    //int b=0;
    int counter=0;
    int size = sizeof(x)/sizeof(x[0]); //calculates the how many characters there are in "x" (for how many times to run loop)
    size+=2; //adds 2 to the loop counter condition to make sure every letter is changed
    //char temp[1000];
    while(y<=size) {
        while(counter<26) {
            if(x[z]==frq[i]) { //checks whether the character to be decoded is the same as the character of "frq" being checked
                x[z]=alph[a]; //if so, makes the tested character equal to the equivalently frequent letter
                //printf("%s\n", test); //prints rectified (partially) string
                /*if(x[b]!=NULL) {
                    temp[b]=x[b];
                    b++;
                } */
                break; //breaks out of first while loop
            }
            //if condition not fulfillded, increments relevant counters
            counter++;
            i++; //incremented twice due to letters and numbers
            i++;
            a++;
        }
        y++; //increments y to continue this loop
        z++; //increments z to check the next letter of the code
        //resets relevant counters to restart nested loop
        i=0;
        counter=0;
        a=0;
    }
    printf("\n%s\n", x); //prints decoded message
    FILE *output;
    output=fopen("output.txt", "w");
    fprintf(output, "%s", x);
}






void rotate_decrypt_brute () {
    int y=0; //loop couner
    int k=0;
    char A[] = {" A "};
    char I[] = {" I "};
    while(k<26) {
        //this loop will decrypt a rotation cipher
        if(k<26 && k>-26) { //ensures encryption key is valid
            while(x[y]!=NULL) {  //loop that will continue until the end of the string
                if(x[y]>64 && x[y]<91) {  //ensures only letters are having their ascii changed
                    x[y]=x[y]+k;   //decodes the letter by shunting it according to the decryption key (k)
                    if(x[y]>90) { //if encryption shunts to above of letter range, this will shunt to beginning of letter range
                        x[y]=x[y]-26;
                    }
                    if(x[y]<65) { //if decryption shunts to below of letter range, this will shunt to end of letter range
                        x[y]=x[y]+26;
                    }
                    //y++;   //increments loop counter to decode the next letter
                }
                else {  //if ascii value is not for a letter, this will print it unchanged
                    //y++; //increments loop counter to decode next letter
                }
                y++;
            }
            if(strstr(x, A)!=NULL) {
                printf("%s\n", x); //prints decoded phrase
                FILE *output;
                output=fopen("output.txt", "a");
                fprintf(output, "%s", x); 
            }
            if(strstr(x, I)!=NULL) {
                printf("%s\n", x); //prints decoded phrase
                FILE *output;
                output=fopen("output.txt", "a");
                fprintf(output, "%s", x); 
            }
        }
        else { //if encryption key isnt valid, prints error message
            printf("error: invalid decryption key\n");
        }
        k++;
        y=0;
        sprintf(x, "%s", str);
    }
}