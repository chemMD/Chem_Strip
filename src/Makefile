program_CXX_SRCS := $(wildcard *.cpp)
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o} 
program_OBJS := $(program_CXX_OBJS)
$(info $$var is [${program_OBJS}])

CXXFLAGS += -Wall -std=c++0x

.PHONY: all clean cleanall

all : $(program_OBJS)

$(program_OBJS): $(program_CXX_SRCS)
	$(COMPILE.cc) $(program_CXX_SRCS)

clean :
	@- $(RM) $(program_OBJS)

cleanall :
	@- $(RM) $(program_OBJS)
	rm -rf *~ html latex
