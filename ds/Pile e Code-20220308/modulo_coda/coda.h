/*******************************/
/* HEADER MODULO "coda" */
/*******************************/
struct elem{
  tipo_inf inf;
  elem* pun;
};

typedef elem* lista;

typedef struct{
  elem* head;
  elem* tail;
} coda;

coda enqueue(coda, tipo_inf);
tipo_inf dequeue(coda&);
tipo_inf first(coda);
bool isEmpty(coda);
coda newQueue();

