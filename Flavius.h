#ifndef __FLAVIUS_H__
#define __FLAVIUS_H__

#include "Circular_linked_list.h"
#include <string.h>
#include <stdbool.h>

/*	QU 1
Type Abstrait:flavius_grp
***************************************
Utilise: Circular_Linked_list,Integer,Boolean
***************************************
Opérations:

init: int ->flavius_grp *

is_empty:flavius_grp * -> Boolean

add:flavius_grp *in);

add_int:int X flavius_grp *

kill:int X flavius_grp *

kill_val:int X flavius_grp *

print: flavius_grp *

solve:flavius_grp * -> int

solve_neg:flavius_grp * -> int

solve_bis:flavius_grp * -> int

solve_neg_bis:flavius_grp * -> int
**************************************
Pré-conditions: in est un flavius_grp in_int est un int

kill(in_int, in); -> \is_empty(in)

kill_val(in_int, in); -> \is_empty(in)

print(in); -> \is_empty(in)

solve(in); -> \is_empty(in)

solve_neg(in); -> \is_empty(in)

solve_bis(in); -> \is_empty(in)

solve_neg_bis(in); -> \is_empty(in)

*/


typedef struct flavius_grp{
	curr_list *people;
	int kill_interval;
	int trigo;
}flavius_grp;

/*
 *CREATE NEW FLAVIUS GRP WITH INT
 */
flavius_grp *init(int in_interval);

/*
 *RETURN TRUE IS LIST EMPTY
 */
bool is_empty(flavius_grp *in);

/*
 *ADDS NEW NODE TO FLAVIUS GRP'S PEOPLE WITH GRP
 */
void add(flavius_grp *in);

/*
 *ADDS NEW NODE INFO TO FLAVIUS GRP'S PEOPLE WITH GRP
 */
void add_int(int info, flavius_grp *in);

/*
 *DELETE NODE OF FLAVIUS GRP'S PEOPLE AT KILL_AT WITH GRP
 */
void kill(int kill_at, flavius_grp *in);


/*
 *DELETE NODE OF FLAVIUS GRP'S PEOPLE OF VAL VALUE WITH GRP
 */
void kill_val(int value, flavius_grp *in);

/*
 *DISPLAY NODE OF FLAVIUS GRP'S PEOPLE WITH GRP
 */
void print(flavius_grp *in);

/*
 * SOLVE THE GAME DISPLAYING KILLED(KILLER) UNTIL ONE SURVIVOR WITH GRP
 */
int solve(flavius_grp *in);

/*
 * SOLVE THE GAME DISPLAYING KILLED(KILLER) UNTIL ONE SURVIVOR WITH GRP (TRIGO)
 */
int solve_neg(flavius_grp *in);

/*
 * SOLVE THE GAME DISPLAYING KILLED(KILLER) UNTIL ONE SURVIVOR WITH GRP NO SUICIDE
 */
int solve_bis(flavius_grp *in);

/*
 * SOLVE THE GAME DISPLAYING KILLED(KILLER) UNTIL ONE SURVIVOR WITH GRP NO SUICIDE(TRIGO)
 */
int solve_neg_bis(flavius_grp *in);

#endif
