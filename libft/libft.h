/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:09:35 by slucas-s          #+#    #+#             */
/*   Updated: 2021/04/19 13:24:16 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);

int		ft_isalpha(int c);
int		ft_isupperalpha(int c);
int		ft_toupper (int c);
int		ft_tolower (int c);

size_t	ft_strlen(const char *str);
int		ft_wordcount(const char *str, char c);
size_t	ft_strlcpy (char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat (char *dst, const char *src, size_t dstsize);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strend_cmp(char *name, char *extension);

char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdiffc(const char *str, const char *set);
char	*ft_strrdiffc(const char *str, const char *set);

char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_strmapi(char const	*str, char (*f)(unsigned int, char));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char	*str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putlong_fd(long nbr, int fd);
void	ft_puthex_fd(unsigned int nbr, int fd);
void	ft_putlonghex_fd(unsigned long nbr, int fd);
void	ft_putupperhex_fd(unsigned int nbr, int fd);

int		ft_digitcount(long n);
int		ft_hexlen(unsigned int n);
int		ft_hexlen_long(unsigned long num);

void	*ft_memset (void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);

void	*ft_calloc(size_t count, size_t size);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	**ft_split(const char *str, char c);

int		ft_chartable_linecount(char **table);
void	ft_free_chartable(char **table);

// ----------

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

void	ft_lstiter(t_list *lst, void (*funct)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*funct)(void *), void(*del)(void *));

#endif
