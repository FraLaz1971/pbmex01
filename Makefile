# testsimplepbm Makefile
CC = gcc
OEXT = .o
EEXT = 
RM = rm -f
TARGET1 = testpbm
CPPFLAGS = -g -O 
CFLAGS = -g -O
LDFLAGS = 
LIBS = 
SRC1 = $(TARGET1).c simplepbm.c
OBJ1 = $(TARGET1)$(OEXT) simplepbm$(OEXT)

all:    $(TARGET1)$(EEXT)

$(TARGET1)$(OEXT): $(TARGET1).c simplepbm.h
	$(CC) $(CPPFLAGS)  -c $(TARGET1).c

	
simplepbm$(OEXT): simplepbm.c simplepbm.h
	$(CC) $(CPPFLAGS) -c simplepbm.c

$(TARGET1)$(EEXT): $(TARGET1)$(OEXT) simplepbm$(OEXT)
	$(CC) $(CFLAGS) $(TARGET1)$(OEXT) simplepbm$(OEXT) -o $(TARGET1)$(EEXT) $(LDFLAGS) $(LIBS)


.PHONY: clean all

clean:
	$(RM) $(OBJ1) $(TARGET1) out.pbm
