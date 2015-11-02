/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:42:54 by harar             #+#    #+#             */
/*   Updated: 2015/03/23 15:52:40 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ;---------------------------------------------------------------------------------------------
** ;	64		|	32		|	16		|	[8		     8]		|  Definitions					 |
** ;----------------------------------------------------------------------------------------------
** ;	%rax	|	%eax	|	%ax		|	%ah			%al		|	Return 1					 |
** ;----------------------------------------------------------------------------------------------
** ;	%rbx	|	%ebx	|	%bx		|	%bh			%bl		|	(Callee saved)				 |
** ;----------------------------------------------------------------------------------------------
** ;	%rcx	|	%ecx	|	%cx		|	%ch			%cl		|	Arg 4 + Counter				 |
** ;----------------------------------------------------------------------------------------------
** ;	%rdx	|	%edx	|	%dx		|	%dh			%dl		|	Arg 3 + Return 2			 |
** ;----------------------------------------------------------------------------------------------
** ;	%rsi	|	%esi	|	%si		|	%sih		%sil	|	Arg 2						 |
** ;----------------------------------------------------------------------------------------------
** ;	%rdi	|	%edi	|	%di		|	%dih		%dil	|	Arg 1						 |
** ;----------------------------------------------------------------------------------------------
** ;	%rbp	|	%ebp	|	%bp		|	%bph		%bpl	|	(Callee saved)				 |
** ;----------------------------------------------------------------------------------------------
** ;	%rsp	|	%esp	|	%sp		|	%sph		%spl	|	Stack pointer (Callee saved) |
** ;----------------------------------------------------------------------------------------------
** ;	%r8		|	%r8d	|	%r8w|	|		  %r8b			|	Arg 5						 |
** ;----------------------------------------------------------------------------------------------
** ;	%r9		|	%r9d	|	%r9w	|		  %r9b			|	Arg 6						 |
** ;----------------------------------------------------------------------------------------------
** ;	%r10	|	%r10d	|	%r10w	|		  %r10b			|	Arg 7						 |
** ;----------------------------------------------------------------------------------------------
** ;	%r11	|	%r11d	|	%r11w	|		  %r11b			|	Tmp							 |
** ;----------------------------------------------------------------------------------------------
** ;	%r12	|	%r12d	|	%r12w	|		  %r12b			|	(Callee saved)				 |
** ;----------------------------------------------------------------------------------------------
** ;	%r13	|	%r13d	|	%r13w	|		  %r13b			|	(Callee saved)				 |
** ;----------------------------------------------------------------------------------------------
** ;	%r14	|	%r14d	|	%r14w	|		  %r14b			|	(Callee saved)				 |
** ;----------------------------------------------------------------------------------------------
** ;	%r15	|	%r15d	|	%r15w	|		  %r15b			|	(Callee saved)				 |
** ;----------------------------------------------------------------------------------------------
**
**		syscall
**
**  0x2000001	exit
**  0x2000002	open
**  0x2000003	read
**  0x2000004	write
**  0x2000005	close
*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>
#include "libfts.h"




# define C_BOLD		"\033[1m"
# define C_NONE		"\033[0m"
# define C_CYAN		"\033[36m"
# define C_RED		"\033[31m"
# define C_UNDER	"\033[4m"



# define MIN(a, b)	((a < b) ? a : b)
# define MAX(a, b)	((a > b) ? a : b)
# define ABS(a)		(abs(a))
# define CHECK(a, b) ((a == b) ? C_CYAN"Good"C_NONE : C_RED"Fail"C_NONE)




#ifdef	USE_FT_MIN
void	ft_test_min(void)
{
	int t1[10] = {INT_MIN, INT_MIN, INT_MIN, -19, -4, 0, 21, 34, INT_MAX, INT_MAX};
	int t2[10] = {INT_MAX, INT_MIN, 0, -19, 4, 3, 21, INT_MIN, INT_MAX, -1};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test MIN"C_NONE"\n");
	for (i = 0; i < 10; i++)
		printf("[%s]  ->  Test:  %d / %d\n",
			   CHECK(ft_min(t1[i], t2[i]), MIN(t1[i], t2[i])), t1[i], t2[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_MAX
void	ft_test_max(void)
{
	int t1[10] = {INT_MIN, INT_MIN, INT_MIN, -19, -4, 0, 21, 34, INT_MAX, INT_MAX};
	int t2[10] = {INT_MAX, INT_MIN, 0, -19, 4, 3, 21, INT_MIN, INT_MAX, -1};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test MAX"C_NONE"\n");
	for (i = 0; i < 10; i++)
		printf("[%s]  ->  Test:  %d / %d\n",
			   CHECK(ft_max(t1[i], t2[i]), MAX(t1[i], t2[i])), t1[i], t2[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_ABS
void	ft_test_abs(void)
{
	int t[5] = {INT_MIN, -999999, 0, 6, INT_MAX};
	int	i;

	printf("\t\t"C_BOLD""C_UNDER"Test ABS"C_NONE"\n");
	for (i = 0; i < 5; i++)
		printf("[%s]  ->  Test:  %d\n", CHECK(ft_abs(t[i]), ABS(t[i])), t[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_ISUPPER
void	ft_test_isupper(void)
{
	char t[8] = {'.', 'D', 'A', 'Z', 'a', 'z', '@', '['};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test ISUPPER"C_NONE"\n");
	for (i = 0; i < 8; i++)
		printf("[%s]  ->  Test: %c\n", CHECK(ft_isupper(t[i]),
											 (t[i] >= 'A' && t[i] <= 'Z')), t[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_ISLOWER
void	ft_test_islower(void)
{
	char t[8] = {'.', 'D', 'A', 'Z', 'a', 'z', '`', '{'};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test ISLOWER"C_NONE"\n");
	for (i = 0; i < 8; i++)
		printf("[%s]  ->  Test: %c\n", CHECK(ft_islower(t[i]),
											 (t[i] >= 'a' && t[i] <= 'z')), t[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_ISALPHA
void	ft_test_isalpha(void)
{
	char t[8] = {'k', 'D', 'A', 'Z', 'a', 'z', '`', '{'};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test ISALPHA"C_NONE"\n");
	for (i = 0; i < 8; i++)
		printf("[%s]  ->  Test: %c\n", CHECK(ft_isalpha(t[i]),
			 (t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z')), t[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_BZERO
void	ft_test_bzero(void)
{
	char s1[1000];
	char s2[1000];
	int	i;

	for (i = 0; i < 1000; i++)
		s1[i] = s2[i] = rand() * 26 + 65;
	bzero(s2, 1000);
	ft_bzero(s1, 1000);
	printf("\t\t"C_BOLD""C_UNDER"Test BZERO"C_NONE"\n");
	for (i = 0; i < 1000; i++)
		if (s1[i] != s2[i])
			break ;
	if (i != 1000)
		printf("[%s] Test 1  ->  index: %d/%d\n", C_RED"FAIL"C_NONE, i, 1000);
	else
		printf("[%s] Test 1  ->  Everything is OK!\n", C_CYAN"Good"C_NONE);
	for (i = 0; i < 1000; i++)
		s1[i] = s2[i] = rand() * 26 + 65;
	bzero((void *)s2, 1000);
	ft_bzero((void *)s1, 1000);
	for (i = 0; i < 1000; i++)
		if (s1[i] != s2[i])
			break ;
	if (i != 1000)
		printf("[%s] Test 2  ->  index: %d/%d\n\n", C_RED"FAIL"C_NONE, i, 1000);
	else
		printf("[%s] Test 2  ->  Everything is OK!\n\n", C_CYAN"Good"C_NONE);

}
#endif


#ifdef	USE_FT_ISDIGIT
void	ft_test_isdigit(void)
{
	char t[10] = {'\0', '/', '0', ':', '9', '5', 'A', 'z', '&', '-'};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test ISDIGIT"C_NONE"\n");
	for (i = 0; i < 10; i++)
		printf("[%s]  ->  Test: [%c]\n", CHECK(ft_isdigit(t[i]),
								 (t[i] >= '0' && t[i] <= '9')), t[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_ISALNUM
void	ft_test_isalnum(void)
{
	char t[14] = {'A', 'H', 'Z', 'a', 'g', 'z', '0', '9', '5', '+', ' ', '&', ':', '`'};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test ISALNUM"C_NONE"\n");
	for (i = 0; i < 14; i++)
		printf("[%s]  ->  Test: [%c]\n", CHECK(ft_isalnum(t[i]),
				(t[i] >= 'A' && t[i] <= 'Z') ||
				(t[i] >= 'a' && t[i] <= 'z') ||
				(t[i] >= '0' && t[i] <= '9')), t[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_ISASCII
void	ft_test_isascii(void)
{
	int t[10] = {21, 34, 69, 74, 129, -1, 98, 104, INT_MAX, INT_MIN};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test ISASCII"C_NONE"\n");
	for (i = 0; i < 10; i++)
		printf("[%s]  ->  Test: [%c]\n", CHECK(ft_isascii(t[i]),
							(t[i] >= 0 && t[i] <= 127)), (char)t[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_ISPRINT
void	ft_test_isprint(void)
{
	int t[10] = {31, 32, 75, INT_MIN, INT_MAX, 116, 126, 150, 0, -1};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test ISPRINT"C_NONE"\n");
	for (i = 0; i < 10; i++)
		printf("[%s]  ->  Test: [%c]\n", CHECK(ft_isprint(t[i]),
					   (t[i] >= ' ' && t[i] <= '~')), t[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_TOLOWER
void	ft_test_tolower(void)
{
	char s1[10] = {'0', 0, '1', 'A', 'a', 'G', 'b', 'z', 'Z', '#'};
	char s2[10] = {'0', 0, '1', 'a', 'a', 'g', 'b', 'z', 'z', '#'};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test TOLOWER"C_NONE"\n");
	for (i = 0; i < 10; i++)
		printf("[%s]  ->  Test: [%c]\n", CHECK(ft_tolower(s1[i]), s2[i]), s1[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_TOUPPER
void	ft_test_toupper(void)
{
	char s1[10] = {'0', 0, '1', 'A', 'a', 'G', 'b', 'z', 'Z', '#'};
	char s2[10] = {'0', 0, '1', 'A', 'A', 'G', 'B', 'Z', 'Z', '#'};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test TOUPPER"C_NONE"\n");
	for (i = 0; i < 10; i++)
		printf("[%s]  ->  Test: [%c]\n", CHECK(ft_toupper(s1[i]), s2[i]), s1[i]);
	printf("\n");
}
#endif


#ifdef	USE_FT_STRLEN
void	ft_test_strlen(void)
{
	char t[1000001];
	int	i;
	size_t a;
	size_t b;
	char *s;

	for (i = 0; i < 1000000; i++)
		t[i] = 'a' + (i % 26);
	t[i] = '\0';

	printf("\t\t"C_BOLD""C_UNDER"Test STRLEN"C_NONE"\n");
	a = ft_strlen(NULL);
	b = strlen("");
	printf("[%s]  ->  Test: [(null)] [0]\n", CHECK(a, b));
	s = strdup("\0");
	printf("[%s]  ->  Test: [%s] [%lu]\n", CHECK(ft_strlen(s), strlen(s)), s, ft_strlen(s));
	s = strdup("bonjour\0");
	printf("[%s]  ->  Test: [%s] [%lu]\n", CHECK(ft_strlen(s), strlen(s)), s, ft_strlen(s));
	s = strdup("En voici un beau main de test\0");
	printf("[%s]  ->  Test: [%s] [%lu]\n", CHECK(ft_strlen(s), strlen(s)), s, ft_strlen(s));
	printf("[%s]  ->  Test: -> Random chaine (1.000.000 caracteres) [%lu]\n",
												CHECK(ft_strlen(t), strlen(t)), ft_strlen(t));
	free(s);
	printf("\n");
}
#endif


#ifdef	USE_FT_STRCAT
void	ft_test_strcat(void)
{
	char *s1[] = {"\0", "\0", "test2", "Bro", "Dick", "Term"};
	char s2[6][7] = {"\0", "test1", "\0", "mance", "head", "inator"};
	char *s3;
	char *s4;
	int	i;

	printf("\t\t"C_BOLD""C_UNDER"Test STRCAT"C_NONE"\n");
	for (i = 0; i < 6 ; i++)
	{
		s3 = ft_strcat(strdup(s1[i]), s2[i]);
		s4 = strcat(strdup(s1[i]), s2[i]);
		printf("[%s]  ->  Test: [%s] -> [%s]\n",
			   CHECK(strcmp(s3, s4), 0), s4, s3);
	}
	printf("\n");
}
#endif


#ifdef	USE_FT_PUTS
void	ft_test_puts(void)
{
	char *s1[] = {NULL, "\0", "Salut", "les", "potes", "Meow"};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test PUTS"C_NONE"\n");
	for (i = 0; i < 6; i++)
	{
		write(1, "Chaine a ecrire: [", 18);
		if (i)
			write(1, s1[i], strlen(s1[i]));
		else
			write(1, "(null)", 6);
		write(1, "]  ->  [", 8);
		ft_puts(s1[i]);
		write(1, "] ", 2);
	}
	printf("\n");
}
#endif

/*
#ifdef	USE_FT_PUTSTR
void	ft_test_putstr(void)
{
	char *s1[] = {"\0", "Salut", "les", "potes", "Meow"};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test PUTSTR"C_NONE"\n");
	for (i = 0; i < 5; i++)
	{
		write(1, "Chaine a ecrire: [", 18);
		if (i)
			write(1, s1[i], strlen(s1[i]));
		write(1, "]  ->  [", 8);
		ft_putstr(s1[i]);
		if (!i)
			printf("]\n");
		else
			printf("]\n");
	}
	printf("\n");
}
#endif


#ifdef	USE_FT_PUTSTRFD
void	ft_test_putstrfd(void)
{
	char *s1[] = {"\0", "Salut", "les", "potes", "Meow"};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test PUTSTR_FD"C_NONE"\n");
	for (i = 0; i < 5; i++)
	{
		write(1, "Chaine a ecrire: [", 18);
		if (i)
			write(1, s1[i], strlen(s1[i]));
		write(1, "]  ->  [", 8);
		ft_putstr_fd(s1[i], i % 2 + 1);
		printf("]\n");
	}
	printf("\n");
}
#endif


#ifdef	USE_FT_PUTCHAR
void	ft_test_putchar(void)
{
	int	s[10] = {0, 64, 78, 35, 98, 117, 85, 58, ' ', 111};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test PUTCHAR"C_NONE"\n");
	for (i = 0; i < 10; i++)
	{
		write(1, "Caractere a ecrire: [", strlen("Caractere a ecrire: ["));
		if (i)
			write(1, &s[i], 1);
		write(1, "]  ->  [", 8);
		ft_putchar(s[i]);
		printf("]\n");
	}
	printf("\n");
}
#endif


#ifdef	USE_FT_PUTCHARFD
void	ft_test_putcharfd(void)
{
	int s[10] = {0, 64, 78, 35, 98, 117, 85, 58, ' ', 111};
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test PUTCHARFD"C_NONE"\n");
	for (i = 0; i < 10; i++)
	{
		write(1, "Caractere a ecrire: [", strlen("Caractere a ecrire: ["));
		if (i)
			write(1, &s[i], 1);
		write(1, "]  ->  [", 8);
		ft_putchar_fd(s[i], i % 2 + 1);
		printf("]\n");
	}
	printf("\n");
}
#endif
*/


