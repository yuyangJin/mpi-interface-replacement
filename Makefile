#If the ROSE bin directory is in your path, rose-config can be found automatically
ifndef ROSE_HOME
ROSE_HOME = $(shell rose-config prefix)
endif

include $(ROSE_HOME)/lib/rose-config.cfg

# Standard C++ compiler stuff (see rose-config --help)
ROSE_CXX         = $(shell $(ROSE_HOME)/bin/rose-config ROSE_CXX)
ROSE_CPPFLAGS    = $(shell $(ROSE_HOME)/bin/rose-config ROSE_CPPFLAGS)
ROSE_CXXFLAGS    = $(shell $(ROSE_HOME)/bin/rose-config ROSE_CXXFLAGS)
ROSE_LDFLAGS     = $(shell $(ROSE_HOME)/bin/rose-config ROSE_LDFLAGS)
ROSE_LIBDIRS     = $(shell $(ROSE_HOME)/bin/rose-config ROSE_LIBDIRS)
ROSE_RPATHS      = $(shell $(ROSE_HOME)/bin/rose-config ROSE_RPATHS)
ROSE_LINK_RPATHS = $(shell $(ROSE_HOME)/bin/rose-config ROSE_LINK_RPATHS)

MOSTLYCLEANFILES =

##############################################################################
# Assuming your source code is "demo.C" to build an executable named "demo".

all: dataFlowGraph

dataFlowGraph.o: src/dataFlowGraph.c
	$(ROSE_CXX) $(ROSE_CPPFLAGS) $(ROSE_CXXFLAGS) -o bin/$@ -c $^

dataFlowGraph: bin/dataFlowGraph.o
	$(ROSE_CXX) $(ROSE_CXXFLAGS) -o bin/$@ $^ $(ROSE_LDFLAGS) $(ROSE_LINK_RPATHS) -Wl,-rpath=$(ROSE_HOME)/lib

MOSTLYCLEANFILES += dataFlowGraph dataFlowGraph.o

##############################################################################
# Standard boilerplate

.PHONY: clean
clean:
	rm -f $(MOSTLYCLEANFILES)