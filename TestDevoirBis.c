#include "Circular_linked_list.h"
#include "Flavius.h"

int main(int argc,char *argv[]){//argv[0]= prog name, argc>0
    if(argc!=3){
        fprintf(stderr,"Error Usage: testDevoirBis int int\n");
        exit(1);
    }
    int r=-1;
    struct flavius_grp *curr= init(atoi(argv[2]));
    for(int i=1;i<=atoi(argv[1]);i++){
        add_int(i,curr);
    }
    if(is_empty(curr)){
        fprintf(stderr,"Error empty grp\n");
        exit(2);
    }
    if(curr->trigo)
        r= solve_neg_bis(curr);
    else
        r= solve_bis(curr);
    delete_node_position(1, curr->people);
    free(curr->people);
    free(curr);
    return r;
}
