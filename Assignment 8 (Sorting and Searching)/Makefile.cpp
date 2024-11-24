# Target to compile the object file
SortNSearch: SortNSearch.o
	g++ SortNSearch.o -o SortNSearch.exe

# Target to compile the C++ program
SortNSearch.o: SortNSearch.cpp
	g++ -c SortNSearch.cpp -o SortNSearch.o

# Target to run the program (interactively)
run: SortNSearch
	./SortNSearch.exe

# Target to compile the object Test file
SortNSearchTest: SortNSearchTest.o
	g++ SortNSearchTest.o -o SortNSearchTest.exe

# Target to compile the C++ Test program
SortNSearchTest.o: SortNSearchTest.cpp
	g++ -c SortNSearchTest.cpp -o SortNSearchTest.o

# Target to run the Test program
test: SortNSearchTest
	./SortNSearchTest.exe

# Target to clean up compiled files
clean:
	rm -f SortNSearch.o SortNSearchTest.o SortNSearch.exe SortNSearchTest.exe
