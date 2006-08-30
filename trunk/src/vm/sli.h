#ifndef __SLI_H__
#define __SLI_H__
/**
 * Standard Library Interface
 *
 * Py requires a few functions from a few different
 * standard C libraries (memory, string, etc).
 * If your microcontroller has these libraries,
 * set the constant to 1 for each library available.
 * This will cause a macro to be defined which wraps
 * the function for use by Py.
 * Otherwise, leave the constant as 0, and Py will
 * use the function defined in sli.c
 * Some of the functions in sli.c will need to be ported
 * to the target system.
 *
 * @author      Dean Hall
 * @copyright   Copyright 2002 Dean Hall.  All rights reserved.
 * @file        sli.h
 *
 * Log:
 *
 * 2002/05/16   First.
 */

/***************************************************************
 * Includes
 **************************************************************/

/***************************************************************
 * Constants
 **************************************************************/

/** 
 * If the compiler has string.h, set HAVE_STRING to 1;
 * otherwise, leave it 0 and the sli functions will be used.
 */
#define HAVE_STRING_H   0


/***************************************************************
 * Macros
 **************************************************************/

/***************************************************************
 * Types
 **************************************************************/

/** usually an int, but larger for 8-bit micros */
#if 1
#include <stddef.h>
#else
typedef S16 size_t;
#endif


/***************************************************************
 * Globals
 **************************************************************/

/***************************************************************
 * Prototypes
 **************************************************************/

/*
 * This section creates a macro or a function prototype
 * for each library based on the corresponding constant.
 * For example, if HAVE_STRING is defined to non-zero,
 * the system <string.h> file will be included,
 * and a macro "sli_strcmp" will be created to wrap the strcmp()
 * function.  But if HAVE_STRING is zero, the sli_strcmp()
 * prototype will be declared and sli_strcmp() must be
 * implemented in sli.c
 */

/* XXX not just string.h, but stdio.h */
#if HAVE_STRING_H
#include <string.h>
#define sli_memcmp(p, q, n)     memcmp((p), (q), (n))
#define sli_memcpy(to, from, n) memcpy((to), (from), (n))
#define sli_memset(dest, from, n) memcpy((dest), (from), (n))
#define sli_strcmp(s1, s2)      strcmp((s1),(s2))
#define sli_strcpy(s1, s2)      strcpy((s1),(s2))
#define sli_strlen(s)           strlen(s)

#else

/**
 * Copy a block of memory in RAM.
 *
 * @param   to the destination address.
 * @param   from the source address.
 * @param   n the number of bytes to copy.
 * @return  The initial value of "to" (XXX what else?).
 * @see     mem_copy
 */
void   *sli_memcpy(void *, const void *, size_t);

/**
 * Copy a value repeatedly into a block of memory
 *
 * @param   dest the destination address.
 * @param   val the value.
 * @param   n the number of bytes to copy.
 * @return  Nothing
 * @see     memset
 */
void sli_memset(void *dest, const char val, size_t n);

/**
 * Compare strings.
 *
 * @param   s1 ptr to string 1.
 * @param   s2 ptr to string 2.
 * @return  value that is less then, equal to or greater than 0
 *          depending on whether s1's encoding is
 *          less than, equal to, or greater than s2's.
 */
int     sli_strcmp(const char *, const char *);

/**
 * Obtain string length.
 *
 * @param   s ptr to string.
 * @return  number of bytes in string.
 */
size_t  sli_strlen(char const *s);

/**
 * Compare strings for a specific length.
 *
 * @param   s1 ptr to string 1.
 * @param   s2 ptr to string 2.
 * @param   n number of chars to compare
 * @return  value that is less then, equal to or greater than 0
 *          depending on whether s1's encoding is
 *          less than, equal to, or greater than s2's.
 */
int     sli_strncmp(const char *s1, const char *s2, S16 n);

/*
int     sli_memcmp(const void *, const void *, size_t);
char    sli_strcpy(char *, const char *);
*/

#endif /* HAVE_STRING_H */

#endif /* __SLI_H__ */
