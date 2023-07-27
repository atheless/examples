struct node {
   tipo_inf inf;
   node* parent; //opzionale
	node* firstChild;
	node* nextSibling;
};

// node* tree -> struct node -> struct node 
// node* puntatore -> [inf][parent][firstChild][nextSubling]
typedef node* tree;

node* new_node(tipo_inf);
void insert_child(tree, tree);
void insert_sibling(node*, tree);
tipo_inf get_info(node*);
node* get_parent(node*);
node* get_firstChild(node*);
node* get_nextSibling(node*);






