NAME := fillit

# project directories

SRC_DIR :=	./src/
OBJ_DIR :=	./obj/
INC_DIR :=	./inc/

# project source files

SRC =	main.c\
	read_file.c\
	validate_figures.c\
	list_functions.c\
	input.c\
	processing.c\
	output.c\

# project object files

OBJ =	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# libraries

LIBFT =         $(LIBFT_DIR)libft.a
LIBFT_DIR :=    $(LIB_DIR)libft/
LIBFT_INC :=    $(LIBFT_DIR)inc/
LIBFT_FLAGS :=  -lft -L $(LIBFT_DIR)


# compilation flags

CC_FLAGS :=	-Wall -Wextra -Werror


# linking flags

LINK_FLAGS :=   $(LIBFT_FLAGS)


# header flags

HEADER_FLAGS := -I $(INC_DIR)  -I $(LIBFT_INC)


# compiler

CC :=	gcc

# rules
	
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
