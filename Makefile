TARGET := vereadores
LIBS := -lm
CFLAGS = -Wall -g -std=c++11
OBJDIR := obj/
SRCDIR := src/
INCLUDEDIR := include/
INCLUDE_PATHS := -Iinclude
CLI := client/main.cpp
CPP := g++

all: $(TARGET)

SRC = $(wildcard $(SRCDIR)*.cpp)
HEADERS = $(wildcard $(INCLUDEDIR)*.h)

CLIENT = $(OBJDIR)$(basename $(notdir $(CLI)))

OBJECTS := $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
OBJECTS += $(CLIENT).o

$(OBJDIR)%.o: $(SRCDIR)%.pp $(HEADERS)
	@ mkdir -p $(OBJDIR)
	$(CPP) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<

$(CLIENT).o: $(CLI)
	$(CPP) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<
  
$(TARGET): $(OBJECTS)
	$(CPP) $(INCLUDE_PATHS) $(OBJECTS) $(LIBS) $(CFLAGS) -o $@

run: $(TARGET)
	@./$(TARGET) candidatos.csv partidos.csv 15/11/2020

clean:
	-rm -f *.csv
	-rm -f $(OBJDIR)*.o
	-rm -f $(TARGET)