/*******************************/
/* HEADER MODULO "coda" */
/*******************************/
struct elem
{
       tipo_inf inf;
       int w;
       elem* pun ;
};

typedef elem* codap;



codap enqueue(codap, tipo_inf,int);
tipo_inf dequeue(codap&);
tipo_inf minQueue(codap);
codap decreaseKey(codap, tipo_inf,int);
bool isEmpty(codap);


