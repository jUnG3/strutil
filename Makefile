BIN=./bin
SRC=./src
TEST_SRC=./test
L_LIB=./lib
LIBNAME=libstrutil
TARGET=$(L_LIB)/$(LIBNAME).so
INSTALL_TARGET=/usr/lib/$(LIBNAME).so
TARGET_TEST_RUNNER=$(BIN)/test_runner
INSTALL_HEADER=/usr/include/strutil.h
INC=\
 -I ./include

CC=cc

CFLAGS=\
 -c\
 -fPIC\
 -Wall\
 $(INC)\
 -o

LD=cc

LDFLAGS=\
 -Wall\
 -shared\
 -Wl,-soname,$(LIBNAME).so\
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
	cp $(TARGET) $(INSTALL_TARGET)
	chmod 0755 $(INSTALL_TARGET)
	cp $(strutil_h) $(INSTALL_HEADER)
	chmod 0644 $(INSTALL_HEADER)

uninstall: $(TARGET)
	rm -f $(INSTALL_TARGET)
	rm -f $(INSTALL_HEADER)

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
