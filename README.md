# immutable-fuse
An immutable filesystem using FUSE
Copyright (C) 2017 Neeral Dodhia <neeral@github.com>

# License
This program can be distributed under the terms of the GNU GPLv3.
See the file COPYING.

## Origin
This code is heavily based on the Big Brother File System, developed
by Joseph J. Pfeiffer, Jr., Ph.D. The structure of the code, build
process, etc are all taken this. Individual functions have been
modified. The original documentation for this file is included below.
 
This code is derived from function prototypes found /usr/include/fuse/fuse.h
Copyright (C) 2001-2007  Miklos Szeredi <miklos@szeredi.hu>
His code is licensed under the LGPLv2.
A copy of that code is included in the file fuse.h

# Why?
The point of this FUSE filesystem is to learn how to write a FUSE
filesystem. It is my first FUSE filesystem and I used the Big Brother
File System written by Joseph J. Pfeiffer, Jr., Ph.D. as a tutorial.
    https://www.cs.nmsu.edu/~pfeiffer/fuse-tutorial/
Other resources I found helpful are
  - https://www.cs.hmc.edu/~geoff/classes/hmc.cs135.201109/homework/fus\
    e/fuse_doc.html#other-options
  - http://blog.jeffli.me/blog/2014/08/30/use-gdb-to-understand-fuse-fi\
    le-system/#how-does-fuse-work

# What does immutable filesystem do?
This filesystem aims to make the `rootdir`, that it is mounted on,
immutable. In other words, no changes should take place to `rootdir`.
The Immutable File System stores all changes to files in-memory. This
allows users to have the impression that they are modifying files and
making changes without these being persisted. When the FUSE filesystem
is unmounted, all changes are lost. The Immutable File System supports
a limited range of operations.

It is possible to read from, write to and delete files and directories.
Creating new files and directories, renaming, changing owner, changing
privileges, creating links, etc are not supported. By this, I mean that
they are destructive operations that will modify `rootdir`.

# How to build, run and test
Instructions from the original tutorial are available [here](html/running.html)
