/*
 *  COPYRIGHT (c) 1989-2010.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */

#include <bsp.h> /* for device driver prototypes */
#include "tmacros.h"
#include <rtems/untar.h>
#include <rtems/error.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "initial_filesystem_tar.h"

#define TARFILE_START initial_filesystem_tar
#define TARFILE_SIZE  initial_filesystem_tar_size

void test_cat(
  char *file,
  int   offset_arg,
  int   length
);

void test_untar_from_memory(void)
{
  rtems_status_code sc;

  printf("Untaring from memory - ");
  sc = Untar_FromMemory((void *)TARFILE_START, TARFILE_SIZE);
  if (sc != RTEMS_SUCCESSFUL) {
    printf ("error: untar failed: %s\n", rtems_status_text (sc));
    exit(1);
  }
  printf ("successful\n");

  /******************/
  printf( "========= /home/test_file =========\n" );
  test_cat( "/home/test_file", 0, 0 );
  
  /******************/
  printf( "========= /symlink =========\n" );
  test_cat( "/symlink", 0, 0 );

}

void test_untar_from_file(void)
{
  rtems_status_code  sc;
  int                fd;

  puts( "Copy tar image to test.tar" );
  /* Copy tar image from object to file in IMFS */
  fd = open( "/test.tar", O_CREAT|O_TRUNC|O_WRONLY, 0777 );
  rtems_test_assert( fd != -1 );

  sc = write( fd, TARFILE_START, TARFILE_SIZE );
  rtems_test_assert( sc == TARFILE_SIZE );
  close( fd );

  /* make a directory to untar it into */
  sc = mkdir( "/dest", 0777 );
  rtems_test_assert( !sc );

  sc = chdir( "/dest" );
  rtems_test_assert( !sc );

  /* Untar it */
  sc = Untar_FromFile( "/test.tar" );
  printf("Untaring from file - ");
  if (sc != RTEMS_SUCCESSFUL) {
    printf ("error: untar failed: %s\n", rtems_status_text (sc));
    exit(1);
  }
  printf ("successful\n");

  /******************/
  printf( "========= /dest/home/test_file =========\n" );
  test_cat( "/dest/home/test_file", 0, 0 );
  
  /******************/
  printf( "========= /dest/symlink =========\n" );
  test_cat( "/dest/symlink", 0, 0 );
}

rtems_task Init(
  rtems_task_argument ignored
)
{
  printf( "\n\n*** TAR01 TEST ***\n" );

  test_untar_from_memory();
  puts( "" );
  test_untar_from_file();

  printf( "*** END OF TAR01 TEST ***\n" );
  exit( 0 );
}


/* NOTICE: the clock driver is explicitly disabled */
#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_MAXIMUM_TASKS            1
#define CONFIGURE_USE_IMFS_AS_BASE_FILESYSTEM
#define CONFIGURE_LIBIO_MAXIMUM_FILE_DESCRIPTORS 5

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
