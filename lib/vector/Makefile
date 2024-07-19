
NAME = libvector.a

SRC_DIR := .

SRCS = \
	vec.c\
	mat.c\
	\
	addm.c\
	addv.c\
	\
	divmf.c\
	divvf.c\
	\
	subm.c\
	subv.c\
	\
	mulmf.c\
	mulvf.c\
	mulvv.c\
	mulmm.c\
	mulmv.c\
	\
	fmavf.c\
	fmamf.c\
	fmavv.c\
	fmamm.c\
	\
	eqv.c\
	eqm.c\
	\
	len.c\
	lensqr.c\
	linearcomb.c\
	normv.c\
	transpose.c\
	cross.c\
	dotv.c\
	ident.c\
	\
	printm.c\
	printv.c\
	toeachv.c\
	toeachm.c\

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
