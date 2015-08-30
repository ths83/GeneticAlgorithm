OBJ=main.o CGene.o CGeneList.o CChromosome.o CDistance.o CParty.o CElite.o CClientTCP.o CColor.o

test:$(OBJ)
	g++ -Wall -g $(OBJ) -o test -lm
	rm *.o
	./test

main.o:main.cc
	g++ -c -g main.cc

CGene.o:CGene.cc CGene.h
	g++ -c -g CGene.cc

CGeneList.o:CGeneList.cc CGeneList.h
	g++ -c -g CGeneList.cc
	
Path.o:CChromosome.cc CChromosome.h
	g++ -c -g CChromosome.cc
	
CDistance.o:CDistance.cc CDistance.h
	g++ -c -g CDistance.cc
	
PathList.o:CParty.cc CParty.h
	g++ -c -g CParty.cc
	
CElite.o:CElite.cc CElite.h
	g++ -c -g CElite.cc

CClientTCP.o:CClientTCP.cc CClientTCP.h
	g++ -c -g CClientTCP.cc
	
CColor.o:CColor.cc CColor.h
	g++ -c -g CColor.cc
