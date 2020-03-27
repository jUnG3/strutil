BIN=./bin
SRC=./src
TEST_SRC=./test
L_LIB=./lib
LIBNAME=libstrutil
LIBSUFIX :=
LIBPATH :=

INSTALL_TARGET :=
TARGET_TEST_RUNNER=$(BIN)/test_runner
OSFLAG :=
ifeq ($(OS),Windows_NT)
	OSFLAG += -D WIN32
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		OSFLAG += -D AMD64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		OSFLAG += -D IA32
	endif
else
	UNAME_S := $(shell uname -s)
	LIBPATH=/usr/local/lib
	INSTALL_HEADER=/usr/local/include/strutil.h
	ifeq ($(UNAME_S),Linux)
		OSFLAG += -D LINUX
		LIBSUFIX = so
	endif
	ifeq ($(UNAME_S),Darwin)
		OSFLAG += -D OSX
		LIBSUFIX = dylib
	endif
		UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		OSFLAG += -D AMD64
	endif
		ifneq ($(filter %86,$(UNAME_P)),)
	OSFLAG += -D IA32
		endif
	ifneq ($(filter arm%,$(UNAME_P)),)
		OSFLAG += -D ARM
	endif
endif

TARGET=$(L_LIB)/$(LIBNAME).$(LIBSUFIX)
INSTALL_TARGET=$(LIBPATH)/$(LIBNAME).$(LIBSUFIX)

INC=\
 -I ./include

CC=cc

CFLAGS=\
 -c\
 -fPIC\
 -Wall\
 $(OSFLAG)\
 $(INC)\
 -o

LD=cc

LDFLAGS=\
 -Wall\
 -shared\
 -o

# header
#########
strutil_h=./include/strutil.h

# sources
# #######
strexplode_c=$(SRC)/strexplode.c
trim_c=$(SRC)/trim.c
explode_free_c=$(SRC)/explode_free.c

# test sources
# #######
test_runner_c=$(TEST_SRC)/test_runner.c

# objects
# #######
strexplode_o=$(BIN)/strexplode.o
trim_o=$(BIN)/trim.o
explode_free_o=$(BIN)/explode_free.o

OBJ=\
 $(strexplode_o)\
 $(trim_o)\
 $(explode_free_o)

# action
# ######
all: $(TARGET)
	$(CC) $(LDFLAGS) $(TARGET) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -f $(TARGET)
	rm -f $(TARGET_TEST_RUNNER)

new: clean all

install: $(TARGET)
	cp $(strutil_h) $(INSTALL_HEADER)
	chmod 0644 $(INSTALL_HEADER)
	cp $(TARGET) $(INSTALL_TARGET)
	chmod 0755 $(INSTALL_TARGET)

uninstall: $(TARGET)
	rm -f $(INSTALL_HEADER)
	rm -f $(INSTALL_TARGET)

test: new $(TARGET_TEST_RUNNER)
	$(TARGET_TEST_RUNNER)

$(TARGET): $(OBJ)

$(strexplode_o): $(strexplode_c)
	$(CC) $(CFLAGS) $@ $(strexplode_c)

$(trim_o): $(trim_c)
	$(CC) $(CFLAGS) $@ $(trim_c)

$(explode_free_o): $(explode_free_c)
	$(CC) $(CFLAGS) $@ $(explode_free_c)

$(TARGET_TEST_RUNNER): $(test_runner_c) $(OBJ)
	$(CC) $(INC) -o $@ $(test_runner_c) $(OBJ) -lcunit
