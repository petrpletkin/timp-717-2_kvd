    #include "stdio.h"
    #include "stdlib.h"
    // Структуры для дерева (1-2) и 2 структуры списка (3-4), для принта
    typedef struct node
    {
        int value;
        struct node* prev;
        struct node* left;
        struct node* right;
    }node;
    typedef struct tree
    {
      struct node* root;
      int count;
    }tree;
    typedef struct l_node
    {
        struct node *value;
        struct l_node *next;
    }l_node;
    typedef struct list
    {
        l_node *tail;
        l_node *head;
    }list;

     
  // Функции очереди // 
      void listInit(list* l)
    {
        l->head = NULL;
        l->tail = NULL;
    }
       int listEmpty(list *l)
    {
      int flag = (l->tail==NULL);
      return flag;
    }

        int push_back(list *l,node *value)
    {
        l_node *tmp_l = malloc(sizeof(l_node));
        tmp_l->value = value;
        tmp_l->next = NULL;

        if(!listEmpty(l))
        {
          l->tail->next = tmp_l;
          l->tail = tmp_l;
        }else
        {
          l->head = l->tail = tmp_l;
        }
    }

    node* removeFirst(list *l)
    {
      l_node *headptr = l->head;
      node *tmp = l->head->value;

      l->head = l->head->next;

      if(l->head==NULL)
          l->tail=NULL;

      free(headptr);

      return tmp;
    }

    int flagEmpty(list *l)
    {
      l_node *headptr = l->head;
      while(headptr!=NULL)
        {
          if(headptr->value!=NULL)
          return 0;

          headptr = headptr->next;
        }
      return 1;
    }

    void listPrint(list *l)
    {
      l_node *headptr = l->head;
      while(headptr)
      {
        if(!headptr->value)
            printf("_");
        else printf("%d",headptr->value->value);

        if(headptr->next)
        printf(" ");

        headptr = headptr->next;
      }
      printf("\n");
    }
    //////////////////////////// Функции дерева ///////////////////////////////////


    void clear(tree *t,list *l)
    {
        
      node *rootptr = t->root;
      node *tmp;
      push_back(l,rootptr);
            while(listEmpty(l))
      {
       
        tmp = rootptr;
        rootptr = removeFirst(l);

        free(tmp);

        if(tmp->left != NULL)
          {
            
            push_back(l,rootptr->left);
          }
        else if(tmp->right!=NULL) {
           
            push_back(l,tmp->right);
          }
      }
        t->root = NULL;
    }

    void init(tree *t)
    {
      
        t->count = 0;
        t->root = NULL;
    }

   int find(tree *t,int value,node *n)
   {
       node *nodeptr = t->root;
       if(!nodeptr){return 1;}
       else
       {
           while(nodeptr!=NULL)
           {

               if(value > nodeptr->value)
               {
                 nodeptr = nodeptr->right;continue;
               }
               if(value < nodeptr->value)
               {
                 nodeptr = nodeptr->left; continue;
               }
               if (value == nodeptr->value)
               {
                   if(n == NULL){return 0;}
                   else {
                     printf("there");
                     n = nodeptr;
                     printf("in function find %p\n",n);
                       return 0;}
               }               
           }
       }
       return 1;
   }

  void find_and_print(tree *t,int value)
   {
      node *nodeptr = t->root;
       if(!nodeptr){printf("_");}
       else
       {
           while(nodeptr!=NULL)
           {

               if(value > nodeptr->value)
               {
                 nodeptr = nodeptr->right;continue;
               }
               if(value < nodeptr->value)
               {
                 nodeptr = nodeptr->left; continue;
               }
               if (value == nodeptr->value)
               {
                 break;
               }               
           }
        if(!nodeptr->prev) printf("_ ");
        else
        {
          printf("%d ",nodeptr->prev->value);
        }
        if(!nodeptr->left) printf("_ ");
        else
        {
          printf("%d ",nodeptr->left->value);
        }
        if(!nodeptr->right)printf("_");
        else
        {
          printf("%d",nodeptr->right->value);
        }
       }
       printf("\n");
   }
  void find1_and_print(tree *t,int value)
   {
      node *nodeptr = t->root;
       if(!nodeptr){printf("-");}
       else
       {
           while(nodeptr!=NULL)
           {

               if(value > nodeptr->value)
               {
                 nodeptr = nodeptr->right;continue;
               }
               if(value < nodeptr->value)
               {
                 nodeptr = nodeptr->left; continue;
               }
               if (value == nodeptr->value)
               {
                 break;
               }               
           }
        if(!nodeptr){printf("-\n"); return;}
        if(!nodeptr->prev) printf("_ ");
        else
        {
          printf("%d ",nodeptr->prev->value);
        }
        if(!nodeptr->left) printf("_ ");
        else
        {
          printf("%d ",nodeptr->left->value);
        }
        if(!nodeptr->right)printf("_");
        else
        {
          printf("%d",nodeptr->right->value);
        }
       }
       printf("\n");
  } 


    int delete_tree(tree* t, int value)
    {
      node* tmp = t->root;
	    node* hell;
	    node* qwe;

	        // поиск элемента на удаление
      while(tmp != NULL) {
        if(tmp->value == value)
          break;

        if(value > tmp->value) {
          // если нет нужного элемента
          if(tmp->right == NULL) {
            return 1;
          }
          tmp = tmp->right;
        }
        else  {
          // если нет нужного элемента
          if(tmp->left == NULL) {
            return 1;
          }
          tmp = tmp->left;
        }
	      }

        // если это корень
        if(tmp->value == t->root->value) {
          hell = tmp;
          // ищем самый правый элемент
          if(tmp->right != NULL) {
            hell = tmp->right;

            while(hell->left != NULL) {
              hell = hell->left;
            }
          }

          // Линковку
          hell->prev = NULL;
          hell->left = tmp->left;
          qwe = tmp;
          qwe = qwe->left;
          qwe->prev = hell;
          
          t->root = hell;
          free(tmp);
          t->count--;
          return 1;
        }

        return 0;
      }

    int insert(tree *t,int value)
    {
            if(!t->root) // если пустой
            {
                node *tmp = malloc(sizeof(node));if(!tmp){return 2;}
                tmp->value = value;
                tmp->right = NULL;
                tmp->left = NULL;
                tmp->prev = NULL; 
                t->root = tmp;
                (t->count)++;
                /* printf("1st \n");
                printf(" root %p\n\n",t->root); */
                return 0;   
            }
            if(!find(t,value,NULL)){return 1;} // проверка на существование
            else
            {
              node *prevptr;
              node *ptr = t->root;
            while(ptr)
              {
                 prevptr = ptr;
                  if( value < ptr->value)// сравнение 
                  {
                   // printf("child : %p ",ptr->left);
                    if(!ptr->left) // проверка на пустоту потомка
                    {
                      node *tmp = malloc(sizeof(node));
                      if(!tmp){return 2;}
                    tmp->value = value;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    tmp->prev = prevptr;
                    prevptr->left = tmp;

                    t->count ++;
                   // printf("\nparent: %p, my: %p ",tmp->prev,prevptr->left);
                    return 0; 
                    }
                    else {ptr = ptr->left; continue;}
                  }
                  else
                  {
                    if(!ptr->right) 
                    {
                    node *tmp = malloc(sizeof(node));
                    tmp->value = value;
                    tmp->left =NULL;
                    tmp->right = NULL;
                    tmp->prev = prevptr;
                    prevptr->right = tmp;
                    t->count ++;
                    return 0; 
                    }
                    else {ptr = ptr->right; continue;}
                  }      
              }
      
            }
                        return 1;
    }

    void print (node *n,list *l)
    {
      node *rootptr = n;
      list *l_tmp = malloc(sizeof(list));

      if(!rootptr)
      {
        printf("-\n");
        return;
      }

      push_back(l,rootptr);
      listPrint(l);

      for(;;)
      {
        while(!listEmpty(l))
        {
          rootptr = removeFirst(l);
          push_back(l_tmp,rootptr);
        }

          while(!listEmpty(l_tmp))
          {
            rootptr = removeFirst(l_tmp);
            if(rootptr == NULL )
            {
              push_back(l,NULL);
              push_back(l,NULL);
            }
            else
            {
              push_back(l,rootptr->left);
              push_back(l,rootptr->right);
            }
            
          }
            if(flagEmpty(l))
            {
              while(!listEmpty(l))
                removeFirst(l);   
              
              break;
            }
            listPrint(l);
        }
    }
 
    void printTree(tree *t, list *l)
    {
      node *rootptr = t->root;
      list *l_tmp = malloc(sizeof(list));
      listInit(l_tmp);
       // пусто ли дерево
      if(!rootptr)
      {
        printf("-\n");
        return;
      }
      // вывод корня
      push_back(l,rootptr);
      listPrint(l);
        
      for(;;) // остальной вывод
      {
        // очистка главного списка, пул в вторую
        while(!listEmpty(l))
        { 
          rootptr = removeFirst(l);
          push_back(l_tmp,rootptr);
        }
        
            //очистка второго и пул в первый
          while(!listEmpty(l_tmp))
          {
            rootptr = removeFirst(l_tmp);
            if(!rootptr)
            {
              push_back(l,NULL);
              push_back(l,NULL);
            }
            else
            {
              push_back(l,rootptr->left);
              push_back(l,rootptr->right);
            }
            
          } // чек пустоты первого
            if(flagEmpty(l)){
              while(!listEmpty(l))
                removeFirst(l);   
              break;
            }
            
            listPrint(l); 
        }
       
    }
  
    int rotateLeft(tree *t) 
    {
      node *parent = NULL,
          *C = NULL,
          *a = NULL, 
          *b = NULL;
        if(!t->root->right) return 1;

      while(t->root->right)
      {
      a = t->root;
      parent = a->prev;
      b = a->right;
      if (b == NULL) {
          return 1;
      }
      C = b->left;
  
      b->left = a;
      a->right = C;
      if (C) {
          C->prev = a;
      }
      b->prev = parent;
      if (parent) {
          if (parent->left == a) {
              parent->left = b;
          } else {
              parent->right = b;
          }
      }
      a->prev = b;
      if (!parent) {
          t->root = (t->root)->prev;
      }
        }   
        return 0;
  } 

