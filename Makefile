.SILENT:
.PHONY: obj libmx

VERSION=${RED}p${ORANGE}a${YELLOW}t${LGREEN}h${CYAN}f${LBLUE}i${LPURPLE}n${PURPLE}d${LRED}e${ORANGE}r\
${YELLOW}v${LGREEN}0${CYAN}.${LBLUE}1 ${LPURPLE}r${PURPLE}e${LRED}a${ORANGE}d${YELLOW}y${NC}

COMP:=clang

ARGS:=#-std=c11 -Wall -Wextra -Werror -Wpedantic

INCLUDE:=inc

LIBNAME:=libmx.a
LIBDIR:=libmx
LIBINCLUDE:=$(LIBDIR)/$(INCLUDE)


CLEAN=\r                                                                              \r

RED=\033[0;31m
GREEN=\033[0;32m
ORANGE=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
# L - "light"
LGREY=\033[0;37m
LRED=\033[1;31m
LGREEN=\033[1;32m
YELLOW=\033[1;33m
LBLUE=\033[1;34m
LPURPLE=\033[1;35m
LCYAN=\033[1;36m
WHITE=\033[1;37m
# NC - no color
NC=\033[0m

all: libmx reinstall
	printf "$(VERSION)\n"

libmx:
	if [ -f $(LIBDIR)/$(LIBNAME) ] ; then \
	printf "" ; \
	else \
		make -sC $(LIBDIR) ; \
	fi

reinstall_libmx:
	make reinstall -sC $(LIBDIR)

obj:
	rm -rf obj
	mkdir obj
	$(COMP) $(ARGS) -c src/*.c -I$(INCLUDE) -I$(LIBINCLUDE)
	mv *.o obj/

reinstall: uninstall install

install: obj
	$(COMP) $(ARGS) obj/*.o -L$(LIBDIR) -lmx -o pathfinder -I$(INCLUDE) -I$(LIBINCLUDE)

uninstall:
	rm -f pathfinder
	rm -rf obj

clean:
	rm -rf obj
	make clean -sC $(LIBDIR)
