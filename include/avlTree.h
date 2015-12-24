/****************************************
Tree variables required
 
 Devin Rose
 August, 2015
 ****************************************/

/*********************************
 Required variables for AVL Tree
*********************************/

/*Type definitions for avl tree functions*/
typedef struct avlTree AvlTree;
typedef struct AvlElememt AvlNode;

/*Data type to create an AVL Tree*/
struct avlTree
{
    int (*compareAvl) (void * data1, void * data2);
    void (* destroyAvl) (void * data);
    void (* printAvl) (void * dataToPrint);
    AvlNode * root;
};

/*Required ADTs to implement an AVLTree with void pointers*/
struct AvlElement
{
    void * avlVPtr;
    int nodeHeight;
    struct avlElement * leftNode;
    struct avlElement * rightNode;
};


/******
 Utility Functions
******/

/*checks if the tree is empty, 
returns 1 for true and 0 for false*/
int isEmpty (AvlNode * root);

/*finds the height of the left child node*/
int findLeftHeight(AvlNode * treeRoot);

/*finds the height of the right child node*/
int findRightHeight(AvlNode * treeRoot);

/*finds the max child height*/
int findMaxChildHeight(AvlNode * findMax);

/*returns the left sub tree if the node passed*/
AvlTree * getLeftAvlSubtree (AvlTree * node);

/*returns the right sub tree if the node passed*/
AvlTree * getRightAvlSubtree (AvlTree * node);

/*returns a void pointer to the data*/
void * getRootData (AvlTree * node);




/******
 AVLTree operation functions
******/

/*initializes a binary tree, allocates enough memory*/
AvlTree * createAVLTree(int (*comparePointer) (void * data1, void * data2), int (*printPointer) (void *), void (*destroyPointer) (void *));

/*removes a node from the AVL tree
AVLNode * deleteAvlNode(AvlTree * theTree, AvlNode * treeRoot);*/

/*called from destroy tree to free all memory*/
void destroyAvlTree(AvlNode * toDie, void (*destroyPointer) (void *));

/*frees the allocated memory within the node*/
void destroyAvlNode(AvlNode * treeNode, void (*destroyPointer) (void *));

/*double rotation functions*/
AvlNode * doubleRotateWithLeftChild (AvlNode * oldRoot);
AvlNode * doubleRotateWithRightChild (AvlNode * oldRoot);

/*finds the minimum node in the tree*/
AvlNode * findMin(AvlNode * root);

/*inserts a node into the AVL tree, only used for testing*/
AvlNode * addToAvlTree(AvlNode * root, AvlTree * Avltree, void * data);

/*single rotation functions*/
AvlNode * rotateRightWithLeftChild(AvlNode * oldRoot);
AvlNode * rotateLeftWithRightChild(AvlNode * oldRoot);
AvlNode * rotateWithLeftChild (AvlNode * nodeToRotate);
AvlNode * rotateWithRightChild (AvlNode * nodeToRotate);
