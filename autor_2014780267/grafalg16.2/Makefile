ARCH:=$(shell getconf LONG_BIT)

# ---------------------------------------------------------------------
# Directories
# ---------------------------------------------------------------------

# Source codes
WKSPCDIR:=$(HOME)/Grafos_e_Algoritmos/aa/LABGADIR
GRAPHDIR:=$(WKSPCDIR)/graph
HEAPDIR:=$(WKSPCDIR)/datast
GRAFALGDIR:=$(WKSPCDIR)/grafalg16.2

TRABSDIR:=$(WKSPCDIR)/progs/grafalg16.2
SRCDIR:=$(TRABSDIR)/src

# Object codes
LIBDIR=$(GRAFALGDIR)/lib
TRABSLIBDIR=$(TRABSDIR)/lib

# Executable codes
BINDIR=$(TRABSDIR)/bin

# Source codes
INCTRABSDIR:=$(GRAFALGDIR)/include

# ---------------------------------------------------------------------
# Compiler options 
# ---------------------------------------------------------------------

COMPILER= gcc
COPT=-m$(ARCH) -O -fpic -fexceptions -DNDEBUG -Wno-unused-result
DEFS= -D_ARCH$(ARCH)_
INCFLAGS = -I$(HEAPDIR) -I$(GRAPHDIR) -I$(INCTRABSDIR)
LIBFLAGS = -L$(LIBDIR) -Wl,-rpath=$(LIBDIR)

# ---------------------------------------------------------------------
# Entries
# ---------------------------------------------------------------------

# Build a list of the object files to create, based on the .cs found
AUTORTRABS:=$(patsubst $(SRCDIR)/trab%.c,trab%,$(wildcard $(SRCDIR)/trab*.c))
AUTOROBJS:=$(patsubst $(SRCDIR)/trab%.c,$(TRABSLIBDIR)/trab%_$(ARCH).o,$(wildcard $(SRCDIR)/trab*.c))

.SECONDEXPANSION:

$(AUTOROBJS):$(TRABSLIBDIR)/trab%_$(ARCH).o: $$(SRCDIR)/trab$$*.c
	echo $<
	$(COMPILER) ${COPT} ${INCFLAGS} ${DEFS} -c $< -o $@

$(AUTORTRABS):trab%: $(AUTOROBJS)
	$(COMPILER) ${COPT} $(LIBFLAGS) ${DEFS} $^ -o $(BINDIR)/$@_$(ARCH) -ltrab_main_$(ARCH)

alltrabs: $(AUTOROBJS) # $(AUTORTRABS)
	$(COMPILER) ${COPT} $(LIBFLAGS) ${DEFS} $^ -o $(BINDIR)/trabs_$(ARCH) -ltrab_main_$(ARCH)

clearall:
	rm $(AUTOROBJS)	
	rm $(BINDIR)/*

mainc:
