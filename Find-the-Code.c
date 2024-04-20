#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void posizione_numero (int cod[5],int num){
    int controllo = 0;
            for (int i = 0;i<5;i++){
                if (num == cod[i]){
                    controllo++;
                }
            }
            switch (controllo){
            case 0:
            printf ("Non c'e' questo numero\n");
            break;
            case 1:
            printf ("Numero giusto ma nella posizione sbagliata\n");
            break;
            case 2:
            printf ("Questo numero c'e' due volte ma lo hai messo nella posizione sbagliata\n");
            break;
            case 3:
            printf ("Questo numero c'e' tre volte ma lo hai messo nella posizione sbagliata\n");
            break;
            case 4:
            printf ("Questo numero c'e' quattro volte ma lo hai messo nella posizione sbagliata\n");
            break;
        }
    }
void posizione_numero_giusto (int cod[5],int num[5], int doppioni, int controllo, int corretto){
            for (int i = 0;i<5;i++){
                        if (corretto == cod[i]){
                            controllo++;            
                        }
                        if (controllo > 1) {
                            i = 5;
                        }
                        
                    }
            
            if (controllo > 1){
                for (int i = 0; i<5;i++){
                    if (corretto == num[i] && corretto == cod[i] && num[i] == cod[i]){
                        doppioni++;
                        }
                    }
                }
            if (doppioni > 1){
                switch (doppioni){
                    case 2:
                    printf ("Entrambi i numeri in posizione corretta\n");
                    break;
                    case 3:
                    printf ("Tutti e 3 i numeri in posizione corretta\n");
                    break;
                    case 4:
                    printf ("Tutti e 4 i numeri in posizione corretta\n");
                    break;
                    case 5:
                    printf ("Tutti e 5 i numeri in posizione corretta\n");
                    break;
                }
            }
              else {  
                  switch (controllo){
                    case 1:
                    printf ("Numero nella posizione corretta\n");
                    break;
                    case 2:
                    printf ("Numero in posizione corretta ma ce n'è un'altro\n");
                    break;
                    case 3:
                    printf ("Numero in posizione corretta ma ce ne sono altri 2\n");
                    break;
                    case 4:
                    printf ("Numero in posizione corretta ma ce ne sono altri 3\n");
                    break;
                    case 5:
                    printf ("Numero in posizione corretta ma ce ne sono altri 4\n");
                    break;
                  }   
                }
            }
            
void numeri_trovati (int cod[5],int num[5]){
        int quanti_numeri = 0;
        for (int i = 0; i<5;i++){
            if (num[i] == cod[i]){
                quanti_numeri++;
            }
        }
        switch (quanti_numeri){
            case 0:
            printf ("Non ne hai preso uno giusto, complimenti");
            break;
            case 1:
            printf ("Ne hai preso uno almeno, non fai cosi' schifo");
            break;
            case 2:
            printf ("Ne hai presi due, meglio di molti, ma fai ancora un po' schifo");
            break;
            case 3:
            printf ("Dai ne hai presi 3, complimenti, non fai cosi' schifo ma puoi fare di meglio");
            break;
            case 4:
            printf ("Ne hai presi 4 giusti? Mi sorpendi, grande soldato");
            break;
            case 5:
            printf ("Spiegami come ne hai presi 5, stai usando qualcosa di illegale? Dai ammettilo");
            break;
        }
    }

int cod_corretto (int cod[5],int num[5],int tent_completi){
    int correzione = 0;
     for (int i = 0; i<5;i++){
            if (num[i] == cod[i]){
                correzione++;
            }
        }
        if (correzione == 5){
            tent_completi = 5;
        }
        return tent_completi;
    }



int main() {
    srand(time(NULL));
    int codice[5];
    int numero[5];
    for (int i = 0;i<5;i++){
        codice[i] = rand() % 10;
    }
    for (int i = 0; i<5; i++) {
        numero [i] = 10;
    }
    printf ("Benvenuto in indovina il codice simulator, hai quattro tentativi per prendere un codice casuale\n");
    printf ("Il codice ha 5 cifre\n");
    for (int tentativi = 1; tentativi < 5;tentativi++){
        int doppioni = 0;
        int controllo = 0;
        for (int i = 1; i<6;i++){
            printf("\nposizione %d\t",i);
            if (numero [i-1] == codice [i-1]) {
                printf ("%d",codice [i-1]);
            }
            else {
                scanf ("%d",&numero[i-1]);
                         
         if (numero[i-1] == codice[i-1]){
            int corretto = numero [i-1];
            posizione_numero_giusto (codice,numero,doppioni,controllo,corretto);
        }
         else {
          posizione_numero (codice,numero[i-1]);
         }
            }
        }
        tentativi = cod_corretto (codice,numero,tentativi);
        if (tentativi != 5){
            printf ("\nHai sbagliato nel tentativo numero %d\n",tentativi);
            printf ("Riprova\n");
        }
        
    }
    numeri_trovati (codice,numero);
    printf("\nil codice era: ");
    for (int i = 0; i<5;i++){
        printf ("%d",codice[i]);
    }
    return 0;
}
























