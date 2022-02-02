blah: driver.cpp linearprobing.o chaining.o cuckoo.o
	g++ driver.cpp linearprobing.o chaining.o cuckoo.o -o blah

linearprobing.o: linearprobing.cpp linearprobing.h
	g++ -c linearprobing.cpp

chaining.o: chaining.cpp chaining.h
	g++ -c chaining.cpp

cuckoo.o: cuckoo.cpp cuckoo.h
	g++ -c cuckoo.cpp

Valgrind:
	valgrind --tool=memcheck --log-file=valgrindoutput.txt ./blah

ValLeak:
	valgrind --tool=memcheck --log-file=valgrindoutput.txt --leak-check=full ./blah

clean:
	rm -f *.o *.h.gch blah valgrindoutput.txt main