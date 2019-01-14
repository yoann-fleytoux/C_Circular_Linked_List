#include "Flavius.h"

flavius_grp *new_flavius_grp;

/*
 *CREATE NEW FLAVIUS GRP WITH INT
 */
flavius_grp *init(int in_interval){
    new_flavius_grp = (flavius_grp *)malloc(sizeof(flavius_grp));
    if(new_flavius_grp==NULL){
        fprintf(stderr, "Error error allocation\n");
        exit(1);
    }
    if(in_interval<0){
    	new_flavius_grp->kill_interval = -in_interval;
    	new_flavius_grp->trigo=1;
    }else{
    	new_flavius_grp->kill_interval = in_interval; 
    	new_flavius_grp->trigo=0;
    }
    
  	new_flavius_grp->people= create_curr_list();
    return new_flavius_grp;
}

/*
 *RETURN TRUE IS LIST EMPTY
 */
bool is_empty(flavius_grp *in){
    return in->people->number==0;
}

/*
 *ADDS NEW NODE TO FLAVIUS GRP'S PEOPLE WITH GRP
 */
void add(flavius_grp *in){
	int info;
	printf("enter the value you would like to add:\n");
    scanf("%d", &info);
   	add_node(info, in->people);
}

/*
 *ADDS NEW NODE INFO TO FLAVIUS GRP'S PEOPLE WITH GRP
 */
void add_int(int info, flavius_grp *in){
   	add_node(info, in->people);
}

/*
 *DELETE NODE OF FLAVIUS GRP'S PEOPLE AT KILL_AT WITH GRP
 */
void kill(int kill_at, flavius_grp *in){
	delete_node_position(kill_at, in->people);
}

/*
 *DELETE NODE OF FLAVIUS GRP'S PEOPLE OF VAL VALUE WITH GRP
 */
void kill_val(int value, flavius_grp *in){
	search_and_destroy(value, in->people);
}

/*
 *DISPLAY NODE OF FLAVIUS GRP'S PEOPLE WITH GRP
 */
void print(flavius_grp *in){
	display_from_beg(in->people);
	printf("\n");

}

/*
 * SOLVE THE GAME DISPLAYING KILLED(KILLER) UNTIL ONE SURVIVOR WITH GRP
 */
 /*
int solve(flavius_grp *in){
	int killed_in_list,killer;
	killed_in_list=(1+in->kill_interval+1)%in->people->number;
	killer=1;
	while(in->people->number!=1){
		display_node_position(killed_in_list, in->people);
		printf("(");
		display_node_position(killer, in->people);
		printf(")");
		printf(",");
		kill(killed_in_list, in);
		killer=killed_in_list-1;
		if(killer==0)
			killer=in->people->number;
		killed_in_list=(killed_in_list+in->kill_interval)%in->people->number;
		if(killed_in_list==0)
			killed_in_list=in->people->number;		
	}
	print(in);
	return get_first_value(in->people);
}
*/

/*
 * SOLVE THE GAME DISPLAYING KILLED(KILLER) UNTIL ONE SURVIVOR WITH GRP
 */
int solve(flavius_grp *in){
	struct node* curr_killer=in->people->first;
	struct node* curr_killed=curr_killer;
	curr_killed=fwd(in->kill_interval+1, curr_killed);
	while(in->people->number!=1){
		printf("%d(%d),",get_value(curr_killed),get_value(curr_killer));
		curr_killer=bck(1, curr_killed);
		kill_val(get_value(curr_killed), in);
		curr_killed=fwd(in->kill_interval+1, curr_killer);
		//print(in);
	}
	print(in);
	return get_first_value(in->people);
}

/*
 * SOLVE THE GAME DISPLAYING KILLED(KILLER) UNTIL ONE SURVIVOR WITH GRP (TRIGO)
 */
int solve_neg(flavius_grp *in){
	struct node* curr_killer=in->people->first;
	struct node* curr_killed=curr_killer;
	curr_killed=bck(in->kill_interval+1, curr_killed);
	while(in->people->number!=1){
		printf("%d(%d),",get_value(curr_killed),get_value(curr_killer));
		curr_killer=fwd(1, curr_killed);
		kill_val(get_value(curr_killed), in);
		curr_killed=bck(in->kill_interval+1, curr_killer);
		//print(in);
	}
	print(in);
	return get_first_value(in->people);
}

/*
 * SOLVE THE GAME DISPLAYING KILLED(KILLER) UNTIL ONE SURVIVOR WITH GRP NO SUICIDE
 */
int solve_bis(flavius_grp *in){
	struct node* curr_killer=in->people->first;
	struct node* curr_killer_scnd=in->people->first;
	struct node* curr_killed=curr_killer;
	curr_killed=fwd(in->kill_interval+1, curr_killed);
	while(in->people->number!=1){
		//if SUICIDE, person to the right of the killed is the killer, normal fonctionment later
		if(curr_killed==curr_killer){
			curr_killer_scnd=bck(1, curr_killed);
			printf("%d(%d),",get_value(curr_killed),get_value(curr_killer_scnd));
		}else
			printf("%d(%d),",get_value(curr_killed),get_value(curr_killer));
		curr_killer=bck(1, curr_killed);
		//kill(killed_in_list, in);
		kill_val(get_value(curr_killed), in);
		curr_killed=fwd(in->kill_interval+1, curr_killer);
		//print(in);
	}
	print(in);
	return get_first_value(in->people);
}

/*
 * SOLVE THE GAME DISPLAYING KILLED(KILLER) UNTIL ONE SURVIVOR WITH GRP NO SUICIDE(TRIGO)
 */
int solve_neg_bis(flavius_grp *in){
	struct node* curr_killer=in->people->first;
	struct node* curr_killed=curr_killer;
	struct node* curr_killer_scnd=curr_killer;
	curr_killed=bck(in->kill_interval+1, curr_killed);
	while(in->people->number!=1){
		//if SUICIDE, person to the left of the killed is the killer, normal fonctionment later
		if(curr_killed==curr_killer){
			curr_killer_scnd=fwd(1, curr_killed);
			printf("%d(%d),",get_value(curr_killed),get_value(curr_killer_scnd));
		}else
			printf("%d(%d),",get_value(curr_killed),get_value(curr_killer));
		curr_killer=fwd(1, curr_killed);
		kill_val(get_value(curr_killed), in);
		curr_killed=bck(in->kill_interval+1, curr_killer);
		//print(in);
	}
	print(in);
	return get_first_value(in->people);
}
