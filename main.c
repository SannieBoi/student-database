#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

typedef struct{
    char ime[15];
    char prezime[15];
    int razred;
    int odeljenje;
    int ocene[10];
    char kraj;
}ucenik;

void menu(){
    printf("\t\t\t\t\t\n");
    printf("\t\t\t\t\t\n");
    printf("\t\t\t\t\t/----------------------\\\n");
    printf("\t\t\t\t\t|     BAZA UCENIKA     |\n");
    printf("\t\t\t\t\t\\----------------------/\n");
    printf("\t\t\t\t\t\n");
    Sleep(40);
    printf("\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t   Pritisni taster za zeljenu komandu\n");
    printf("\t\t\t\t----------------------------------------\n");
    Sleep(40);
    printf("\n");
    printf("\t\t\t\t\t(1) Prikazi sve ucenike\n");
    Sleep(40);
    printf("\t\t\t\t\t(2) Unesi novog ucenika\n");
    Sleep(40);
    printf("\t\t\t\t\t(3) Sortiraj ucenike\n");
    Sleep(40);
    printf("\t\t\t\t\t(4) Pretraga ucenika\n");
    Sleep(40);
    printf("\t\t\t\t\t(5) Prikazi vukovce\n");
    Sleep(40);
    printf("\n");
    printf("\t\t\t\t----------------------------------------\n");
    printf("\n");
    Sleep(40);
    printf("\t\t\t\t\t(0) Prekinuti program\n");
    Sleep(40);
    printf("\n");
    printf("\t\t\t\t----------------------------------------\n");
    Sleep(40);
    printf("\t\t\t\t\t\tUNOS: ");
}

void menu2(){
    printf("\t\t\t\t\t \n");
    printf("\t\t\t\t\t \n");
    printf("\t\t\t\t\t \n");
    printf("\t\t\t\t\t      SORTIRAJ PO:     \n");
    printf("\t\t\t\t\t \n");
    printf("\t\t\t\t\t \n");
    Sleep(40);
    printf("\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t   Pritisni taster za zeljenu komandu\n");
    printf("\t\t\t\t----------------------------------------\n");
    Sleep(40);
    printf("\n");
    printf("\t\t\t\t\t(1) Imenu\n");
    Sleep(40);
    printf("\t\t\t\t\t(2) Prezimenu\n");
    Sleep(40);
    printf("\t\t\t\t\t(3) Razredu\n");
    Sleep(40);
    printf("\t\t\t\t\t(4) Proseku\n");
    Sleep(40);
    printf("\n");
    printf("\t\t\t\t----------------------------------------\n");
    printf("\n");
    Sleep(40);
    printf("\t\t\t\t\t(0) Vrati se u meni\n");
    Sleep(40);
    printf("\n");
    printf("\t\t\t\t----------------------------------------\n");
    Sleep(40);
    printf("\t\t\t\t\t\tUNOS: ");
}

void dodela(char F[15], ucenik u[]){
    FILE *f=NULL;
    char c;
    int br=0;
    f=fopen(F, "a+");
    if(f==NULL){
        printf("Nemoguc pristup.");
        return;
    }
    fseek(f, 0, SEEK_SET);
    while((c=fgetc(f))!=EOF){
        if(c!='.')
            br=br;
        else
            br++;
    }
    fseek(f, 0, SEEK_SET);
    for(int i=0; i<br; i++){
        fflush(f);
        fscanf(f, "%s", u[i].ime);
        fseek(f, 1, SEEK_CUR);

        fflush(f);
        fscanf(f, "%s", u[i].prezime);
        fseek(f, 1, SEEK_CUR);

        fflush(f);
        fscanf(f, "%d", &u[i].razred);
        fseek(f, 1, SEEK_CUR);

        fflush(f);
        fscanf(f, "%d", &u[i].odeljenje);
        fseek(f, 1, SEEK_CUR);

        fflush(f);
        for(int j=0; j<10; j++){
            fscanf(f, "%d", &u[i].ocene[j]);
            fseek(f, 1, SEEK_CUR);
        }

        fflush(f);
        fscanf(f, "%c", &u[i].kraj);
        fseek(f, 2, SEEK_CUR);
    }
}

