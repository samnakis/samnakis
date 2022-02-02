# main: bitMain.cpp bitarray.o set.o
# 	g++ -o main bitMain.cpp bitarray.o set.o

main: bitMain.cpp bitarray.o set.o dictionary.o
	g++ -o main bitMain.cpp bitarray.o set.o dictionary.o

bitarray.o: bitarray.cpp bitarray.h
	g++ -c bitarray.cpp bitarray.h

set.o: set.cpp set.h bitarray.o
	g++ -c set.cpp set.h bitarray.o

dictionary.o: dictionary.cpp dictionary.h bitarray.o
	g++ -c dictionary.cpp dictionary.h bitarray.o

clean:
	rm -f *.o *.h.gch main
