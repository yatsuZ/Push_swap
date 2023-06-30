/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:31:45 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/13 17:39:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

//////////////////////////////////// STRUCTURE

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/////////////////////////////////// LIBFT

size_t	ft_strlen(const char *cha);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(char cha);
int		ft_isalpha(char cha);
int		ft_isalnum(int cha);
int		ft_isascii(int cha);
int		ft_atoi(const char *nptr);
int		ft_isprint(char cha);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchar(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);

///////////////////////////////////////////////////// LIBFT-BONUS

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

///////////////////////////////////////////////////// PRINTF
/*
	@brief Reproduit la fonction printf.
*/
int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printptr(void *add);
int		ft_prnbr(long n, char *base, long len);
int		ft_prexa(unsigned int n, char *base, unsigned int len);
int		ft_prptr(unsigned long n, char *base, unsigned long len);

////////////////////////////////////////////////// GNL

char	*get_next_line(int fd);
char	*ft_strdup2(char *s, int option);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strlen_or_findendl(char *s, int option);
void	*ft_calloc2(int nmemb, int size);
char	*ft_memcpy2(char *dest, char *src, int n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
