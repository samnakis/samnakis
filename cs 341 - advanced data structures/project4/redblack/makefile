blah: driver.cpp node.o
	g++ driver.cpp node.o -o blah

node.o: node.cpp node.h
	g++ -c node.cpp

Valgrind:
	valgrind --tool=memcheck --log-file=valgrindoutput.txt ./blah

ValLeak:
	valgrind --tool=memcheck --log-file=valgrindoutput.txt --leak-check=full ./blah

clean:
	rm -f *.o *.h.gch blah valgrindoutput.txt main