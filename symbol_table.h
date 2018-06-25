/* Studente: Emanuele Filingeri		Matricola:0629173 */

/* Definizione delle strutture utilizzate */
struct Alunno{
	char* matricola;
	int anno_corso;
	struct Lista_materie *esami;
};

struct Lista_alunni{
	struct Alunno alunno;
	struct Lista_alunni *next;
};

struct Materia{
	char* codice;
	int anno_corso;
	int crediti;
	int voto;
};

struct Lista_materie{
	struct Materia materia;
	struct Lista_materie *next;
};
/******************************************/

/******** Typedefs delle varie strutture ********/
typedef struct Alunno Alunno;
typedef struct Lista_alunni Lista_alunni;
typedef struct Materia Materia;
typedef struct Lista_materie Lista_materie;
/************************************************/

/* Dichiarazione liste concatenate */
Lista_materie* materie;
Lista_alunni* alunni;
/***********************************/

/* Funzioni di creazioni delle variabili Alunno e Materia */
Alunno creaAlunno(char*, int, Lista_materie*);
Materia creaMateria(char*, int, int, int);
/**********************************************************/

/* Funzioni per l'inserimento in testa nelle varie liste */
void aggiungiAlunno(Lista_alunni **, Alunno*);
void aggiungiMateria(Lista_materie **, Materia*);
/*********************************************************
/* Funzioni di controllo e calcolo della media ponderata */
float mediaPonderata(Alunno*);
bool controllaAnno(const Alunno, const Materia);
/*********************************************************/

/* Funzioni di stampa di ogni singolo tipo di struttura */
void outputAlunno(Alunno*);
void outputMaterie(Lista_materie *);
void outputMateria(Materia*);

/* 	Quest'ultima funzione stampa il tutto nel formato:
 * 	Matricola > tot_esami > tot_crediti > media_ponderata
 */	

void outputAlunni(Lista_alunni *);
/********************************************************/

/* Funzione utilizzata per la concatenazione di due liste concatenate*/
Lista_materie* concatena(Lista_materie*, Lista_materie*);
/*********************************************************************/

/* Funzioni di supporto per la ricerca della materia desiderata nella LL materie */
Materia prendiMateria(Lista_materie**, char*, int);
Materia cercaMateria(Lista_materie**, char*);
/*********************************************************************************/