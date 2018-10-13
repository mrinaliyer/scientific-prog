logseries.exe: logseries.o aitken.o
	g++ -o logseries.exe logseries.o aitken.o -lm

leibnitz.exe: leibnitz.o aitken.o
	g++ -o leibnitz.exe leibnitz.o aitken.o -lm

aitken.o: aitken.cpp aitken.hpp
	g++ -c aitken.cpp

logseries.o: logseries.cpp aitken.hpp
	g++ -c logseries.cpp

leibnitz.o: leibnitz.cpp aitken.hpp
	g++ -c leibnitz.cpp

clean:
	rm -f *.o *.exe
