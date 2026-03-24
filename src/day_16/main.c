#include <stdio.h>
#include <stdlib.h>

/*
    Nodes em C
    A List aponta para o primeiro elemento
    da corrente, ->next dentro do Node é
    o pointer para o elemento de baixo:

    | List      
          v
    | Next Node 
          v
    | Next Node 
          v
    | Next Node 
          v
    | NULL   
    
    Ao chegar em um Node com ->next =
    NULL, é o fim da List
*/

typedef struct Node{
    int value;
    // Pointing to the next
    // Node of the 'chain'
    struct Node *next;
} Node;

Node *node_create(int value){

    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;

    return n;
}

Node *node_pfront(Node *list, int value){

    Node *node = node_create(value);
    node->next = list;
    return node;
}

Node *node_pback(Node *list, int value){

    Node *node = node_create(value);
    Node *node_pointer = list;

    while(node_pointer->next != NULL){
        node_pointer = node_pointer->next;
    }

    // Node pointer is the last item
    node_pointer->next = node;

    return list;
}

void node_list(Node *list){

    Node *node_pointer = list;

    while(node_pointer!= NULL){
        printf("%d\n", node_pointer->value);
        node_pointer = node_pointer->next;
    }
}

int node_free(Node *list){

    Node *node_pointer = list;
    Node *temp_node;
    while(node_pointer!= NULL){
        temp_node = node_pointer->next;
        free(node_pointer);
        node_pointer = temp_node;
    }

    return 1;
}

int main(void)
{
    Node *list = node_create(9);

    list = node_pfront(list, 23);
    list = node_pfront(list, 2);

    list = node_pback(list, 777);

    node_list(list);

    if(node_free(list)){
        printf("List removed");
    }
}

