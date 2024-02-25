CC = clang -std=c89
CXX = clang++ -std=c++98 -x c++ # Without the -x c++, clang warns that treating C as C++ is deprecated

BASECFLAGS = -Wall -Wextra -O0 -g -ferror-limit=30
CFLAGS = $(BASECFLAGS) -fno-asynchronous-unwind-tables
CXXFLAGS = $(BASECFLAGS)

LDCXX = clang++ -std=c++98 #Strangely, OSX terminal blows up if -x c++ is passed during the link

TEST = selftest.exe
CXXTEST = selftest.cxx.exe

all:	$(TEST) $(CXXTEST)
	./$(TEST)
	./$(CXXTEST)

HDR := EvilUnit.h EvilUnit_contract.h
SRC := EvilUnit_selftest.c EvilUnit_main.c EvilUnit_contract.c EvilUnit_contract_none.c EvilUnit_contract_libc.c EvilUnit_contract_clang.c EvilUnit_contract_gcc.c

%.o:	%.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

%.cxx.o:	%.c $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CXXTEST):	$(SRC:.c=.cxx.o)
	$(LDCXX) $(CXXFLAGS) $^ -o $@

$(TEST):	$(SRC:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o *.exe

