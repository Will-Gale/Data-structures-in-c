/****************************************
Tree variables required
 
 Devin Rose
 August, 2015
 ****************************************/

/*Created boolean data type*/
typedef int bool;
enum {false, true};

/*********************************
 Required variables for AVL Tree
*********************************/
 
/*Data type to create an AVL Tree*/
struct avlTree
{
    int (*compareFunction) (void * data1, void * data2);
    void (* destroyFunction) (void * data);
    AVLNode * root;
};
typedef struct avlTree AvlTree;

/*Required ADTs to implement an AVLTree with void pointers*/
struct avlElement
{
    void * avlVPtr;
    int nodeHeight;
    struct avlElement * leftNode;
    struct avlElement * rightNode;
};
typedef struct avlElememt AvlNode;

