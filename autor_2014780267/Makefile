# ---------------------------------------------------------------------
# Entries
# ---------------------------------------------------------------------

# Build a list of the object files to create, based on the .cs found
MODELDIRS:=$(patsubst $(MODELDIR)/%,%,$(wildcard $(MODELDIR)/*.c))
MODELOBJS:=$(patsubst $(MODELDIR)/%.c,$(FRMTRABSOBJS)/%_$(ARCH).o,$(wildcard $(MODELDIR)/trab*.c))

.SECONDEXPANSION:

$(MODELOBJS):$(FRMTRABSOBJS)/%_$(ARCH).o: $$(MODELDIR)/$$*.c
	$(COMPILER) ${COPT} ${INCFLAGS} ${DEFS} -I $(INCTRABSDIR) -c $< -o $@

modeltrabs: $(MODELOBJS)

clearall:
	rm $(BINDIR)/*
	rm $(AUTOROBJS)	
