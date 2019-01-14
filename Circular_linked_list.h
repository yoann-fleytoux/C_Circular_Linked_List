#ifndef __CIRCULAR_LINKED_LIST_H__
#define __CIRCULAR_LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node n;

typedef struct curr_list{
    struct node *first;
    struct node *last;
    int number;
}curr_list;


/*
 *CREATE NEW LIST
 */
curr_list* create_curr_list();

/*
 *CREATE NEW NODE INFO WITH LIST
 */
n* create_node(int info, curr_list *in);

/*
 *ADDS NEW NODE INFO WITH LIST
 */
void add_node(int info, curr_list *in);

/*
 *DELETE NODE AT POS WITH LIST
 */
void delete_node_position(int pos, curr_list *in);

/*
 *DELETE NODE VALUE WITH LIST
 */
void search_and_destroy(int value, curr_list *in);

/*
 *DISPLAY FROM BEGINNING WITH LIST
 */
void display_from_beg(curr_list *in);

/*
 *DISPLAY NODE AT POS WITH LIST
 */
void display_node_position(int pos, curr_list *in);

/*
 * RETURN FIRST VALUE WITH LIST
 */
int get_first_value(curr_list *in);

/*
 * RETURN VALUE OF NODE
 */
int get_value(n *in);

/*
 * RETURN THE NODE IN MOVED FWD TIMES TIMES
 */
n* fwd(int times, n *in);

/*
 * RETURN THE NODE IN MOVED BCK TIMES TIMES
 */
n* bck(int times, n *in);

#endif
