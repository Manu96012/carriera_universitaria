%{
/* Studente: Emanuele Filingeri		Matricola:0629173 */
#include<stdio.h>
#include<stdlib.h>	
#include<string.h>
#include<stdbool.h>
#include "symbol_table.h"

#define controlla_data(a, b) 	((a) == 99 && (b) == 0 || (b) == ((a)+1))
#define controlla_anno(a) 		((a)>=1 && (a)<=3)
#define controlla_crediti(a) 	((a) == 3 || (a) == 6 || (a) == 9 || (a) == 12 || (a) == 15)
#define controlla_voto(a)		((a) >= 18 && (a) <= 30)

void yyerror(char const*);
%}

%union{
	int intero;
	char* stringa;
	Lista_materie* esami;
}

%token ANNO_INT NOME_MAIUSCOLO NOME_MINUSCOLO 
%token <stringa> MATRICOLA CODICE_MATERIA
%token <intero> ANNO_CREDITI_VOTO
%token SEP1 SEP2 PAR_AP PAR_CH APICI FRECCIA TRATTINO VIRGOLA PUNTO_VIRGOLA
%type <esami> Lista_esami

%start Input
%error-verbose

%%

Input: Controllo_parte_1 SEP1 Controllo_parte_2 SEP2 Controllo_parte_3
	;


Controllo_parte_1:	ANNO_INT ANNO_CREDITI_VOTO '/' ANNO_CREDITI_VOTO {
						if(!controlla_data($2, $4)){
							yyerror("Data errata!");
							printf("Data errata!");
							exit(EXIT_FAILURE);
						}
					}
	;

Controllo_parte_2: 	Materia Controllo_parte_2
		
	| Materia
	;

Materia: PAR_AP Contenuto PAR_CH
	;

Contenuto: CODICE_MATERIA VIRGOLA Insegnamento VIRGOLA ANNO_CREDITI_VOTO VIRGOLA ANNO_CREDITI_VOTO {

		if(!controlla_anno($5)){
			yyerror("Anno di corso errato!");
			printf("Anno di corso errato!");
			exit(EXIT_FAILURE);
		}
		if(!controlla_crediti($7)){
			yyerror("Crediti errati!");
			printf("Crediti errati!");
			exit(EXIT_FAILURE);
		}

		Materia m = creaMateria($1, $5, $7, 0);
		aggiungiMateria(&materie, &m);
	}
	;


Insegnamento: APICI Nome_materia APICI
	;

Nome_materia: NOME_MAIUSCOLO Lista_materie_minuscolo
	|	NOME_MAIUSCOLO
	;

Lista_materie_minuscolo:	NOME_MINUSCOLO Lista_materie_minuscolo
	|	NOME_MINUSCOLO
	;

Controllo_parte_3: Alunno Controllo_parte_3
	| 	Alunno
	;

Alunno: MATRICOLA FRECCIA Nome_e_cognome PUNTO_VIRGOLA ANNO_CREDITI_VOTO PUNTO_VIRGOLA Lista_esami PUNTO_VIRGOLA {
			if(!controlla_anno($5)){
				yyerror("Anno di corso errato!");
				printf("Anno di corso errato!");
				exit(EXIT_FAILURE);
			}
			Lista_materie* lm = $7;
			Alunno a = creaAlunno($1, $5, lm);
			aggiungiAlunno(&alunni, &a);
	}
	;

Nome_e_cognome: NOME_MAIUSCOLO Nome_e_cognome
	|		NOME_MAIUSCOLO
	;


Lista_esami: 	CODICE_MATERIA VIRGOLA ANNO_CREDITI_VOTO TRATTINO {
						if(!controlla_voto($3)){
							yyerror("Voto errato.");
							printf("Voto errato.");
							exit(EXIT_FAILURE);
						}
						$$ = NULL;
						Materia m = prendiMateria(&materie, $1, $3);
						aggiungiMateria(&$$, &m);

				}	
		|		CODICE_MATERIA VIRGOLA ANNO_CREDITI_VOTO TRATTINO Lista_esami{
						if(!controlla_voto($3)){
							yyerror("Voto errato.");
							printf("Voto errato.");
							exit(EXIT_FAILURE);
						}
						$$ = NULL;
						Materia m = prendiMateria(&materie, $1, $3);
						$$ = concatena($$, $5);
						aggiungiMateria(&$$, &m);
						
				}
	;


%%

int main(void){


	materie = (Lista_materie*)malloc(sizeof(Lista_materie));
	alunni = (Lista_alunni*)malloc(sizeof(Lista_alunni));
	materie = NULL;
	alunni = NULL;

	yyparse();

	outputAlunni(alunni);
	
}

void yyerror(char const *s){
	fprintf(stderr, "%s\n", s);
}

