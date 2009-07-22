/*
 *  MEDIT Shell Command Implmentation
 *
 *  Author: Fernando RUIZ CASAS
 *  Work: fernando.ruiz@ctv.es
 *  Home: correo@fernando-ruiz.com
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <rtems.h>
#include <rtems/shell.h>
#include <rtems/stringto.h>
#include "internal.h"

extern int rtems_shell_main_mdump(int, char *);

int rtems_shell_main_medit(
  int   argc,
  char *argv[]
)
{
  unsigned long  tmp;
  unsigned char *pb;
  int            n;
  int            i;

  if ( argc < 3 ) {
    fprintf(stderr,"%s: too few arguments\n", argv[0]);
    return -1;
  }

  /*
   *  Convert arguments into numbers
   */
  if ( !rtems_string_to_unsigned_long(argv[1], &tmp, NULL, 0) ) {
    printf( "Address argument (%s) is not a number\n", argv[1] );
    return -1;
  }
  pb = (unsigned char *) tmp;

  /*
   * Now edit the memory
   */
  n = 0;
  for (i=2 ; i<=argc ; i++) {
    unsigned char tmpc;

    if ( !rtems_string_to_unsigned_char(argv[i], &tmpc, NULL, 0) ) {
      printf( "Value (%s) is not a number\n", argv[i] );
      continue;
    }

    pb[n++] = tmpc;
  }

  return 0;
}

rtems_shell_cmd_t rtems_shell_MEDIT_Command = {
  "medit",                                      /* name */
  "medit address value1 [value2 ...]",          /* usage */
  "mem",                                        /* topic */
  rtems_shell_main_medit,                       /* command */
  NULL,                                         /* alias */
  NULL                                          /* next */
};
