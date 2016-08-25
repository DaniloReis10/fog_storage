#ifndef __NODE__

#define __NODE__

#include "lib/list.h"
#include "contiki.h"
 
// structure of fog node
typedef struct tagNode {
  uint16_t               id;// Node's identify
  float                 x,y;// Node position
  list_t             oneHop;// List of node Id neighbors with weight  
  uint16_t  numberNeighbors;// number of neighbors 
} Node;

// Structure of edge 
typedef struct tagNode_Edge{
  struct Node_Edge *next;// Requirement for contiki list 
  uint16_t        baseId;// Base Id Node
  uint16_t    neighborId;// Neighbor Id Node 
  float           weight;// weight: distance
} Node_Edge;

void Node_Edge_init(Node_Edge *edge,Node *base,Node *neighbor);

// instances node structure with no parameters
void                         Node_init(Node *this);

// instances node structure with broadcast message
uint16_t   Node_fromString(Node *this,char *string);

// Decode Node info to string
char                     *Node_toString(Node *this);

// Lenght of list of neighbors
uint16_t           Node_neighborLength(Node *this);

// Go to first element of neighbors list
void                 Node_neighborHead(Node *this);

// Add a new Neighbor
void   Node_addNeighbor(Node *this,Node *neighbor);

// Find edge by node Id
Node_Edge          *Node_findEdgeById(uint16_t id);

// Remove Edge by Id node
uint16_t      Node_removeEdgeByIdNode(uint16_t id);

// Get next neighbors
Node_Edge           *Node_neighborNext(Node *this);

// Destroy node structure
void                        Node_close(Node *this);

#endif
