
FLAGS = -Wall -std=c++11

all:	driver

tester: tester.o
	g++ $(FLAGS) tester.o -o tester

tester.o: tester.cpp
	g++ $(FLAGS) -c tester.cpp -o tester.o

driver:	driver.o
	g++ $(FLAGS) driver.o -o driver

driver.o:	driver.cpp
	g++ $(FLAGS) -c driver.cpp -o driver.o

clean:
	rm -f *.o driver tester