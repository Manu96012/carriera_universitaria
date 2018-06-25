/* Studente: Emanuele Filingeri		Matricola:0629173 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbol_table.h"


Alunno creaAlunno(char* matricola, int anno_corso, Lista_materie *esami){

	Alunno a;
	a.matricola = strdup(matricola);
	a.anno_corso = anno_corso;
	a.esami = (Lista_materie*)malloc(sizeof(Lista_materie));
	a.esami = esami;

	return a;
}

Materia creaMateria(char* codice, int anno_corso, int crediti, int voto){
	
	Materia m;
	m.codice = strdup(codice);
	m.anno_corso = anno_corso;
	m.crediti = crediti;
	m.voto = voto;

	return m;
}

void aggiungiAlunno(Lista_alunni **alunni, Alunno *alunno){
	
	Lista_alunni *la = (Lista_alunni*)malloc(sizeof(Lista_alunni));
		
	la->alunno.matricola = strdup(alunno->matricola);
		
	la->alunno.anno_corso = alunno->anno_corso;

	la->alunno.esami = alunno->esami;

	if(*alunni == NULL)
		la->next = NULL;
	else
		la->next = (*alunni);

	(*alunni) = la;
}

void aggiungiMateria(Lista_materie **materie, Materia *materia){
	
	Lista_materie *lm = (Lista_materie*)malloc(sizeof(Lista_materie));

	lm->materia.codice = strdup(materia->codice);
	
	lm->materia.anno_corso = materia->anno_corso;
	
	lm->materia.crediti = materia->crediti;
	
	lm->materia.voto = materia->voto;

	if(*materie == NULL)
		lm->next = NULL;
	else
		lm->next = (*materie);

	(*materie) = lm;
}

bool controllaAnno(const Alunno alunno, const Materia materia){
	if(alunno.anno_corso >= materia.anno_corso)
		return true;
	return false;
}

float mediaPonderata(Alunno* alunno){
	int tot_crediti = 0;
	int crediti_e_voti = 0;
	Lista_materie *lm = (Lista_materie*)malloc(sizeof(Lista_materie));
	lm = alunno->esami;

	while(lm != NULL){
		if(controllaAnno(*alunno, lm->materia)){
			tot_crediti += lm->materia.crediti;
			crediti_e_voti += (lm->materia.crediti*lm->materia.voto);
		}
		else
			printf("Anno di corso errato!\n");
		lm = lm->next;
	}

	return (float)((float)crediti_e_voti/(float)tot_crediti);
}


void outputMaterie(Lista_materie *materie){

	if(materie){
		outputMateria(&(materie->materia));
		outputMaterie(materie->next);
	}
}

void outputMateria(Materia *m){
	
	if(m){
		printf("%s\t%d\t%d\t%d\n", m->codice, m->anno_corso, m->crediti, m->voto);
	}
}

void outputAlunni(Lista_alunni *alunni){
	if(alunni){
		outputAlunno(&(alunni->alunno));
		printf("\n");
		outputAlunni(alunni->next);
	}
}

void outputAlunno(Alunno *alunno){

	int tot_crediti = 0;
	int tot_esami = 0;
	float media_ponderata = 0.0f;

	Lista_materie *e = (Lista_materie*)malloc(sizeof(Lista_materie));
	e = alunno->esami;

	while(e != NULL){
		if(alunno->anno_corso >= e->materia.anno_corso){
			++tot_esami;
			tot_crediti += e->materia.crediti;
		}
		e = e->next;
	}

	printf("%s > %d > %d > %.1f", alunno->matricola, tot_esami, tot_crediti, mediaPonderata(alunno));

}

Materia cercaMateria(Lista_materie **materie, char* codice){
	
	Lista_materie *lm = (Lista_materie*)malloc(sizeof(Lista_materie));
	lm = *materie;

	while(lm != NULL)
		if(strcmp(lm->materia.codice, codice) == 0){
			return creaMateria(codice, lm->materia.anno_corso, lm->materia.crediti, 0);
		} 
		else
			lm = lm->next;

	exit(EXIT_FAILURE);
}


Materia prendiMateria(Lista_materie **materie, char* codice, int voto){

	Materia m;
	m = cercaMateria(materie, codice);
	m.voto = voto;

	return m;
}

Lista_materie* concatena(Lista_materie *a, Lista_materie *b)
{
	Lista_materie **tmp = (Lista_materie**)malloc(sizeof(Lista_materie*));
	*tmp = a;

	while(a != NULL){
		aggiungiMateria(tmp, &(a->materia));
		a = a->next;
	}
	while(b != NULL){
		aggiungiMateria(tmp, &(b->materia));
		b = b->next;
	}
	
	return *tmp;
}