#ifdef	USE_FT_MEMSET
void	ft_test_memset(void)
{
	char b1[100], b2[100];

	printf("\t\t"C_BOLD""C_UNDER"Test MEMSET"C_NONE"\n");
	ft_memset(b1, 42, 100);
	memset(b2, 42, 100);
	printf("[%s]  ->  Test: [100x '%c']\n", CHECK(memcmp(b1, b2, 0), 0), 42);
	printf("[%s]  ->  Test: [%s, '%s', %d]\n",
		   CHECK(memcmp(memset(strdup("abcd"), 'A', 5), ft_memset(strdup("abcd"), 'A', 5), 5), 0), "abcd", "A", 5);
	printf("[%s]  ->  Test: [%s, '%s', %d]\n",
		   CHECK(memcmp(memset(strdup("abcd"), 0, 0), ft_memset(strdup("abcd"), 0, 0), 5), 0), "abcd", "\\0", 0);
	printf("\n");
}
#endif



#ifdef	USE_FT_MEMCPY
void	ft_test_memcpy(void)
{
	char b1[100], b2[100];

	printf("\t\t"C_BOLD""C_UNDER"Test MEMCPY"C_NONE"\n");
	memset(b1, 33, 100);
	memset(b2, 63, 100);
	ft_memcpy(b1, b2, 100);
	printf("[%s]  ->  Test: [100x]\n", CHECK(memcmp(b1, b2, 100), 0));
	printf("[%s]  ->  Test: [Same chaine]\n", CHECK(memcmp(ft_memcpy(b1, b2, 0), b1, 100), 0));
	printf("\n");
}
#endif



