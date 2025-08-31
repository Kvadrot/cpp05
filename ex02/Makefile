C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp\
	  AForm.cpp\
	  ShrubberyCreationForm.cpp\
	  main.cpp\

OBJFILES = $(SRC:.cpp=.o)

NAME = form.out

all: $(NAME)

$(NAME):$(OBJFILES)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
