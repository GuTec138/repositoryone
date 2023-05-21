//LIBS..........................................
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
//______________________________________________

//ESTRUTURA.....................................
typedef struct{
   int vida;
   int taxa_raiva;
   char simbolo;
   int posicaol, posicaoc;
}Personagem;
//______________________________________________

//PROTÓTIPO FUNÇÕES.............................
void zerar(int tam, char Mapa[tam][tam]);
void InicializarMapa(int tam, char Mapa[tam][tam], char objetos, int quantidade, Personagem *Eleven, Personagem *Will);
void Imprimir(int tam, char Mapa[tam][tam]);
bool abrirPortal(Personagem *Eleven);
void MovimentacaoEleven(Personagem *Eleven, int tam, char Mapa[tam][tam], char *movimentar);
//______________________________________________

//JOGO..........................................
int main(void) {
  
//Declaração de Variáveis.........................
srand(time(NULL));
Personagem Eleven, Will;
int tam = 3, tam2 = 10;
Eleven.simbolo = 'E';
Will.simbolo = 'W';
char Mapa[tam][tam], MundoInvertido[tam2][tam2];
Eleven.vida = 100;
bool abrir;
char movimentar;
//___________________________________________________

//Estrutura do Jogo...............................  
  zerar(tam,Mapa);
  InicializarMapa(tam,Mapa,Eleven.simbolo, 1, &Eleven, &Will);
  Imprimir(tam,Mapa);
  do{
    abrir = abrirPortal(&Eleven);
  }while(abrir == false);
  system("clear");
  InicializarMapa(tam,Mapa,'O', 1, &Eleven, &Will);
  Imprimir(tam,Mapa);
  printf("\n\nDigite (w/a/s/d) para se movimentar:\n");
  while(Mapa[Eleven.posicaol][Eleven.posicaoc] != 'O'){
   scanf("%c", &movimentar);
   MovimentacaoEleven(&Eleven, tam, Mapa,&movimentar);
   system("clear");
   if(Mapa[Eleven.posicaol][Eleven.posicaoc] != 'O'){
     Imprimir(tam,Mapa);
   } 
  }

  zerar(tam2,MundoInvertido);
  InicializarMapa(tam2,MundoInvertido,Eleven.simbolo, 1, &Eleven, &Will);
  InicializarMapa(tam2,MundoInvertido,'a', 10, &Eleven, &Will);
  InicializarMapa(tam2,MundoInvertido,'^', 5, &Eleven, &Will);
  InicializarMapa(tam2,MundoInvertido,'D', 4, &Eleven, &Will);
  InicializarMapa(tam2,MundoInvertido,'+', 10, &Eleven, &Will);
  InicializarMapa(tam2,MundoInvertido,Will.simbolo, 1, &Eleven, &Will);
  InicializarMapa(tam2,MundoInvertido,'*', 1, &Eleven, &Will);
  Imprimir(tam2,MundoInvertido);
  while(MundoInvertido[Eleven.posicaol][Eleven.posicaoc] != '*'){
   scanf("%c", &movimentar);
   MovimentacaoEleven(&Eleven, tam2, MundoInvertido, &movimentar);
   system("clear");
   if(Mapa[Eleven.posicaol][Eleven.posicaoc] != '*'){
     Imprimir(tam2,MundoInvertido);
   } 
  }

  return 0;
}
//________________________________________________________

