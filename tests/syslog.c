/*
 * Copyright (c) 2016-2018 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "tests.h"
#include <asm/unistd.h>

#ifdef __NR_syslog

# include <stdio.h>
# include <unistd.h>

# define SYSLOG_ACTION_READ 2
# define SYSLOG_ACTION_CLEAR 5

int
main(void)
{
	const long addr = (long) 0xfacefeeddeadbeefULL;

	int rc = syscall(__NR_syslog, SYSLOG_ACTION_READ, addr, -1);
	printf("syslog(SYSLOG_ACTION_READ, %#lx, -1) = %d %s (%m)\n",
	       addr, rc, errno2name());

	rc = syscall(__NR_syslog, SYSLOG_ACTION_CLEAR, addr, 0);
	printf("syslog(SYSLOG_ACTION_CLEAR, %#lx, 0) = %d %s (%m)\n",
		addr, rc, errno2name());

	puts("+++ exited with 0 +++");
	return 0;
}

#else

SKIP_MAIN_UNDEFINED("__NR_syslog")

#endif