int rotareRight(tree *t) {
    node *parent = NULL,
         *C = NULL,
         *a = NULL, 
         *b = NULL;
         if(!t->root->left) return 1;

    while(t->root->left)
    {
          b = (t->root);
          parent = b->prev;
          a = b->left;
          if (a == NULL) {
              return 1;
          }
          C = a->right;
      
          a->right = b;
          b->left = C;
          if (C) {
              C->prev = b;
          }
          a->prev = parent;
          if (parent) {
              if (parent->left == b) {
                  parent->left = a;
              } else {
                  parent->right = a;
              }
          }
          b->prev = a;
      
          t->root = (t->root)->prev;
          
    }
   return 0;
}

void test(tree *t)
{
  node *ptr = t->root;
  while(ptr)
  {
  printf("val :%d left:%p right:%p prev:%p\n",ptr->value,ptr->left,ptr->right,ptr->prev);
  ptr = ptr->right;
  }
}
    int main()
    {
      tree *t = malloc(sizeof(tree));
      list *l = malloc(sizeof(list));
      init(t);
      listInit(l);
      for(int i = 0; i < 4; i++)
      {
        int a; scanf("%d",&a);
        insert(t,a);
      }
     printTree(t,l);
     for(int i = 0; i < 3; i++)
     {
       int a;scanf("%d",&a);
       insert(t,a);
     }
      printTree(t,l);
     int M1;scanf("%d",&M1);
     find_and_print(t,M1);
     int M2; scanf("%d",&M2);
     find1_and_print(t,M2); 
     int M3; scanf("%d",&M3);
     delete_tree(t,2);
     printTree(t,l);
     rotateLeft(t);
     printTree(t,l);
     rotareRight(t);
     printTree(t,l);
     printf("%d\n",t->count); 
     clear(t,l);
     printTree(t,l); 
    }
