#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;  
}node;
typedef struct list
{
 struct node *head;
 struct node *tail;
}list;

 void init(list* l)
{
    l->head = NULL;
    l->tail = NULL;
}
void clear (list *l)
{
    node *temp = l->head;
    while(temp!=NULL)
    {
        free(temp);
        temp = temp->next;
    }
    l->tail = NULL;
    l->head = NULL;
}
int isEmpty(list *l)
{
    if(l->head==NULL && l->tail==NULL) return 0;
    else return 1;
}

node* find(list *l,int value)
{
    node *tmp = l->head;
    while(tmp!=NULL)
    {
        if(tmp->value == value) {return tmp;}
        else tmp = tmp->next;
    }
    return NULL;
}
int push_back(list *l,int value)
{
    
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = NULL;
    if(l->head==NULL&&l->tail==NULL)
    {
      l->head = tmp;
      l->tail = tmp;
      tmp->prev = NULL;
    }
    else{
    node *ptr = l->tail;
    tmp->prev = ptr;
    ptr->next = tmp;
    l->tail = tmp;   
    }
}
int push_front(list *l,int value)
{
    node *temp = malloc(sizeof(node));
    temp->value = value;
    temp->prev = NULL;
    if(l->head==NULL && l->tail==NULL)
    {
        l->tail=temp;
        l->head=temp;
        temp->next = NULL;
        return 0;
    }
    else
    {
       node *ptr = l->head;
       ptr->prev = temp;
       temp->next = ptr;
       l->head = temp;
       return 0;
    }
    return 1;
}
int insertAfter(node *n,int value)
{
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = n->next;
    tmp->prev = n;
    n->next = tmp;
    return 0;
}
int insertBefore(node *n,int value)
{
    node *prevp = n->prev;// Указатель на предыдущий узел 
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    if(prevp==NULL)
    {
        prevp = tmp;
        tmp->next = n;
        tmp->prev = NULL;
        
    }
    else{
        tmp->value = value;
        prevp->next = tmp;
        prevp = tmp;
        tmp->next = n;
    }
    
}

int removeFirst(list *l, int value)
{
   node* headptr = l->head;
   node* tmp;
   while(headptr!=NULL)
   {
       tmp = headptr;
       headptr = headptr->next;
       if(tmp->value==value)
       {
           if(tmp->prev==NULL)
           {
               (tmp->next)->prev = NULL;
               l->head =tmp->next;
               free(tmp);break;
           }
           if(tmp->next==NULL)
           {
               (tmp->prev)->next = NULL;
               l->tail = tmp->prev;
               free(tmp);break;
           }
           else{(tmp->prev)->next = headptr;
           headptr->prev = tmp->prev;
           free(tmp);}break;
       }
   }
}

int removeLast(list *l,int value)
{
    node* tailptr = l->tail;
    node* tmp;
    while(tailptr!=NULL)
    {
        tmp = tailptr;
        tailptr = tailptr->prev;
        if(tmp->value==value)
        {
            if(tailptr==NULL)
            {
                (tmp->next)->prev = NULL;
                l->head = tmp->next;
                free(tmp);
                break;
            }
            if(tmp->next==NULL)
            {
                tailptr->next = NULL;
                l->tail = tailptr;
                free(tmp);
                break;
            }
            else
            {
                tailptr->next = tmp->next;
                (tmp->next)->prev = tailptr;
                free(tmp);
                break;
            }
        }
    }
}

void print(list *l)
{
node* ptr = l->head;
   for(;ptr!=NULL;ptr = ptr->next)
   {
    if(ptr->next==NULL)printf("%d",ptr->value);
    else  printf("%d ",ptr->value);
   }
    printf("\n");
}

void print_invers(list *l)
{
    node *tailptr = l->tail;
    for(;tailptr!=NULL;tailptr = tailptr->prev)
    {
        if(tailptr->prev == NULL) printf("%d",tailptr->value);
        else printf("%d ",tailptr->value);
    }
    printf("\n");
}
int findval(list *l,int value)
{
    node* ptr = l->head;
    for(;ptr!=NULL;ptr = ptr->next)
    {
        if(ptr->value == value)
        {
            return 1;
        }     
    }
    return 0;
}
int addAfterCount(list *l,int value,unsigned n)
{ 
   node* headptr = l->head;
   node *tmp1 = malloc(sizeof(node));
   node *tmp2;
   unsigned u = 0;
    while(u!=n)
    {
        tmp2 = headptr;
        headptr = headptr->next;
        u++;
    }
    headptr->prev = tmp1;
    tmp1->next = headptr;
    tmp1->prev = tmp2;
    tmp2->next = tmp1;
}
int addBeforeCount(list *l,int value,unsigned n)
{
    node* headptr = l->head;
    node* tmp1 = malloc(sizeof(node));
    tmp1->value = value;
    node *tmp2;
    unsigned u = 0;
    while(u!=n)
    {
        tmp2 = headptr;
        headptr = headptr->next;
        u++;
    }
    (tmp2->prev)->next = tmp1;
    tmp1->next = tmp2;
    tmp1->prev = tmp2->prev;
    tmp2->prev = tmp1;

}

int main()
{
 list l;
 unsigned n;scanf("%u",&n);
 init(&l);
 for(unsigned i=1;i<=n;i++)
 {
     int a; scanf("%d",&a);
     push_back(&l,a);
 }
 print(&l);
 for(int i=1; i <= 3;i++)
 {
     int k;scanf("%d",&k);
    printf("%d",findval(&l,k));
 }
 printf("\n");
 int m; scanf("%d",&m); push_back(&l,m);print_invers(&l);
 scanf("%d",&m); push_front(&l,m);print(&l);
 unsigned j; int x;
 scanf("%u %d",&j,&x);addAfterCount(&l,x,j);
 print_invers(&l);
 scanf("%u %d",&j,&x);addBeforeCount(&l,x,j);
 print(&l);
 int z; scanf("%d",&z);removeFirst(&l,z);print_invers(&l);
 scanf("%d",&z);removeLast(&l,z);print(&l);
 clear(&l);
}