.PHONY: all clean fclean re

NAME := cast.out

CL_DIR := class/
SRCS_DIR := src/
OBJS_DIR := .build/

SERIAL_DIR := $(addprefix $(CL_DIR), serializer/)
SERIAL_CL := Serializer.cpp

P_SERIAL := $(addprefix $(SERIAL_DIR), $(SERIAL_CL))

P_MAIN := $(addprefix $(SRCS_DIR), main.cpp)

SRCS := $(P_SERIAL) $(P_MAIN)
INCS := $(SERIAL_DIR)
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.o))
DEPS := $(addprefix $(OBJS_DIR), $(OBJS:.o=.d))

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := $(addprefix -I,$(INCS)) -MMD -MP
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJS_DIR)

fclean:
	rm -rf $(OBJS_DIR)
	rm -f $(NAME)

re: fclean
	$(MAKE) all