NAME = gc.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj

SRC =	gc.c \
		gc_utils.c \
		gc_calloc.c \
		gc_itoa.c \
		gc_split.c \
		gc_strdup.c \
		gc_strjoin.c \
		gc_substr.c 

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

RM = rm -f

vpath %.c	gc_lib

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "✅ Garbage Collector library built"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "📄 Compiled $<"

clean:
	@$(RM) $(OBJ)
	@$(RM) -r $(OBJ_DIR)
	@echo "🧹 GC objects cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "🧹 GC library removed"

re: fclean all