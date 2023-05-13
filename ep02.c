#include <stdio.h>

/*double polyval(double pol[], int size, double x){
    double counter = 0;
    int i;
    int expo = 1;
    for (i = 0 ; i < size; i++){
        counter += (pol[i]*expo);
        expo = expo * x;
    }
    printf("%f\n", counter);
    return counter;
}

int main(){
    double pol[] = {1,2,3}; 
    polyval(pol,3,2);
    return 0;
}*/
/*#define MAX 2000

int moda(){
    int i, currNum, numbers[MAX], result;
    for (i=0; i <= MAX; i++){
        numbers[i] = 0;
    }
    scanf("%d", &currNum);
    while (currNum >=0){
        numbers[currNum]++;
        scanf("%d", &currNum);
    }
    result = 0;
    for(i=0; i<MAX; i++){
        if (numbers[i]>numbers[result]){
            result = i;
        }
    }
    printf("%d\n", result);
    return 0;
}

int main(){
    moda();
    return 0;
}*/

/*int contaUnicos(int v[], int size){
    int i,j, count = 0;
    for (i = 0; i<size; i++){
        int unico = 0;
        for(j = 0; j < size;j++){
            if(v[i] == v[j]){
                unico ++;
            }
        }
        if (unico == 1){
            count++;
        }
    }
    printf("%d\n", count);
    return count;
}

int main(){
    int v[] = {3,6,4,6,6,4,5, 8};
    contaUnicos(v, 8);
    return 0;

}*/

int digitosRepetidos(char s1[], char s2[]){

}

/*int numMoedas(float v[], int size, float amount){
    int i = 0;
    int counter = 0;
    float x = amount;
    while (i < size){
            if (x - v[i] >= 0){
            x= x - v[i];
            counter++;
            }
            else if (x-v[i]<0){
                i++;
            }
    }
    printf("%d\n", counter);
    return counter;
}

int main(){
    float v[] = {2,1,0.5, 0.2, 0.1, 0.05,0.02,0.01};
    numMoedas(v, 8, 5.63);
    return 0;
}*/

/*int digitosRepetidos(char s[]) {
    int i = 0, digitos[10]= {0}, counter=0, k;
    while(s[i] != '\0') {
        if ((s[i] >= '0') && (s[i] <= '9')) {
            k = s[i]-'0';
            digitos[k]++;
        }
        i++;
    }
    for (i = 0; i <= 9; i++) {
        if (digitos[i] > 1) {
            counter++;
        }
        
    }
    printf("%d", counter);
    return counter;
}

int main(){
    char s [] = "IAED é a melhor UC desde 1991 até 2021.";
    digitosRepetidos(s);
    return 0;
}*/

/*void produtoInterno(int v1[], int v2[], int size){
    int i, counter = 0;
    for (i = 0; i<size ;i++){
        counter += (v1[i] * v2[i]);
    }
    printf("%d\n", counter);
}

int main(){
    int v1[] = {0,2,4};
    int v2[] = {1,3,5};
    produtoInterno(v1, v2, 3);
    return 0;
}*/

/*char maiusculaFrequente(char s[]){
    int maiusculas[26] = {0};
    char result;
    int i = 0;
    int k = 0;
    while (s[i] != '\0'){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            maiusculas[s[i] - 'A'] = maiusculas[s[i]- 'A']+1; 
        }
        i++;
    }
    for (int j = 0; j<26; j++){
        if (maiusculas[j] > k){
            k = maiusculas[j];
            result = j + 'A';
        }
        
    }
    printf("%c\n", result);
    return result;
}

int main(){
    char s[] = "LEIC e IST: juntos desde 1989";
    maiusculaFrequente(s);
    return 0;
}*/

/*int seqCrescente(int v[], int size){
    int counter = 1;
    int numcounter = 0;
    for (int i = 0; i<size-1; i++){
        if (v[i] < v[i+1]){
            counter++;
        }
        else{
            if(counter > numcounter){
                numcounter = counter;
            }
            counter = 1;
        }
    }
    return numcounter;
}

int main(){
    int v[] = {1,2,1,10,12,18,7,8,9};
    seqCrescente(v,9);
    return 0;
}*/

/*int semOcorrencia(int v[], int size){
    int possnotas[21] = {0};
    int counter = 0;
    for (int i = 0; i < size; i++){
        possnotas[v[i]] = 1;
    }
    for (int j = 0; j < 21; j++){
        if (possnotas[j] == 0){
            counter++;
        }
    }
    printf("%d\n",counter);
    return counter;
}

int main(){
    int v[]={1,1,1,2,2,14,15,16,17};
    semOcorrencia(v,9);
    return 0;
}*/

