CC=gcc

IDIR=include
ODIR=obj
SRCDIR=src

test:	$(ODIR)/test.o $(ODIR)/dynamic_table.o $(ODIR)/get_time.o
		$(CC) -o test -g $(ODIR)/test.o $(ODIR)/dynamic_table.o $(ODIR)/get_time.o

$(ODIR)/test.o:	test.c
	$(CC) -w -o $(ODIR)/test.o -c test.c

$(ODIR)/dynamic_table.o:	$(SRCDIR)/dynamic_table.c $(IDIR)/dynamic_table.h
	$(CC) -w -o $(ODIR)/dynamic_table.o -c $(SRCDIR)/dynamic_table.c
	
$(ODIR)/get_time.o:	$(SRCDIR)/get_time.c $(IDIR)/get_time.h
	$(CC) -w -o $(ODIR)/get_time.o -c $(SRCDIR)/get_time.c


clean:
	rm -f $(ODIR)/*.o
	rm test
