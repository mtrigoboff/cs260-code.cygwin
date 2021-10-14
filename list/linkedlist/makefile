SUBDIRS = $(wildcard */.)

.PHONY: all
all:
		for dir in $(SUBDIRS); do	\
			$(MAKE) -C $$dir;		\
		done

.PHONY: x
x:
		for dir in $(SUBDIRS); do	\
			$(MAKE) -C $$dir x;		\
		done
