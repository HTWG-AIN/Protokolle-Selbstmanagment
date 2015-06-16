#
# Makefile
#


#Komando-Variablen
CC = gcc -g
CFLAGS = -W -Wall -ansi -pedantic
CPPFLAGS = -I.
RM = rm -f

# Musterregel fürs Übersetzen

TARGET = liste

%.o: %.c
	$(CC) $(CFALGS) $(CPPFLAGS) -c $< -o $@

.PHONY: all clean 

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o

