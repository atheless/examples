/*******************************/
/* HEADER MODULO "carta" 	   */
/*******************************/


typedef struct{
	char nc[50];
	int totalep;
} tipo_inf;


int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
