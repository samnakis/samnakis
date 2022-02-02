blah: driver.cpp congaline.o node.o pirate.o
	g++ driver.cpp congaline.o node.o pirate.o -o blah

node.o: node.cpp node.h
	g++ -c node.cpp node.h

congaline.o: congaline.cpp congaline.h 
	g++ -c congaline.cpp congaline.h

pirate.o: pirate.cpp pirate.h
	g++ -c pirate.cpp pirate.h

Valgrind:
	valgrind --tool=memcheck --log-file=valgrindoutput.txt ./blah

ValLeak:
	valgrind --tool=memcheck --log-file=valgrindoutput.txt --leak-check=full ./blah

clean:
	rm -f *.o *.h.gch blah valgrindoutput.txt main