#ifdef	USE_FT_STRDUP
void	ft_test_strdup(void)
{
	char *s[] = {"\0\0\0", "", "Salut", "Les", "Potes", "Et", "Les", "Aut\0res", "res", "."};
	char *s1;
	char *s2;
	int i;

	printf("\t\t"C_BOLD""C_UNDER"Test STRDUP"C_NONE"\n");
	for (i = 0; i < 10; i++)
	{
		s1 = ft_strdup(s[i]);
		s2 = strdup(s[i]);
		printf("[%s]  ->  Test: [%s] -> [%s] \n", CHECK(strcmp(s1, s2), 0), s2, s1);
		free(s1);
		free(s2);
	}
	printf("\n");
}
#endif

/*
#ifdef	USE_FT_STRCMP
void	ft_test_strcmp(void)
{
	char *s1[] = {"", "Yop", "", "Salut", "les", "potes", "et", "les", "aut\0res", "res"};
	char *s2[] = {"", "", "Yop", "Salut", "Les", "potes", "eet", "le\0s", "autres", "res"};
	int i;
	int n1;
	int	n2;

	printf("\t\t"C_BOLD""C_UNDER"Test STRCMP"C_NONE"\n");
	for (i = 0; i < 10; i++)
	{
		n1 = ft_strcmp(strdup(s1[i]), strdup(s2[i]));
		n1 = (n1 < 0) ? -1 : (n1 > 0);
		n2 = strcmp(strdup(s1[i]), strdup(s2[i]));
		n2 = (n2 < 0) ? -1 : (n2 > 0);
		printf("[%s]  ->  Test: [%s & %s] -> [ft: %d / Reel: %d]\n",
			   CHECK(n1, n2), s1[i], s2[i], n1, n2);
	}
	printf("\n");
}
#endif


#ifdef	USE_FT_STRNCMP
void	ft_test_strncmp(void)
{
	char *s1[] = {"", "Yop", "", "Salut", "les", "potes", "et", "les", "aut\0res", "res"};
	char *s2[] = {"", "", "Yop", "Salut", "Les", "potes", "teet", "le\0s", "autres", "res"};
	size_t t[] = {0, 1, 2, 5, 3, 1, 0, 6, 3, 1000};
	int i;
	int n1;
	int n2;

	printf("\t\t"C_BOLD""C_UNDER"Test STRNCMP"C_NONE"\n");
	for (i = 0; i < 10; i++)
	{
		n1 = ft_strncmp(strdup(s1[i]), strdup(s2[i]), t[i]);
		n1 = (n1 < 0) ? -1 : (n1 > 0);
		n2 = strncmp(strdup(s1[i]), strdup(s2[i]), t[i]);
			n2 = (n2 < 0) ? -1 : (n2 > 0);
		printf("[%s]  ->  Test: [%s & %s & [%lu] -> [ft: %d / Reel: %d]\n",
			   CHECK(n1, n2), s1[i], s2[i], t[i], n1, n2);
	}
	printf("\n");
}
#endif

*/

