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
SRC_FILES 	=	APizza.cpp 					\
        		Parsing/PlazzaParser.cpp	\
				Parsing/Input.cpp			\
				SocketUnix/Server.cpp		\
				SocketUnix/Client.cpp		\
				Reception/Reception.cpp		\
				Utils/MessageQueue.cpp 		\
				Utils/Mutex.cpp 			\
				Utils/Semaphore.cpp 		\
				Utils/Stack.cpp 			\
				Utils/Timer.cpp 			\
				Utils/Thread.cpp 			\
				Kitchen.cpp					\


SRC_DIR 	=	src/
SRC		=	$(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_OBJ	=	$(SRC:.cpp=.o)

OBJ		= $(SRC_OBJ) $(MAIN_OBJ)

# Tests
TEST_FILES 	=	TestStack.cpp

TEST_DIR 	=	tests/
TEST		=	$(addprefix $(TEST_DIR), $(TEST_FILES))
TEST_OBJ	=	$(TEST:.cpp=.o)
TEST_FLAGS	=	--coverage -lcriterion -I./include
TEST_GCDA 	=	$(SRC:.cpp=.gcda)
TEST_GCNO 	=	$(SRC:.cpp=.gcno)

# Binary
NAME 	=	plazza

# Flags
IFLAGS 	=	-I./include
CFLAGS 	=	-Wall -Wextra -Werror -g

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
