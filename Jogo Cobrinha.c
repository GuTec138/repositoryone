#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Inicializar(int tam, char Matriz[tam][tam], int quantidade, char objeto);
void Zerar(int tam, char Matriz[tam][tam]);
void Imprimir(int tam, char Matriz[tam][tam]);
void Barreiras(int tam, char Matriz[tam][tam]);

int main(){
	srand(time(NULL));
	
	int tam = 30;
	char Mapa[tam][tam];
	
	Zerar(tam,Mapa);
	Barreiras(tam, Mapa);
	Inicializar(tam, Mapa, 1, '*');
	Imprimir(tam, Mapa);
}




void Zerar(int tam, char Matriz[tam][tam]){
	for(int l = 0; l<tam; l++){
		for(int c =0; c<tam; c++){
			Matriz[l][c] = ' ';
		}
	}
}
void Barreiras(int tam, char Matriz[tam][tam]){
	for(int l = 0; l<tam; l++){
		for(int c = 0; c<tam; c++){
			if(l == 0){
				Matriz[l][c] = '-';
			}
			if(l+1 == tam){
				Matriz[l][c] = '-';
			}
			if(c == 0){
				Matriz[l][c] = '|';
			}
			if(c+1 == tam){
				Matriz[l][c] = '|';
			}
		}
	}
}
void Inicializar(int tam, char Matriz[tam][tam], int quantidade, char objeto){
	for(int i = 0; i < quantidade;){
	
	int l = rand()%tam;
	int c = rand()%tam;
	
	if(Matriz[l][c] == ' '){
		Matriz[l][c] = objeto;
		i++;
	}
    }
}
void Imprimir(int tam, char Matriz[tam][tam]){
	for(int l = 0; l<tam; l++){
		for(int c =0; c<tam; c++){
			printf("%c ", Matriz[l][c]);
		}
		printf("\n");
	}
}
