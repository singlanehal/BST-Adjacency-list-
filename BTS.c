# BST-Adjacency-list-
#include<stdio.h>
#include<stdlib.h>
#define SIZE 40
struct Queue
{
	int items[SIZE];
	int front;
	int rear;
};
struct Queue *createQueue();
void enqueue(struct Queue *q,int n);
void dequeue(struct Queue *q);
void Display(struct Queue *q);
void isEmpty(struct Queue *q);
void printQueue(struct Queue *q);
struct Node
{
	int vertex;
	struct node *next;
};
struct Node *createnode(int);
struct Graph
{
	int numVertices;
	struct node **adjLists;
	int *visted;
};
void bfs(struct Graph* graph,int startVertex)
{
	struct queue *q=createQueue();
	
	graph->visted[startVertex]=1;
	enqueue(q,startVertex);
	while(!isEmpty(q))
	{
		printQueue(q);
		int currentvertex=dequeue(q);
		printf("Visited %d\n",currentvertex);
		
		struct Node *temp=graph->adjLists[currentvertex];
		while(temp)
		{
			int adjVertex=temp->vertex;
			if(graph->visted[adjVertex]==0)
			{
				graph->visted[adjVertex]=1;
				enqueue(q,adjVertex);
			}
			temp=temp->next;
		}
	}
	
}
struct Node *createnode(int v)
{
	struct Node *newnode=malloc(sizeof(struct Node));
	newnode->vertex=v;
	newnode->next=NULL;
	return newnode;
}

struct Graph *creategraph(int vertices)
{
	struct Graph *graph=malloc(sizeof(struct Graph));
	graph->numVertices=vertices;
	
	graph->adjLists=malloc(sizeof(struct Node*));
	graph->visted=malloc(sizeof(int));
	
	int i;
	for(i=0;i<vertices;i++)
	{
		graph->adjLists[i]=NULL;
		graph->visted[i]=0;
	}
	return graph;
}
void addedge(struct Graph* graph,int src,int dest)
{
	struct node *newnode=createnode(dest);
	newnode->next=graph->adjLists[src];
	graph->adjLists[src]=newnode;
	
	newnode=createnode(src);
	newnode->next=graph->adjLists[dest];
	graph->adjLists[dest]=newnode;
}
struct Queue *createQueue()
{
	struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
};
// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
  }
}

int main() {
  struct Graph* graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  bfs(graph, 0);

  return 0;
}
