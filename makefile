CC = clang -std=c89
CXX = clang++ -std=c++98 -x c++ # Without the -x c++, clang warns that treating C as C++ is deprecated

BASECFLAGS = -Wall -Wextra -Weverything -O0 -g -ferror-limit=30
CFLAGS = $(BASECFLAGS) -fno-asynchronous-unwind-tables
CXXFLAGS = $(BASECFLAGS)

LDCXX = clang++ -std=c++98 #Strangely, OSX terminal blows up if -x c++ is passed during the link

TEST = selftest.exe
CXXTEST = selftest.cxx.exe

SRC := $(wildcard evilunit_selftest_*.c)

OBJ=$(SRC:%.c=%.o) EvilUnit.o

CXXOBJ=$(SRC:%.c=%.cxx.o) EvilUnit.cxx.o

PRECOMPILER = clang -std=c89 -E -C -P -DPRECOMPILATION

all:	$(TEST) $(CXXTEST) EvilUnit.pre.h EvilUnit.pre.c
	./$(TEST)
	./$(CXXTEST)


EvilUnit.pre.h:	EvilUnit.h
	$(PRECOMPILER) $< -o $@

EvilUnit.pre.c:	EvilUnit.c
	$(PRECOMPILER) $< -o $@

%.o:	%.c EvilUnit.h
	$(CC) $(CFLAGS) -c $< -o $@

%.cxx.o:	%.c EvilUnit.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CXXTEST):	$(CXXOBJ) evilunit_selftest.cxx.o
	$(LDCXX) $(CXXFLAGS) $^ -o $@

$(TEST):	$(OBJ) evilunit_selftest.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o *.exe
	$(RM) *~
	$(RM) *.pre.h *.pre.c