//FUNÇÕES.......................................
void zerar(int tam, char Mapa[tam][tam]){
  for(int l =0; l<tam; l++){
    for(int c=0; c<tam; c++){
      Mapa[l][c] = '_';
    }
  }
}
void InicializarMapa(int tam, char Mapa[tam][tam], char objetos, int quantidade, Personagem *Eleven, Personagem *Will){
  for(int i =0; i<quantidade;){
  
      int l = rand()%tam;
      int c = rand()%tam;
      
      if(Mapa[l][c] == '_'){
        Mapa[l][c] = objetos;
      if(objetos == 'E'){
        Eleven->posicaol = l;
        Eleven->posicaoc = c;
      }
      if(objetos == 'W'){
        Will->posicaol = l;
        Will->posicaoc = c;
      }
        i++;
      }
}
}
void MovimentacaoEleven(Personagem *Eleven, int tam, char Mapa[tam][tam], char *movimentar){
       switch(*movimentar){
         case 'w':if(Eleven->posicaol - 1 >= 0){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != 'O'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != 'a'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != 'c'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != '^'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != '*'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != 'W'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] == '+'){
                      Eleven->vida+=5;
                      if(Eleven->vida >= 100){
                        Eleven->vida = 100;
                      }
                      }
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] == 'D'){
                      Eleven->vida -= 10;
                      if(Eleven->vida <= 0){
                         printf("Eleven morreu!");
                         exit(0);
                      }
                      }
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] == '*'){
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = '_';
                      Eleven->posicaol--;
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = 'E';
                    }
                    }
                      else{
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                    }
                    }
                    }
                    }
                    else{
                        Mapa[Eleven->posicaol][Eleven->posicaoc] = 'O';
                        break;
                      }
                   }
                  break;
         case 'W':if(Eleven->posicaol - 1 >= 0){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != 'O'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != 'a'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != 'c'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != '^'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != '*'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] != 'W'){
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] == '+'){
                      Eleven->vida+=5;
                      if(Eleven->vida >= 100){
                        Eleven->vida = 100;
                      }
                      }
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] == 'D'){
                      Eleven->vida -= 10;
                      if(Eleven->vida <= 0){
                         printf("Eleven morreu!");
                         exit(0);
                      }
                      }
                      if(Mapa[Eleven->posicaol-1][Eleven->posicaoc] == '*'){
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = '_';
                      Eleven->posicaol--;
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = 'E';
                    }
                    }
                      else{
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                    }
                    }
                    }
                    }
                    else{
                        Mapa[Eleven->posicaol][Eleven->posicaoc] = 'O';
                        break;
                      }
                   }
                  break;
         case 's':if(Eleven->posicaol + 1 <tam){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != 'O'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != 'a'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != 'c'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != '^'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != '*'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != 'W'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] == '+'){
                      Eleven->vida+=5;
                      if(Eleven->vida >= 100){
                        Eleven->vida = 100;
                      }
                      }
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] == 'D'){
                      Eleven->vida -= 10;
                      if(Eleven->vida <= 0){
                         printf("Eleven morreu!");
                         exit(0);
                      }
                      }
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] == '*'){
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = '_';
                      Eleven->posicaol++;
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = 'E';
                    }
                    }
                      else{
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                    }
                    }
                    }
                    }
                    else{
                        Mapa[Eleven->posicaol][Eleven->posicaoc] = 'O';
                        break;
                      }
                   }
                  break;
         case 'S':if(Eleven->posicaol + 1 <tam){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != 'O'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != 'a'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != 'c'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != '^'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != '*'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] != 'W'){
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] == '+'){
                      Eleven->vida+=5;
                      if(Eleven->vida >= 100){
                        Eleven->vida = 100;
                      }
                      }
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] == 'D'){
                      Eleven->vida -= 10;
                      if(Eleven->vida <= 0){
                         printf("Eleven morreu!");
                         exit(0);
                      }
                      }
                      if(Mapa[Eleven->posicaol+1][Eleven->posicaoc] == '*'){
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = '_';
                      Eleven->posicaol++;
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = 'E';
                    }
                    }
                      else{
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                    }
                    }
                    }
                    }
                    else{
                        Mapa[Eleven->posicaol][Eleven->posicaoc] = 'O';
                        break;
                      }
                   }
                  break;
         case 'd':if(Eleven->posicaoc + 1 <tam){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != 'O'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != 'a'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != 'c'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != '^'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != '*'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != 'W'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] == '+'){
                      Eleven->vida+=5;
                      if(Eleven->vida >= 100){
                        Eleven->vida = 100;
                      }
                      }
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] == 'D'){
                      Eleven->vida -= 10;
                      if(Eleven->vida <= 0){
                         printf("Eleven morreu!");
                         exit(0);
                      }
                      }
                        if(Mapa[Eleven->posicaol][Eleven->posicaoc+1] == '*'){
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = '_';
                      Eleven->posicaoc++;
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = 'E';
                    }
                    }
                        else{
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                    }
                    }
                    }
                    }
                      else{
                        Mapa[Eleven->posicaol][Eleven->posicaoc] = 'O';
                        break;
                      }
                   }
                  break;
         case 'D':if(Eleven->posicaoc + 1 <tam){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != 'O'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != 'a'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != 'c'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != '^'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != '*'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] != 'W'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] == '+'){
                      Eleven->vida+=5;
                      if(Eleven->vida >= 100){
                        Eleven->vida = 100;
                      }
                      }
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc + 1] == 'D'){
                      Eleven->vida -= 10;
                      if(Eleven->vida <= 0){
                         printf("Eleven morreu!");
                         exit(0);
                      }
                      }
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc+1] == '*'){
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = '_';
                      Eleven->posicaoc++;
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = 'E';
                    }
                    }
                        else{
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                    }
                    }
                    }
                    }
                      else{
                        Mapa[Eleven->posicaol][Eleven->posicaoc] = 'O';
                        break;
                      }
                   }
                  break;
         case 'a':if(Eleven->posicaoc - 1 >= 0){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != 'O'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != 'a'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != 'c'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != '^'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != '*'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != 'W'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] == '+'){
                      Eleven->vida+=5;
                      if(Eleven->vida >= 100){
                        Eleven->vida = 100;
                      }
                      }
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] == 'D'){
                      Eleven->vida -= 10;
                      if(Eleven->vida <= 0){
                         printf("Eleven morreu!");
                         exit(0);
                      }
                      }
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = '_';
                      Eleven->posicaoc--;
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = 'E';
                    }
                    }
                      else{
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }  
                      }
                    }  
                    }
                    }
                      else{
                        Mapa[Eleven->posicaol][Eleven->posicaoc] = 'O';
                        break;
                      }
                   }
                  break;
         case 'A':if(Eleven->posicaoc - 1 >= 0){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != 'O'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != 'a'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != 'c'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != '^'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != '*'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] != 'W'){
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] == '+'){
                      Eleven->vida+=5;
                      if(Eleven->vida >= 100){
                        Eleven->vida = 100;
                      }
                      }
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc - 1] == 'D'){
                      Eleven->vida -= 10;
                      if(Eleven->vida <= 0){
                         printf("Eleven morreu!");
                         exit(0);
                      }
                      }
                      if(Mapa[Eleven->posicaol][Eleven->posicaoc-1] == '*'){
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = '_';
                      Eleven->posicaoc--;
                      Mapa[Eleven->posicaol][Eleven->posicaoc] = 'E';
                    }
                    }
                      else{
                        system("clear");
              printf("*********************************\n");
                        printf("**********Final de Jogo**********\n");
                      printf("*********************************\n\n");
                        printf("Eleven e Will Voltaram vivos!\n");
                        printf("Vida restante de Eleven: %i", Eleven->vida);
                        exit(0);
                      }
                    }  
                    }
                    }
                    }
                      else{
                        Mapa[Eleven->posicaol][Eleven->posicaoc] = 'O';
                        break;
                      }
                   }
                  break;
         default: break;
  }
}
bool abrirPortal(Personagem *Eleven){
  char portal;
    printf("\nDigite p para tentar abrir portal: ");
    scanf("%c", &portal);
    getchar();
      if(portal == 'p' || portal == 'P'){
          Eleven->taxa_raiva = rand()%101;
            if(Eleven->taxa_raiva >= 60){
                return true;
            }
            else{
                 Eleven->vida-=20;
                 if(Eleven->vida<=0){
                    printf("Eleven morreu\nGame Over!");
                    exit(0);
                 }
                 else{
                      printf("\n\nTentativa fracassada\nVida Atual: %i", Eleven->vida);
                   return false;
                 }
            }
      }
  else{
    return NULL;
  }
}
void Imprimir(int tam, char Mapa[tam][tam]){
  for(int l=0; l<tam; l++){
    for(int c = 0; c<tam; c++){
      printf("%c\t", Mapa[l][c]);
    }
    printf("\n");
  }
}
//_______________________________________________