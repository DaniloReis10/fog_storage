#include "node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void Node_edge_init(Node_Edge *edge,Node *base,Node *neighbor)
{
   edge->baseId     = base->id;
   edge->neighborId = neighbor->id;
   edge->weight     = sqrt( pow((base->x - neighbor->x),2) + 
                            pow((base->y - neighbor->y),2)); 
}

// instances node structure with no parameters
void Node_init(Node *this)
{
    this -> id              = 0;
    this -> numberNeighbors = 0;  
    list_init(this->oneHop);
}
void Node_withId(Node *this,uint16_t id)
{   
   Node_init(this);
   this->id = id;
}

// instances node structure with broadcast message
uint16_t Node_fromString(Node *this,char *string)
{
   char          *token;
   char       *position;
   char      *neighbors;
   uint16_t  neighborId;
   Node       *neighbor;

   Node_init(this);
   // Decode string
   // Search for ':'
   token     = strtok(string,":");
   this->id  = atoi(token);
   position  = strtok(NULL,":");
   // Get part of string with neighbors nodes
   position  = strtok(NULL,":");
   neighbors = strtok(NULL,":");
   // Get position X and Y
   token     = strtok(position,",");
   this->x   = (float)atof(token);
   token     = strtok(NULL,",");
   this->y   = (float)atof(token);
   token     = strtok(neighbors,",");
   // For each neighbor node add in node neighbors list
   while( token != NULL){
      // Get Id
      neighborId = atoi(token);
      // Alloc node
      neighbor   = malloc(sizeof(Node));
      // instace a Node
      Node_withId( neighbor, neighborId);
      // Add to neighbor list
      Node_addNeighbor(this,neighbor);
      // gets new neighbor Id
      token      = strtok(NULL,",");
   }
   return 0;
}

// convert node structure to string
char *Node_toString(Node *this)
{
    uint16_t                           i,n;
    static char nodeInfo[100],neighbor[10];
    Node_Edge                        *edge;
    
    sprintf(nodeInfo,"%d:%f,%f",this->id,this->x,this->y);
    n = Node_neighborLength(this);
    Node_neighborHead(this);
    for( i = 0; i < n; i++){
        edge = Node_neighborNext(this);
        if (i <(n - 1)){
           sprintf(neighbor,"%d,",edge->neighborId);
        }
        else{
           sprintf(neighbor,"%d",edge->neighborId);
        }
        strcat(nodeInfo,neighbor);
    }
    return nodeInfo;
}
// Lenght of list of neighbors
void Node_neighborHead(Node *this)
{
   list_head(this->oneHop);
}


// Lenght of list of neighbors
uint16_t Node_neighborLength(Node *this)
{
   return list_length(this->oneHop);
}

// Add a new Neighbor
void Node_addNeighbor(Node *this,Node *neighbor)
{
   list_add(this->oneHop, neighbor);
}

// Get next neighbors
Node_Edge *Node_neighborNext(Node *this)
{
   return NULL;
}
// Destroy node structure
void Node_close(Node *this)
{
}

