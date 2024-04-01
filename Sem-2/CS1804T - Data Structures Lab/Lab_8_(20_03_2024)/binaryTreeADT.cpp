#include <stdio.h>
#include <stdlib.h>

class binTree{
    private:
        struct Node{
            int data;
            struct Node *Left;
            struct Node *Right;
        };
        struct Node *temp;
        struct Node *newNode;
        struct Node *Root;
        struct Node *SearchParent;
        struct Node *SearchChild;
        void recInsert(int,int,struct Node*);
        int recSearch(int,struct Node*);
        struct Node *recGetLeaf(struct Node*);
        void recInOrder(struct Node*);
        void recPreOrder(struct Node*);
        void recPostOrder(struct Node*);
    
    public:
        binTree(){
            Root = nullptr;
        }
        struct Node *CreateNode();
        void Insert(int);
        int Search(int);
        int Delete(int);
        void InOrder();
        void PreOrder();
        void PostOrder();


};


int main(){
    binTree T1;
    int opt=1,data;
    while (opt!=0){
        system("cls");
        system("cls");
        printf("\nOptions : \n\t1 - Insert\n\t2 - Delete\n\t3 - Preorder\n\t4 - Inorder\n\t5 - Postorder\n\t6 - Search\n\t7 - Exit\n\t0 - Exit\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter data to insert : ");
            scanf("%d",&data);
            T1.Insert(data);
            break;
        case 2:
            break;
        case 3:
            T1.PreOrder();
            break;
        case 4:
            T1.InOrder();
            break;
        case 5:
            T1.PostOrder();
            break;
        case 6:
            printf("Enter data to search : ");
            scanf("%d",&data);
            if(T1.Search(data)==1){
                printf("Found element inside the tree");
            }else{
                printf("This element is not found in the tree");
            }
            break;
        case 0:
            break;
        default:
            break;
        }
        printf("\n\n(Press enter to continue)");
        getchar();
        getchar();
    }
}





// Method to allocate space for new node and return the pointer to it
struct binTree::Node * binTree::CreateNode(){
    return (struct Node*)malloc(sizeof(struct Node));
}

// A recursive method to insert a New Node
void binTree::recInsert(int val,int dir,struct Node*Root){
    printf("\n--Currently at Node : ( %d )",Root->data);
    switch (dir)
    {
    case 1:
        if(Root->Left == nullptr){
            newNode = CreateNode();
            newNode->data = val;
            Root->Left = newNode;
            newNode->Left = nullptr;
            newNode->Right = nullptr;
        }else{
            printf("\n\nEnter the Direction : \n\t1 - Left\n\t2 - Right\n>>>");
            scanf("%d",&dir);
            recInsert(val,dir,Root->Left);
        }
        break;
    case 2:
        if(Root->Right == nullptr){
            newNode = CreateNode();
            newNode->data = val;
            Root->Right = newNode;
            newNode->Left = nullptr;
            newNode->Right = nullptr;
        }else{
            printf("\n\nEnter the Direction : \n\t1 - Left\n\t2 - Right\n>>>");
            scanf("%d",&dir);
            recInsert(val,dir,Root->Right);
        }
        break;
    default:
        break;
    }
}


// Method to Insert A node into the tree
void binTree::Insert(int val){
    if(Root == nullptr){
        newNode = CreateNode();
        newNode->data = val;
        Root = newNode;
        newNode->Left = nullptr;
        newNode->Right = nullptr;
    }else{
        int dir = 0;
        printf("\n--Currently at Node : ( %d )\n\nEnter the Direction : \n\t1 - Left\n\t2 - Right\n>>>",Root->data);
        scanf("%d",&dir);
        recInsert(val,dir,Root);
    }
}

// Method to print data of the tree recursively and INORDER
void binTree::recInOrder(struct Node *Root){
    if(Root->Left != nullptr){
        recInOrder(Root->Left);
    }
    printf(" %d ",Root->data);
    if(Root->Right != nullptr){
        recInOrder(Root->Right);
    }
}


// Method to print data of tree INORDER
void binTree::InOrder(){
    if(Root != nullptr){
        recInOrder(Root);
    }
    else{
        printf("Tree is Empty");
    }
}

// Method to print data of the tree recursively and PREORDER
void binTree::recPreOrder(struct Node *Root){
    printf(" %d ",Root->data);
    if(Root->Left != nullptr){
        recPreOrder(Root->Left);
    }
    if(Root->Right != nullptr){
        recPreOrder(Root->Right);
    }
}


// Method to print data of tree PREORDER
void binTree::PreOrder(){
    if(Root != nullptr){
        recPreOrder(Root);
    }
    else{
        printf("Tree is Empty");
    }
}


// Method to print data of the tree recursively and POSTORDER
void binTree::recPostOrder(struct Node *Root){
    if(Root->Left != nullptr){
        recPostOrder(Root->Left);
    }
    if(Root->Right != nullptr){
        recPostOrder(Root->Right);
    }
    printf(" %d ",Root->data);
}


// Method to print data of tree POSTORDER
void binTree::PostOrder(){
    if(Root != nullptr){
        recPostOrder(Root);
    }
    else{
        printf("Tree is Empty");
    }
}

// Recursive method to earch for a value in the tree using preorder
int binTree::recSearch(int val,struct Node *root){
    if(root==nullptr){
        return 0;
    }else{
        if(SearchChild != nullptr && SearchParent == nullptr){
            SearchParent = root;
        }
        if(root->data == val){
            SearchChild = root;
        }
        return (root->data==val || recSearch(val,root->Left) || recSearch(val,root->Right));
    }
}



// Method to search for a value in the tree using Preorder
int binTree::Search(int val){
    SearchChild = nullptr;
    SearchParent = nullptr;
    if(recSearch(val,Root)==1){
        return 1;
    }else{
        return 0;
    }
}

//Method to delete an element form the tree
int binTree::Delete(int val){
    if(Search(val)==1){
        
    }return 0;
}
