SRCS_DIR := './srcs'
HEADR_DIR := './includes'
HARDRD :=  $(HEADR_DIR)/ft.h
SRCS :=  $(SRCS)/ft_putchar.c $(SRCS)/ft_swap.c $(SRCS)/ft_putstr.c $(SRCS)/ft_strlen.c $(SRCS)/ft_strcmp.c
OBJS := $(SRCS:%.c=%.o)
TARGET := libft.a
CFLAGS = -Wall -Wextra -Werror 

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar -rsc $(TARGET) $(OBJS) 

%.o : %.c
	cc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)