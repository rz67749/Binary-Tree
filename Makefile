GPP = g++
CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors

main: Main.cpp BinaryTree.o ItemType.o
	$(GPP) $(CFLAGS) -o main Main.cpp BinaryTree.o ItemType.o

BinaryTree.o: BinaryTree.cpp BinaryTree.h ItemType.h
	$(GPP) $(CFLAGS) -c BinaryTree.cpp

ItemType.o: ItemType.cpp ItemType.h
	$(GPP) $(CFLAGS) -c ItemType.cpp


clean:
	rm -rf main
	rm -rf *.o
