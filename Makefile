##
## EPITECH PROJECT, 2024
## Plazza
## File description:
## Makefile of the project
##

# Main file
MAIN		=	src/main.cpp
MAIN_OBJ	=	$(MAIN:.cpp=.o)

# Sources
SRC_FILES 	=	Parsing/Input.cpp	\
				Pizza.cpp			\

SRC_DIR 	=	src/
SRC		=	$(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_OBJ	=	$(SRC:.cpp=.o)

OBJ		= $(SRC_OBJ) $(MAIN_OBJ)

# Tests
TEST_FILES 	=	\

TEST_DIR 	=	tests/
TEST		=	$(addprefix $(TEST_DIR), $(TEST_FILES))
TEST_OBJ	=	$(TEST:.c=.o)
TEST_FLAGS	=	--coverage -lcriterion
TEST_GCDA 	=	$(SRC:.c=.gcda)
TEST_GCNO 	=	$(SRC:.c=.gcno)

# Binary
NAME 	=	plazza

# Flags
IFLAGS 	=	-I./include
CFLAGS 	=	-Wall -Wextra -Werror

# Compiler
CC = g++

# Colors
YELLOW 	=	/bin/echo -e "\x1b[33m $1\x1b[0m"
GREEN 	=	/bin/echo -e "\x1b[32m $1\x1b[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(IFLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")

clean:
	@rm -f $(OBJ)
	@$(call GREEN,"✅ [$@] done !")

fclean: clean
	@rm -f $(NAME)
	@$(call GREEN,"✅ [$@] done !")

re: fclean all

src_obj: $(SRC_OBJ)

tests_run: fclean $(TEST_OBJ)
	@$(MAKE) src_obj CFLAGS+=--coverage
	@$(CC) -o unit_tests $(TEST_OBJ) $(SRC_OBJ) $(TEST_FLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")
	./unit_tests
	gcovr --exclude tests/

tests_clean: clean
	@rm -f $(TEST_OBJ)
	@rm -f unit_tests
	@rm -f $(TEST_GCDA)
	@rm -f $(TEST_GCNO)
	@$(call GREEN,"✅ [$@] done !")

%.o: %.cpp
	@$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS) && \
	$(call YELLOW,"🆗 $<") || \
	$(call YELLOW,"❌ $<")
