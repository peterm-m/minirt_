
NAME = libvector.a

SRC_DIR := .

SRCS = \
	addm.c\
	ident.c\
	addv.c\
	cross.c\
	divmf.c\
	divv2.c\
	dotv.c\
	eqv.c\
	len.c\
	lensqr.c\
	linearcomb.c\
	mat.c\
	mulmf.c\
	mulmm.c\
	mulmv.c\
	mulv.c\
	mulvf.c\
	normv.c\
	printm.c\
	printv.c\
	subm.c\
	subv.c\
	vec.c\
	transpose.c\

SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR   := .build

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

CC = gcc
DIR_DUP = mkdir -p $(@D)
CLEANER = rm -rf

AR := ar
ARFLAGS  := -r -c -s

CCFLAGS = -Wall -Werror -Wextra -Ofast -march=native


all: $(NAME)

$(NAME): $(LIBLIB) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CCFLAGS) -c $< -o $@
	$(info CREATED $@)

clean:
	$(CLEANER) $(BUILD_DIR)

fclean: clean 
	$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