void tabela(ucenik u[], int n){
    float s=0, p;
    printf("   |IME            |PREZIME        |RAZRED     |ODELJENJE  |OCENE\n");
    Sleep(40);
    printf("   |               |               |           |           |     \n");
    Sleep(40);
    for(int i=0; i<n; i++){
        printf("%02d.|%-15s|%-15s|%d          |%d          |",i+1, u[i].ime, u[i].prezime, u[i].razred, u[i].odeljenje);
        for(int j=0; j<10; j++){
            printf("%d ", u[i].ocene[j]);
            s=s + u[i].ocene[j] + 0.0;
        }
        p=(s+0.0)/10;
        printf("(%.2f)", p);
        s=0;
        p=0;
        Sleep(40);
        printf("\n");
    }
}

void unesi(ucenik v[]){
    int x;

    printf("Unosite novog ucenika.");
    Sleep(3000);

    for(int i=0; i<1; i++){
    system("cls");
    printf("Ime ucenika:\n");
    printf("Prezime ucenika:\n");
    printf("Razred ucenika:\n");
    printf("Odeljenje ucenika:\n");
    printf("Ocene ucenika:\n");
    printf("\n\n");
    printf("Ime ucenika: \n");
    fflush(stdin);
    gets(v[i].ime);

    system("cls");
    printf("Ime ucenika: ");
    puts(v[i].ime);
    printf("Prezime ucenika:\n");
    printf("Razred ucenika:\n");
    printf("Odeljenje ucenika:\n");
    printf("Ocene ucenika:\n");
    printf("\n\n");
    printf("Prezime ucenika:\n");
    fflush(stdin);
    gets(v[i].prezime);

    system("cls");
    printf("Ime ucenika: ");
    puts(v[i].ime);
    printf("Prezime ucenika: ");
    puts(v[i].prezime);
    printf("Razred ucenika:\n");
    printf("Odeljenje ucenika:\n");
    printf("Ocene ucenika:\n");
    printf("\n\n");
    printf("Razred ucenika:\n");
    fflush(stdin);
    scanf("%d", &x);
    v[i].razred=x;

    system("cls");
    printf("Ime ucenika: ");
    puts(v[i].ime);
    printf("Prezime ucenika: ");
    puts(v[i].prezime);
    printf("Razred ucenika: ");
    printf("%d\n", v[i].razred);
    printf("Odeljenje ucenika:\n");
    printf("Ocene ucenika:\n");
    printf("\n\n");
    printf("Odeljenje ucenika:\n");
    fflush(stdin);
    scanf("%d", &x);
    v[i].odeljenje=x;

    system("cls");
    printf("Ime ucenika: ");
    puts(v[i].ime);
    printf("Prezime ucenika: ");
    puts(v[i].prezime);
    printf("Razred ucenika: ");
    printf("%d\n", v[i].razred);
    printf("Odeljenje ucenika: ");
    printf("%d\n", v[i].odeljenje);
    printf("Ocene ucenika:\n");
    printf("\n\n");
    printf("10 Ocena ucenika:\n");
    for(int j=0; j<10; j++){
        scanf("%d", &x);
        v[i].ocene[j]=x;
    }
    system("cls");
    printf("Ime ucenika: ");
    puts(v[i].ime);
    printf("Prezime ucenika: ");
    puts(v[i].prezime);
    printf("Razred ucenika: ");
    printf("%d\n", v[i].razred);
    printf("Odeljenje ucenika: ");
    printf("%d\n", v[i].odeljenje);
    printf("Ocene ucenika: ");
    for(int j=0; j<10; j++)
        printf("%d ", v[i].ocene[j]);
    printf("\n\n");

    v[i].kraj='.';
    }
}

