CC = clang -std=c89
CXX = clang++ -std=c++98 -x c++ # Without the -x c++, clang warns that treating C as C++ is deprecated

BASECFLAGS = -Wall -Wextra -Weverything -O0 -g -ferror-limit=30
CFLAGS = $(BASECFLAGS) -fno-asynchronous-unwind-tables
CXXFLAGS = $(BASECFLAGS)

LDCXX = clang++ -std=c++98 #Strangely, OSX terminal blows up if -x c++ is passed during the link

TEST = selftest.exe
CXXTEST = selftest.cxx.exe

SRC := EvilUnit.c

OBJ := EvilUnit.o

CXXOBJ := EvilUnit.cxx.o

all:	$(TEST) $(CXXTEST)
	./$(TEST)
	./$(CXXTEST)

%.o:	%.c EvilUnit.h
	$(CC) $(CFLAGS) -c $< -o $@

%.cxx.o:	%.c EvilUnit.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CXXTEST):	$(CXXOBJ) EvilUnit.cxx.o
	$(LDCXX) $(CXXFLAGS) $^ -o $@

$(TEST):	$(OBJ) EvilUnit.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o *.exe
	$(RM) *~
