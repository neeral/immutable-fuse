/*
  Copyright (C) 2012 Joseph J. Pfeiffer, Jr., Ph.D. <pfeiffer@cs.nmsu.edu>

  This program can be distributed under the terms of the GNU GPLv3.
  See the file COPYING.

  There are a couple of symbols that need to be #defined before
  #including all the headers.
*/

#ifndef _PARAMS_H_
#define _PARAMS_H_

// The FUSE API has been changed a number of times.  So, our code
// needs to define the version of the API that we assume.  As of this
// writing, the most current API version is 26
#define FUSE_USE_VERSION 26

// need this to get pwrite().  I have to use setvbuf() instead of
// setlinebuf() later in consequence.
#define _XOPEN_SOURCE 500

// maintain bbfs state in here
#include <limits.h>
#include <stdio.h>
struct bb_state {
    FILE *logfile;
    char *rootdir;
    struct journal *journals;
    struct file_size *file_sizes;
};
#define BB_DATA ((struct bb_state *) fuse_get_context()->private_data)

// [ND] changes below
#include <sys/types.h>
struct journal {
    char *path;  // TODO how to make this immutable?
    char *buf;
    size_t size;
    off_t offset;
    struct journal *next;
};
struct file_size {
    char *path;  // TODO how to make this immutable?
    off_t offset;
    struct file_size *next;
};
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#endif