int potvrda(){
    int x=0, n=0, y=1, z=1;
    while(1){
        switch(x){
            case 0:
                y=1;
                while(y){
                    printf("Da li ste ispravno uneli podatke?     1-DA / 0-NE\n");
                    scanf("%d", &n);
                    if(n==1 || n==0)
                        y=0;
                    else
                        printf("Niste ispravno uneli odgovor!\n");
                }
                if(n)
                    return 1;
                x=1;
                break;

            case 1:
                z=1;
                while(z){
                    printf("Da li zelite da odustanete?     1-DA / 0-NE\n");
                    scanf("%d", &n);
                    if(n==1 || n==0)
                        z=0;
                    else
                        printf("Niste ispravno uneli odgovor!\n");
                }
                if(z)
                    return 0;
                return -1;
                break;
        }
    }
}

void unos(char F[15], ucenik v[]){
    FILE *f=NULL;
    f=fopen(F, "a+");
    fprintf(f, "\n\n");

    fputs(v[0].ime, f);
    fprintf(f, " ");

    fputs(v[0].prezime, f);
    fprintf(f, " ");

    fprintf(f, "%d ", v[0].razred);
    fprintf(f, "%d\n", v[0].odeljenje);

    for(int i=0; i<10; i++){
        fprintf(f,"%d ", v[0].ocene[i]);
    }

    fputc(v[0].kraj, f);
}

void vukovci(ucenik u[], int n){
    float s=0, p;
    printf("   |IME            |PREZIME        |RAZRED     |ODELJENJE  |OCENE\n");
    Sleep(40);
    printf("   |               |               |           |           |     \n");
    Sleep(40);
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            s=s+u[i].ocene[j];
        }
        p=(s+0.0)/10;
        if(p==5.0){
            printf("%2d.|%-15s|%-15s|%d          |%d          |",i+1, u[i].ime, u[i].prezime, u[i].razred, u[i].odeljenje);
            for(int j=0; j<10; j++){
                printf("%d ", u[i].ocene[j]);
                s=s + u[i].ocene[j] + 0.0;
            }
            Sleep(40);
            printf("\n");
        }
        s=0;
    }
}

void pretraga(ucenik u[], int n){
    int br=0;
    int t=0;
    int ind=0;
    char s[15];
    char prekid[15]="0";
    while(1){
        printf("Unesite pocetnih nekoliko slova po kojim trazite ime ucenika. Unesite 0 da prekinete.");
        printf("\n\t\t\tUNOS:  ");
        fflush(stdin);
        gets(s);
        if(strcmp(s,prekid)==0)
            return;

        int m=strlen(s);
        for(int i=0; i<n; i++){
            for(int j=0; j<m && ind==0; j++){
                if((toupper(s[j])==u[i].ime[j])||(tolower(s[j])==u[i].ime[j]))
                    br++;
                else
                    ind=1;
            }
            ind=0;
            if(br==m)
                t++;
            br=0;
        }
        if(t==0)
            printf("Nema ucenika koji se uklapaju sa vasom pretragom!");
        else{
            printf("\nPronadjeno je %d rezultata.\n\n", t);
            printf("   |IME            |PREZIME        |RAZRED     |ODELJENJE  |OCENE\n");
            Sleep(40);

            for(int i=0; i<n; i++){
                for(int j=0; j<m && ind==0; j++){
                    if((toupper(s[j])==u[i].ime[j])||(tolower(s[j])==u[i].ime[j]))
                        br++;
                    else
                        ind=1;
                }
                ind=0;
                if(br==m){
                    printf("%2d.|%-15s|%-15s|%d          |%d          |",i+1, u[i].ime, u[i].prezime, u[i].razred, u[i].odeljenje);
                    for(int j=0; j<10; j++){
                        printf("%d ", u[i].ocene[j]);
                    }
                    Sleep(40);
                    printf("\n");
                }
                br=0;
            }
        }
        t=0;

        printf("\n\nPritisni bilo koj taster da ponovite pretragu  ");
        getch();
        system("cls");
    }
}

