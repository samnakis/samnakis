main: nodeDriver.cpp node.o linkedList.o
	g++ -o test nodeDriver.cpp node.o linkedList.o

node.o: node.cpp node.h
	g++ -c node.cpp node.h

linkedList.o: linkedList.cpp linkedList.h node.h
	g++ -c linkedList.cpp linkedList.h node.h

clean:
	rm -f *.o *.h.gch test