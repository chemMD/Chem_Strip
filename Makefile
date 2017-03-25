program_NAME := MD_strip
CXXFLAGS += -Wall -std=c++0x
io_OBJS := $(wildcard src/*.cpp)
program_OBJS := $(io_OBJS:.cpp=.o)

.PHONY: all clean cleanall

all : $(program_NAME)

$(program_NAME): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

$(program_strip): $(program_SRC)
	$(MAKE) -C src

clean :
	@- $(RM) $(program_OBJS)
	@- $(MAKE) clean -C src

cleanall :
	@- $(RM) $(program_OBJS)
	@- $(RM) $(program_NAME)
	@- $(MAKE) cleanall -C src