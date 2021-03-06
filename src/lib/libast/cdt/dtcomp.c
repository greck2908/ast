/***********************************************************************
 *                                                                      *
 *               This software is part of the ast package               *
 *          Copyright (c) 1985-2012 AT&T Intellectual Property          *
 *                      and is licensed under the                       *
 *                 Eclipse Public License, Version 1.0                  *
 *                    by AT&T Intellectual Property                     *
 *                                                                      *
 *                A copy of the License is available at                 *
 *          http://www.eclipse.org/org/documents/epl-v10.html           *
 *         (with md5 checksum b35adb5213ca9657e911e9befb180842)         *
 *                                                                      *
 *              Information and Software Systems Research               *
 *                            AT&T Research                             *
 *                           Florham Park NJ                            *
 *                                                                      *
 *               Glenn Fowler <glenn.s.fowler@gmail.com>                *
 *                    David Korn <dgkorn@gmail.com>                     *
 *                     Phong Vo <phongvo@gmail.com>                     *
 *                                                                      *
 ***********************************************************************/
/*
 * backwards binary compatibility
 */
#include "config_ast.h"  // IWYU pragma: keep

#include <sys/types.h>

#include "cdt.h"

#undef dtflatten
Dtlink_t *dtflatten(Dt_t *d) {
    return (Dtlink_t *)(*(_DT(d)->searchf))((d), (void *)(0), DT_FLATTEN);
}

#undef dtextract
Dtlink_t *dtextract(Dt_t *d) {
    return (Dtlink_t *)(*(_DT(d)->searchf))((d), (void *)(0), DT_EXTRACT);
}

#undef dtrestore
Dtlink_t *dtrestore(Dt_t *d, void *l) {
    return (Dtlink_t *)(*(_DT(d)->searchf))((d), (l), DT_RESTORE);
}

#undef dtsize
ssize_t dtsize(Dt_t *d) { return (ssize_t)(*(_DT(d)->searchf))((d), (void *)(0), DT_STAT); }