void sortiranje(ucenik u[], int n, int tip){
    ucenik pom, v[n];
    float s=0, pp, p[n];
    for(int i=0; i<n; i++)
        v[i]=u[i];
    switch(tip){
        case 1:
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(strcmp(v[i].ime, v[j].ime)>0){
                        pom=v[i];
                        v[i]=v[j];
                        v[j]=pom;
                    }
                }
            }
            tabela(v, n);
            break;
        case 2:
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(strcmp(v[i].prezime, v[j].prezime)>0){
                        pom=v[i];
                        v[i]=v[j];
                        v[j]=pom;
                    }
                }
            }
            tabela(v, n);
            break;
        case 3:
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(v[i].razred>v[j].razred){
                        pom=v[i];
                        v[i]=v[j];
                        v[j]=pom;
                    }
                }
            }
            tabela(v, n);
            break;
        case 4:
            for(int i=0; i<n; i++){
                for(int j=0; j<10; j++){
                    s=s+v[i].ocene[j]+0.0;
                }
                p[i]=(s+0.0)/10;
                s=0;
            }
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(p[i]<p[j]){
                        pom=v[i];
                        v[i]=v[j];
                        v[j]=pom;
                        pp=p[i];
                        p[i]=p[j];
                        p[j]=pp;
                    }
                }
            }
            tabela(v, n);
            break;
    }
}

int main(){

    printf("Otvaranje falja...");
    FILE *f=NULL;
    ucenik v[1];
    int n=1, x=0, y=0, br=0, z=1, k=0;
    char F[15]="C:\\ucenici.txt"; //podesite lokaciju fajla ovde.
    char c;
    f=fopen(F, "a+");
    if(f==NULL){
        printf("Nemoguc pristup.");
        return 0;
    }

    system("cls");
    printf("Dodela ucenika...");
    fseek(f, 0, SEEK_SET);
    while((c=fgetc(f))!=EOF){
        if(c!='.')
            br=br;
        else
            br++;
    }
    fseek(f, 0, SEEK_SET);
    ucenik u[br];
    dodela(F, u);

    system("cls");
    menu();

    while(1){
        scanf("%d", &x);
        system("cls");
        switch(x){
            case 1:
                tabela(u, br);
                break;
            case 2:
                z=1;
                unesi(v);
                while(z){
                    k=potvrda();
                    if(k>0){
                        if(k){
                            unos(F, v);
                            printf("Ucenik uspesno unet. Ponovo pokrenite program da bi ste videli promene.\n");
                        }
                        else{
                            printf("Otkazano unosenje ucenika.\n");
                        }
                        z=0;
                    }
                    else{
                        system("cls");
                        unesi(v);
                    }
                }
                break;
            case 3:
                menu2();
                n=1;
                while(n){
                    scanf("%d", &y);
                    system("cls");
                    switch(y){
                        case 1:
                            sortiranje(u, br, y);
                            break;
                        case 2:
                            sortiranje(u, br, y);
                            break;
                        case 3:
                            sortiranje(u, br, y);
                            break;
                        case 4:
                            sortiranje(u, br, y);
                            break;
                        case 0:
                            n=0;
                            system("cls");
                            break;
                        default:
                            printf("Proverite unos!");
                            break;
                    }
                    if(y){
                        printf("\n\nPritisni bilo koj taster za povratak u meni  ");
                        getch();
                        system("cls");
                        menu2();
                    }
                    else
                        system("cls");
                }
                break;
            case 4:
                pretraga(u, br);
                break;
            case 5:
                vukovci(u,br);
                break;
            case 9:
                fprintf(f, "\b");
                break;
            case 0:
                fclose(f);
                return 0;
                break;
            default:
                printf("Proverite unos!");
                break;
        }
        if(x!=3){
            printf("\n\nPritisni bilo koj taster za povratak u meni  ");
            getch();
        }
        system("cls");
        menu();
    }
}
