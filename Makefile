############
# Exemplo de makefile
# Prof. João Paulo A. Almeida
# Programação III
# 
# A princípio, você não precisa alterar nada, mas aqui assume-se que o diretório atual
# é o diretório onde estão os códigos fonte (.cpp).
#

# nome do compilador
CLI := client/main.cpp
CPP = g++

# opções de compilação
CFLAGS = -Wall -g
CPPFLAGS = -std=c++11
SRCDIR := src/
INCLUDEDIR := include
OBJDIR := obj/
# define lista de arquivos-fonte, assumindo que estão no diretório atual
FONTES = $(wildcard $(SRCDIR)*.cpp) 
HEADERS = $(wildcard $(INCLUDEDIR)*.h)
# define lista dos arquivos-objeto usando nomes da lista de arquivos-fonte
OBJETOS = $(FONTES:.cpp=.o)

# nome do arquivo executável
EXECUTAVEL = vereadores

############ alvos
#
# use @ antes de todos os comandos, pois é necessário no script de teste
#

# alvo principal é o executável  
all: $(EXECUTAVEL)

# para linkar o executável, precisamos dos arquivos-objetos
$(EXECUTAVEL): $(OBJETOS)
	@$(CPP) -o $@ $^ 
CLIENT = $(OBJDIR)$(basename $(notdir $(CLI)))
 OBJECTS := $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
 OBJECTS += $(CLIENT).o

 $(OBJDIR)%.o: $(SRCDIR)%.pp $(HEADERS)
 	@ mkdir -p $(OBJDIR)
 	$(CPP) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<

$(CLIENT).o: $(CLI)
 	$(CPP) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<
  
# alvo para cada arquivo-objeto depende do código fonte
# (observação, aqui não estamos capturando as dependências de arquivos .h)
%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $(CFLAGS) $^

# o comando para executar deve especificar sempre como parâmetro divulga.csv	
run: $(EXECUTAVEL)
	@./$(EXECUTAVEL) candidatos.csv partidos.csv 15/11/2020

# comando para limpeza
clean: 
	@rm *.o vereadores *.csv *.txt
# TARGET := vereadores
# LIBS := -lm
# OBJDIR := obj/
# SRCDIR := src/
# INCLUDEDIR := include/
# INCLUDE_PATHS := -Iinclude
# CLI := client/main.cpp
# CPP := g++

# all: $(TARGET)

# SRC = $(wildcard $(SRCDIR)*.cpp)
# HEADERS = $(wildcard $(INCLUDEDIR)*.h)

# CLIENT = $(OBJDIR)$(basename $(notdir $(CLI)))

# OBJECTS := $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
# OBJECTS += $(CLIENT).o

# $(OBJDIR)%.o: $(SRCDIR)%.pp $(HEADERS)
# 	@ mkdir -p $(OBJDIR)
# 	$(CPP) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<

# $(CLIENT).o: $(CLI)
# 	$(CPP) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<
  

# $(TARGET): $(OBJECTS)
# 	$(CPP) $(INCLUDE_PATHS) $(OBJECTS) $(LIBS) -o $@

# clean:
# 	-rm -f -r obj
# 	-rm -f *.o
# 	-rm -f $(TARGET)

