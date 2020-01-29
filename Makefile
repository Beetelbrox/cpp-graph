CCC = g++
CFLAGS = -Wall -Wextra

ADJLIST = adjlist
GRAPH = graph
MAIN =  main

$(MAIN): $(MAIN).o $(ADJLIST).o
	$(CCC) $(CFLAGS) -o bin/$(MAIN) $(MAIN).o $(ADJLIST).o 

${MAIN}.o: src/$(MAIN).cpp
	$(CCC) $(CFLAGS) -c src/$(MAIN).cpp

${ADJLIST}.o: src/$(ADJLIST).cpp src/$(ADJLIST).hpp
	$(CCC) $(CFLAGS) -c src/$(ADJLIST).cpp

clean:
	rm --force *.o bin/*