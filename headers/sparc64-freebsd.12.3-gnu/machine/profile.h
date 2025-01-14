/*-
 * SPDX-License-Identifier: MIT-CMU
 *
 * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.
 * All rights reserved.
 *
 * Author: Chris G. Demetriou
 * 
 * Permission to use, copy, modify and distribute this software and
 * its documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 * 
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS" 
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND 
 * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 * 
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie the
 * rights to redistribute these changes.
 *
 *	from: NetBSD: profile.h,v 1.9 1997/04/06 08:47:37 cgd Exp
 *	from: FreeBSD: src/sys/alpha/include/profile.h,v 1.4 1999/12/29
 * $FreeBSD: releng/12.3/sys/sparc64/include/profile.h 326403 2017-11-30 15:48:35Z pfg $
 */

#ifndef _MACHINE_PROFILE_H_
#define	_MACHINE_PROFILE_H_

#if !defined(_KERNEL) && !defined(_SYS_CDEFS_H_)
#error this file needs sys/cdefs.h as a prerequisite
#endif

#define	FUNCTION_ALIGNMENT	32

typedef u_long	fptrdiff_t;

#ifdef _KERNEL

#include <machine/cpufunc.h>
#include <machine/intr_machdep.h>

#define	_MCOUNT_DECL	void mcount
#define	MCOUNT

#define	MCOUNT_DECL(s)	register_t s;
#define	MCOUNT_ENTER(s)	s = rdpr(pil); wrpr(pil, 0, PIL_TICK)
#define	MCOUNT_EXIT(s)	wrpr(pil, 0, s)

void bintr(void);
void btrap(void);
void eintr(void);
void user(void);

#define	MCOUNT_FROMPC_USER(pc)					\
	((pc < (uintfptr_t)VM_MAXUSER_ADDRESS) ? (uintfptr_t)user : pc)

#define	MCOUNT_FROMPC_INTR(pc)					\
	((pc >= (uintfptr_t)btrap && pc < (uintfptr_t)eintr) ?	\
	    ((pc >= (uintfptr_t)bintr) ? (uintfptr_t)bintr :	\
		(uintfptr_t)btrap) : ~0UL)

void	mcount(uintfptr_t frompc, uintfptr_t selfpc);

#else /* !_KERNEL */

typedef u_long	uintfptr_t;

#define	_MCOUNT_DECL	static __inline void __mcount

#ifdef __GNUCLIKE_ASM
#define	MCOUNT								\
void									\
_mcount()								\
{									\
	uintfptr_t frompc, selfpc;					\
									\
	/*								\
	 * Find the return address for mcount,				\
	 * and the return address for mcount's caller.			\
	 *								\
	 * selfpc = pc pushed by call to mcount				\
	 */								\
	__asm("add %%o7, 8, %0" : "=r" (selfpc));			\
	/*								\
	 * frompc = pc pushed by call to mcount's caller.		\
	 */								\
	__asm("add %%i7, 8, %0" : "=r" (frompc));			\
	__mcount(frompc, selfpc);					\
}
#else /* !__GNUCLIKE_ASM */
#define	MCOUNT
#endif /* __GNUCLIKE_ASM */

#endif /* _KERNEL */

#endif /* !_MACHINE_PROFILE_H_ */
