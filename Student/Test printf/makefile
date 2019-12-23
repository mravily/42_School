NAME=		a.out

##
##		RESSOURCES
##

##List every folder where he will find header
INC_DIR = 	$(shell find includes -type d)
##List every folder where he will find source file
SRC_DIR = 	$(shell find srcs -type d)
##List every folder where he will find lib file
LIB_DIR = 	$(shell find ~/.brew/lib -type d)
##Folder where he will store the .o
OBJ_DIR	=	obj

##Add to the vpath the folder find in SRC_DIR
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

##Set the download program to brew
DWL =		brew

##List every .c found inside SRC_DIR
SRC = 		$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

##Transform and place every .o from SRC
OBJ=		$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

##List of libraries to download and install using the function defined in DWL
LIB_DWN =
##List of libraries to link while compiling
LIB =

##
##		COMPILER FLAGS
##

##Basics flags
CFLAGS=		-fsanitize=address -g -Wall -Werror -Wextra
##Create the flags to includes every .h needed by this program
IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir)) $(foreach dir, $(shell find ~/.brew/include -type d), -I$(dir))

##Create the flags to link every libraries needed by this program (-L and -l)
LFLAGS = 	$(foreach dir, $(LIB_DIR), -L $(dir) ) $(foreach lib, $(LIB), -l$(lib)) -framework OpenGL

##Define the compiler to use
CC=			gcc

all:
				make $(NAME)

$(NAME):		$(OBJ)
				@echo "Compiling $(NAME) ...\c"
				@$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)
				@echo " DONE"

$(OBJ_DIR)/%.o : %.c
				@mkdir $(OBJ_DIR) 2> /dev/null || true
				@echo "Compiling $< ...\c"
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo " DONE"

clean:
				@rm -rf $(OBJ_DIR)
				@echo "clean"

fclean:			clean
				@rm -f $(NAME)
				@echo "fclean"

re:				fclean all

.PHONY: all clean fclean re
