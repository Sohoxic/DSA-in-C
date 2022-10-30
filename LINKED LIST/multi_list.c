typedef struct matrixNode *matrixPointer;
typedef enum {head,data} tagfield;
typedef entryNode{
    int row;
    int column;
    int value;
};
typedef
typedef struct matrixNode{
    matrixPointer right;
    matrixPointer down;
    tagfield tag;
    union
    {
        matrixPointer next;
        entryNode entry;
    }u;
    
}
