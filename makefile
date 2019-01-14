CC=gcc
WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wuninitialized -Wconversion
CFLAGS := -g -std=c99 $(WARNINGS)
LDFLAGS=
SOURCES1=Circular_linked_list.c Flavius.c TestDevoir.c 
SOURCES2=Circular_linked_list.c Flavius.c TestDevoirBis.c
OBJECTS1=$(SOURCES1:.c=.o)
OBJECTS2=$(SOURCES2:.c=.o)
EXEC1=testDevoir.exe
EXEC2=testDevoirBis.exe
#.exe not always useful 

all:    $(EXEC1) $(EXEC2)

$(EXEC1):    $(OBJECTS1)
	$(CC) $(CFLAGS) -o $(EXEC1) $(OBJECTS1) $(LDFLAGS)

$(EXEC2):    $(OBJECTS2)
	$(CC) $(CFLAGS) -o $(EXEC2) $(OBJECTS2) $(LDFLAGS)


# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:   $(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o *.exe *.out $(EXEC1) $(EXEC2)