NAME = form

CC = c++

INCLUDES_DIR = includes

CFLAGS = -Wall -Werror -Wextra -g -std=c++98 -I./$(INCLUDES_DIR)

SRCS_DIR = srcs

SRCS =	$(SRCS_DIR)/main.cpp \
	$(SRCS_DIR)/AForm.cpp \
	$(SRCS_DIR)/Bureaucrat.cpp \
	$(SRCS_DIR)/PresidentialPardonForm.cpp \
	$(SRCS_DIR)/RobotomyRequestForm.cpp \
	$(SRCS_DIR)/ShrubberyCreationForm.cpp \
	$(SRCS_DIR)/Intern.cpp

OBJ_DIR = obj

OBJS = $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re