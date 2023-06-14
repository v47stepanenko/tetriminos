#ifndef LIBFT_H
#define LIBFT_H

#define BUFF_SIZE 32

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>


typedef struct s_list
{
	void * content;
	size_t content_size;
	struct s_list * next;
}		t_list;

typedef struct node 
{
  int fdnum;
  char * line;
  struct node * next;
} Node;

typedef struct
{
  Node * head;
} Stack;



int ft_isalpha(int ch);
int ft_isdigit(int ch);
int ft_isalnum(int ch);
int ft_isascii(int ch);
int ft_isprint(int ch);
int ft_toupper(int ch);
int ft_tolower(int ch);
size_t ft_strlen(char const *str);
char *ft_strdup(char *src);
char *ft_strndup(char *src, size_t len);
int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strcat(char *dst, const char *src);
char *ft_strncat(char *dst, const char *src, size_t len);
char *ft_strcpy(char *dst, const char *src);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
char *ft_strncpy(char *dst, const char *src, size_t len);
void ft_putchar(char c);
void ft_putstr(char const *str);
void ft_putendl(char const *str);
void ft_putnbr(int n);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char const *s, int fd);
void ft_putendl_fd(char const *s, int fd);
void ft_putnbr_fd(int n, int fd);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memccpy(void *dst, const void *src, int c, size_t n);
void *ft_memmove(void *dst, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memalloc(size_t n);
void ft_memdel(void **s);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strstr(const char *s1, const char *s2);
char *ft_strnstr(const char*s1, const char *s2, size_t n);
void ft_striter(char *s, void (*f)(char *));
void ft_striteri(char *s, void (*f)(unsigned int, char *));
char *ft_strmap(char const *s, char (*f)(char));
char *ft_strmapi(char const *s, char(*f)(unsigned int, char));
int ft_atoi(const char *str);
char *ft_itoa(int n);
int ft_strequ(char const *s1, char const *s2);
int ft_strnequ(char const *s1, char const *s2, size_t n);
char *ft_strnew(size_t n);
char **ft_strsplit(char const *s, char c);
void ft_strdel(char **as);
void ft_strclr(char *s);
char *ft_strtrim(char const *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strsub(char const *s, unsigned int start, size_t len);
t_list *ft_lstnew(void const *content, size_t content_size);
void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void ft_lstadd(t_list **alst, t_list *newnode);
t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int get_next_line(const int fd, char **line);
char *ft_strncat_m(char *dst, const char *src, size_t len);

#endif