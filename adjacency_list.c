#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node *next;
};

struct graph{
    int numVertices;
    struct node **adjLists;
};

struct node *createNode(int v){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

struct graph* createAGraph(int vertices){
    struct graph* g = (struct graph *)malloc(sizeof(struct graph));
    g->numVertices = vertices;
    g->adjLists = malloc(vertices * sizeof(struct node *));
    for (int i = 0; i < vertices; i++)
    {
        g->adjLists[i] = NULL;
    }
    return g;    
}

void addEdge(struct graph* g, int s, int d){
    struct node *newnode = createNode(d);
    newnode->next = g->adjLists[s];
    g->adjLists[s] = newnode;

    newnode = createNode(s);
    newnode->next = g->adjLists[d];
    g->adjLists[d] = newnode;
}

void printGraph(struct graph* g){
    for (int v = 0; v < g->numVertices; v++)
    {
        struct node* temp = g->adjLists[v];
        printf("\nVertex %d: ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");       
    }
}

int main(){
    struct graph *g = createAGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 0, 3);
    addEdge(g, 1, 2);

    printGraph(g);
    return 0;
}