CXX = g++
CXXFLAGS = -g -Wall
FC  = gfortran
FCFLAGS  = -g -Wall -Wno-integer-division

all: TimeInterval.o interval_tests.o ftn_div_test.o
	$(CXX) $(CXXFLAGS) -o interval_tests TimeInterval.o interval_tests.o
	$(FC) $(FCFLAGS) -o ftn_div_test ftn_div_test.o

TimeInterval.o: TimeInterval.cpp TimeInterval.h
	$(CXX) $(CXXFLAGS) -c TimeInterval.cpp

interval_tests.o: interval_tests.cpp TimeInterval.h
	$(CXX) $(CXXFLAGS) -c interval_tests.cpp

%.o: %.f90
	$(FC) $(FCFLAGS) -c $<

clean:
	\rm -f interval_tests.o TimeInterval.o interval_tests ftn_div_test.o ftn_div_test
