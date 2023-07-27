CXXFLAGS = -Wall
obj = conto.o coda.o grafi.o compito.o

PROJECTNAME: $(obj)
	g++ -o PROJECTNAME $(obj)

-include dependancies

-PHONY: clean cleanall dependancies

clean:
	rm -f *o 

cleanall:
	rm -f PROJECTNAME dependancies *.o

dependancies:
	g++ -MM *.cc > dependancies
