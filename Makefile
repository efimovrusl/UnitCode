.SILENT:


VERSION=${RED}F${ORANGE}U${YELLOW}C${LGREEN}K${CYAN}Y${LBLUE}O${LPURPLE}U \
${PURPLE}v${LRED}0${ORANGE}.${YELLOW}1 ${LGREEN}i${CYAN}s \
${LBLUE}r${LPURPLE}e${PURPLE}a${LRED}d${ORANGE}y${NC}

COMP:=clang

ARGS:=-std=c11 -Wall -Wextra -Werror -Wpedantic

LIBNAME:=libmx.a

INCLUDE:=inc

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

all: reinstall
	printf "${VERSION}\n"

install: obj
	ar -rc $(LIBNAME) obj/*.o
	printf "${CLEAN}Library is ${GREEN}installed${NC}\n"

uninstall: clean
	rm -f $(LIBNAME)
	printf "Library is ${LPURPLE}uninstalled${NC}"
	
reinstall: uninstall install


obj:
	rm -rf obj
	mkdir obj
	$(COMP) $(ARGS) -c src/*.c -I$(INCLUDE)
	mv *.o obj/

clean:
	rm -rf obj

test: reinstall
	printf "${VERSION}\n"
	$(COMP) ${ARGS} -fsanitize=address -fno-omit-frame-pointer main.c libmx.a -o test -I$(INCLUDE)
	echo ">-------< ${LCYAN}TEST${NC} >-------<" 
	./test
	rm test
	

compile: reinstall
	printf "${VERSION}\n"
	$(COMP) $(ARGS) main.c libmx.a -o test -I$(INCLUDE)
	echo "${LCYAN}test${NC} is compiled"