#ifdef	USE_FT_CAT
void	ft_test_ftcat(int fd)
{
	printf("\t\t"C_BOLD""C_UNDER"Test CAT"C_NONE"\n");
	ft_cat(fd);
	printf("\n");
}
#endif




int main(int argc, char **argv)
{
	int fd;
	srand(time(NULL));

#ifdef	USE_FT_MIN
	ft_test_min();
#endif
#ifdef	USE_FT_MAX
	ft_test_max();
#endif
#ifdef	USE_FT_ABS
	ft_test_abs();
#endif
#ifdef	USE_FT_ISUPPER
	ft_test_isupper();
#endif
#ifdef	USE_FT_ISLOWER
	ft_test_islower();
#endif
#ifdef	USE_FT_ISALPHA
	ft_test_isalpha();
#endif
#ifdef	USE_FT_BZERO
	ft_test_bzero();
#endif
#ifdef	USE_FT_ISDIGIT
	ft_test_isdigit();
#endif
#ifdef	USE_FT_ISALNUM
	ft_test_isalnum();
#endif
#ifdef	USE_FT_ISASCII
	ft_test_isascii();
#endif
#ifdef	USE_FT_ISPRINT
	ft_test_isprint();
#endif
#ifdef	USE_FT_TOLOWER
	ft_test_tolower();
#endif
#ifdef	USE_FT_TOUPPER
	ft_test_toupper();
#endif
#ifdef	USE_FT_STRLEN
	ft_test_strlen();
#endif
#ifdef	USE_FT_STRCAT
	ft_test_strcat();
#endif
#ifdef	USE_FT_PUTS
	ft_test_puts();
#endif
/*#ifdef	USE_FT_PUTSTR
	ft_test_putstr();
#endif
#ifdef	USE_FT_PUTSTRFD
	ft_test_putstrfd();
#endif
#ifdef	USE_FT_PUTCHAR
	ft_test_putchar();
#endif
#ifdef	USE_FT_PUTCHARFD
	ft_test_putcharfd();
#endif*/
#ifdef	USE_FT_MEMSET
	ft_test_memset();
#endif
#ifdef	USE_FT_MEMCPY
	ft_test_memcpy();
#endif
#ifdef	USE_FT_STRDUP
	ft_test_strdup();
#endif
/*#ifdef	USE_FT_STRCMP
	ft_test_strcmp();
#endif
#ifdef	USE_FT_STRNCMP
	ft_test_strncmp();
#endif
*/




#ifdef	USE_FT_CAT
	printf("USE FT_CAT ENABLED\n");
	if (!(fd = 0) && argc >= 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			printf("Le fichier ne peut etre ouvert, le file descriptor transmi est: [%d]\n", ++fd);
	}
	else
		printf("Aucun argument en parametre, file descriptor transmi: [%d]\n", fd);
	ft_test_ftcat(fd);
#endif

	(void)argc;
	(void)argv;
	(void)fd;
	return (0);
}
