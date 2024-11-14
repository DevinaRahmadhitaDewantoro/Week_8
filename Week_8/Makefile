# Target to compile the object file
sortingandSearch: sortingandSearch.o
	g++ sortingandSearch.o -o sortingandSearch.exe

# Target to compile the C++ program
sortingandSearch.o: sortingandSearch.cpp
	g++ -c sortingandSearch.cpp -o sortingandSearch.o

# Target to run the program (interactively)
run: sortingandSearch
	./sortingandSearch.exe

# Target to compile the object Test file
sortingandSearchTest: sortingandSearchTest.o
	g++ sortingandSearchTest.o -o sortingandSearchTest.exe

# Target to compile the C++ Test program
sortingandSearchTest.o: sortingandSearchTest.cpp
	g++ -c sortingandSearchTest.cpp -o sortingandSearchTest.o

# Target to run the Test program
test: sortingandSearchTest
	./sortingandSearchTest.exe

# Target to clean up compiled files
clean:
	rm -f sortingandSearch.o sortingandSearchTest.o sortingandSearch.exe sortingandSearchTest.exe