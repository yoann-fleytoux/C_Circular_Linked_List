#include "Circular_linked_list.h"

struct node{
    int val;
    struct node *next;
    struct node *prev;
};

n *new, *ptr, *prev;
curr_list *new_curr_list;

/*
 *CREATE NEW LIST
 */
curr_list* create_curr_list(){
    new_curr_list = (curr_list *)malloc(sizeof(curr_list));
    if(new_curr_list==NULL){
        fprintf(stderr, "Error error allocation\n");
        exit(1);
    }
    new_curr_list->first = NULL, 
    new_curr_list->last = NULL;
    new_curr_list->number = 0;
    return new_curr_list;
}

/*
 *CREATE NEW NODE INFO WITH LIST
 */
n* create_node(int info, curr_list *in){
    in->number++;
    new = (n *)malloc(sizeof(n));
    if(new==NULL){
        fprintf(stderr, "Error error allocation\n");
        exit(2);
    }
    new->val = info;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

/*
 *ADDS NEW NODE INFO WITH LIST
 */
void add_node(int info, curr_list *in){
    new = create_node(info, in);
    if (in->first == in->last && in->first == NULL) {
        in->first = in->last = new;
        in->first->next = in->last->next = NULL;
        in->first->prev = in->last->prev = NULL;
    }else{
        in->last->next = new;
        new->prev = in->last;
        in->last = new;
        in->last->next = in->first;
        in->first->prev = in->last;
    }
}


/*
 *DELETE NODE AT POS WITH LIST
 */
void delete_node_position(int pos, curr_list *in){    
    int i;
    n *prevnode;
    if (in->first == in->last && in->first == NULL)
        fprintf(stderr,"empty linked list you cant delete\n");
    else{
        if (in->number < pos)
            fprintf(stderr,"node cant be deleted at position as it is exceeding the linkedlist length\n");
        else{
            for (ptr = in->first,i = 1;i <= in->number;i++){
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1){    
                    in->number--;
                    in->last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    in->first = ptr;
                    free(prevnode);
                    break;        
                }else{ 
                    if (i == pos - 1){  
                        in->number--;
                        prevnode->next = ptr->next;
                        ptr->next->prev = prevnode;
                        free(ptr);
                        break;
                    }
                }
            }
        }
    }
}

/*
 *DELETE NODE VALUE WITH LIST
 */
void search_and_destroy(int value, curr_list *in){    
    int count = 0, i, f = 0;
    if (in->first == in->last && in->first == NULL)
        fprintf(stderr,"list is empty no elements in list to search\n");
    else{
        for (ptr = in->first,i = 0;i < in->number;i++,ptr = ptr->next){
            count++;
            if (ptr->val == value){
               // printf("the value is found at position at %d\n", count);
                delete_node_position(count, in);
                f = 1;
            }    
        }
        if (f == 0)
            fprintf(stderr,"the value is not found in linkedlist\n");
    }
}


/*
 *DISPLAY FROM BEGINNING WITH LIST
 */
void display_from_beg(curr_list *in){
    int i;
    if (in->first == in->last && in->first == NULL)
        fprintf(stderr,"list is empty no elemnts to print\n");
    else{    
        for (ptr = in->first, i = 0;i < in->number;i++,ptr = ptr->next)
            printf("%d ", ptr->val);
    }
}

/*
 *DELETE NODE AT POS WITH LIST
 */
void display_node_position(int pos, curr_list *in){    
    int i;
    n *prevnode;
    if (in->number < pos)
        fprintf(stderr,"node cant be displayed as position is exceeding the linkedlist length\n");
    else{
        for (ptr = in->first, i = 1;i <= in->number;i++){
            prevnode = ptr;
            ptr = ptr->next;
            if(pos==1){
                printf("%d", prevnode->val);
                break;
            }
            if (i == pos-1){
                printf("%d", ptr->val);
                break;
            }
        }
    }
}

/*
 * RETURN FIRST VALUE WITH LIST
 */
int get_first_value(curr_list *in){       
    if (in->first == in->last && in->first == NULL)
        fprintf(stderr,"list is empty there are no elments\n");
    else
            return in->first->val;
    return 0;
}

/*
 * RETURN VALUE OF NODE
 */
int get_value(n *in){
    int r=in->val;
    return r;
}

/*
 * RETURN THE NODE IN MOVED FWD TIMES TIMES
 */
n* fwd(int times, n *in){
    int i;
    for (ptr = in,i = 0;i < times;i++,ptr = ptr->next);
    return ptr;
}

/*
 * RETURN THE NODE IN MOVED BCK TIMES TIMES
 */
n* bck(int times, n *in){
    int i;
    for (ptr = in,i = 0;i < times;i++,ptr = ptr->prev);
    return ptr;
}