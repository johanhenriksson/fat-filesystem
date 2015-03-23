CC = gcc
CFLAGS = -g 

SRC = fatinfo.c direntry.c directory.c blockio.c wordio.c fatfs.c fat12.c fat32.c 
OBJ = $(SRC:.c=.o)

fatinfo: $(OBJ)

depend: $(SRC)
	makedepend $(SRC)

clean:
	/bin/rm -f $(OBJ) fatinfo *~

# DO NOT DELETE

fatinfo.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
fatinfo.o: /usr/include/sys/_symbol_aliasing.h
fatinfo.o: /usr/include/sys/_posix_availability.h /usr/include/Availability.h
fatinfo.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
fatinfo.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
fatinfo.o: /usr/include/i386/_types.h /usr/include/sys/_types/_va_list.h
fatinfo.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_null.h
fatinfo.o: /usr/include/sys/_types/_off_t.h
fatinfo.o: /usr/include/sys/_types/_ssize_t.h /usr/include/secure/_stdio.h
fatinfo.o: /usr/include/secure/_common.h fatfs.h /usr/include/stdlib.h
fatinfo.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
fatinfo.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
fatinfo.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
fatinfo.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
fatinfo.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
fatinfo.o: /usr/include/sys/_types/_sigaltstack.h
fatinfo.o: /usr/include/sys/_types/_ucontext.h
fatinfo.o: /usr/include/sys/_types/_pthread_attr_t.h
fatinfo.o: /usr/include/sys/_types/_sigset_t.h
fatinfo.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
fatinfo.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
fatinfo.o: /usr/include/sys/_types/_int16_t.h
fatinfo.o: /usr/include/sys/_types/_int32_t.h
fatinfo.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
fatinfo.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
fatinfo.o: /usr/include/_types/_uint64_t.h
fatinfo.o: /usr/include/sys/_types/_intptr_t.h
fatinfo.o: /usr/include/sys/_types/_uintptr_t.h
fatinfo.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
fatinfo.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
fatinfo.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
fatinfo.o: /usr/include/libkern/_OSByteOrder.h
fatinfo.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
fatinfo.o: /usr/include/sys/_types/_ct_rune_t.h
fatinfo.o: /usr/include/sys/_types/_rune_t.h
fatinfo.o: /usr/include/sys/_types/_wchar_t.h /usr/include/machine/types.h
fatinfo.o: /usr/include/i386/types.h /usr/include/sys/_types/___offsetof.h
fatinfo.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_mode_t.h
fatinfo.o: fat12.h fat32.h wordio.h blockio.h directory.h direntry.h
direntry.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
direntry.o: /usr/include/sys/_symbol_aliasing.h
direntry.o: /usr/include/sys/_posix_availability.h
direntry.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
direntry.o: /usr/include/_types.h /usr/include/sys/_types.h
direntry.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
direntry.o: /usr/include/sys/_types/_va_list.h
direntry.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_null.h
direntry.o: /usr/include/sys/_types/_off_t.h
direntry.o: /usr/include/sys/_types/_ssize_t.h /usr/include/secure/_stdio.h
direntry.o: /usr/include/secure/_common.h /usr/include/stdlib.h
direntry.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
direntry.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
direntry.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
direntry.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
direntry.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
direntry.o: /usr/include/sys/_types/_sigaltstack.h
direntry.o: /usr/include/sys/_types/_ucontext.h
direntry.o: /usr/include/sys/_types/_pthread_attr_t.h
direntry.o: /usr/include/sys/_types/_sigset_t.h
direntry.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
direntry.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
direntry.o: /usr/include/sys/_types/_int16_t.h
direntry.o: /usr/include/sys/_types/_int32_t.h
direntry.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
direntry.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
direntry.o: /usr/include/_types/_uint64_t.h
direntry.o: /usr/include/sys/_types/_intptr_t.h
direntry.o: /usr/include/sys/_types/_uintptr_t.h
direntry.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
direntry.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
direntry.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
direntry.o: /usr/include/libkern/_OSByteOrder.h
direntry.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
direntry.o: /usr/include/sys/_types/_ct_rune_t.h
direntry.o: /usr/include/sys/_types/_rune_t.h
direntry.o: /usr/include/sys/_types/_wchar_t.h /usr/include/machine/types.h
direntry.o: /usr/include/i386/types.h /usr/include/sys/_types/___offsetof.h
direntry.o: /usr/include/sys/_types/_dev_t.h
direntry.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
direntry.o: /usr/include/sys/_types/_rsize_t.h
direntry.o: /usr/include/sys/_types/_errno_t.h /usr/include/strings.h
direntry.o: /usr/include/secure/_string.h direntry.h
directory.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
directory.o: /usr/include/sys/_symbol_aliasing.h
directory.o: /usr/include/sys/_posix_availability.h
directory.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
directory.o: /usr/include/_types.h /usr/include/sys/_types.h
directory.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
directory.o: /usr/include/sys/_types/_va_list.h
directory.o: /usr/include/sys/_types/_size_t.h
directory.o: /usr/include/sys/_types/_null.h /usr/include/sys/_types/_off_t.h
directory.o: /usr/include/sys/_types/_ssize_t.h /usr/include/secure/_stdio.h
directory.o: /usr/include/secure/_common.h /usr/include/stdlib.h
directory.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
directory.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
directory.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
directory.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
directory.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
directory.o: /usr/include/sys/_types/_sigaltstack.h
directory.o: /usr/include/sys/_types/_ucontext.h
directory.o: /usr/include/sys/_types/_pthread_attr_t.h
directory.o: /usr/include/sys/_types/_sigset_t.h
directory.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
directory.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
directory.o: /usr/include/sys/_types/_int16_t.h
directory.o: /usr/include/sys/_types/_int32_t.h
directory.o: /usr/include/sys/_types/_int64_t.h
directory.o: /usr/include/_types/_uint8_t.h /usr/include/_types/_uint16_t.h
directory.o: /usr/include/_types/_uint32_t.h /usr/include/_types/_uint64_t.h
directory.o: /usr/include/sys/_types/_intptr_t.h
directory.o: /usr/include/sys/_types/_uintptr_t.h
directory.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
directory.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
directory.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
directory.o: /usr/include/libkern/_OSByteOrder.h
directory.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
directory.o: /usr/include/sys/_types/_ct_rune_t.h
directory.o: /usr/include/sys/_types/_rune_t.h
directory.o: /usr/include/sys/_types/_wchar_t.h /usr/include/machine/types.h
directory.o: /usr/include/i386/types.h /usr/include/sys/_types/___offsetof.h
directory.o: /usr/include/sys/_types/_dev_t.h
directory.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
directory.o: /usr/include/sys/_types/_rsize_t.h
directory.o: /usr/include/sys/_types/_errno_t.h /usr/include/strings.h
directory.o: /usr/include/secure/_string.h directory.h direntry.h
blockio.o: /usr/include/sys/types.h /usr/include/sys/appleapiopts.h
blockio.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
blockio.o: /usr/include/sys/_posix_availability.h
blockio.o: /usr/include/machine/types.h /usr/include/i386/types.h
blockio.o: /usr/include/i386/_types.h /usr/include/sys/_types/_int8_t.h
blockio.o: /usr/include/sys/_types/_int16_t.h
blockio.o: /usr/include/sys/_types/_int32_t.h
blockio.o: /usr/include/sys/_types/_int64_t.h
blockio.o: /usr/include/sys/_types/_intptr_t.h
blockio.o: /usr/include/sys/_types/_uintptr_t.h
blockio.o: /usr/include/sys/_types/___offsetof.h /usr/include/sys/_types.h
blockio.o: /usr/include/machine/_types.h /usr/include/machine/endian.h
blockio.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
blockio.o: /usr/include/libkern/_OSByteOrder.h
blockio.o: /usr/include/libkern/i386/_OSByteOrder.h
blockio.o: /usr/include/sys/_types/_dev_t.h
blockio.o: /usr/include/sys/_types/_blkcnt_t.h
blockio.o: /usr/include/sys/_types/_blksize_t.h
blockio.o: /usr/include/sys/_types/_gid_t.h
blockio.o: /usr/include/sys/_types/_in_addr_t.h
blockio.o: /usr/include/sys/_types/_in_port_t.h
blockio.o: /usr/include/sys/_types/_ino_t.h
blockio.o: /usr/include/sys/_types/_ino64_t.h
blockio.o: /usr/include/sys/_types/_key_t.h /usr/include/sys/_types/_mode_t.h
blockio.o: /usr/include/sys/_types/_nlink_t.h /usr/include/sys/_types/_id_t.h
blockio.o: /usr/include/sys/_types/_pid_t.h /usr/include/sys/_types/_off_t.h
blockio.o: /usr/include/sys/_types/_uid_t.h
blockio.o: /usr/include/sys/_types/_clock_t.h
blockio.o: /usr/include/sys/_types/_size_t.h
blockio.o: /usr/include/sys/_types/_ssize_t.h
blockio.o: /usr/include/sys/_types/_time_t.h
blockio.o: /usr/include/sys/_types/_useconds_t.h
blockio.o: /usr/include/sys/_types/_suseconds_t.h
blockio.o: /usr/include/sys/_types/_rsize_t.h
blockio.o: /usr/include/sys/_types/_errno_t.h
blockio.o: /usr/include/sys/_types/_fd_def.h
blockio.o: /usr/include/sys/_types/_fd_setsize.h
blockio.o: /usr/include/sys/_types/_fd_set.h
blockio.o: /usr/include/sys/_types/_fd_clr.h
blockio.o: /usr/include/sys/_types/_fd_zero.h
blockio.o: /usr/include/sys/_types/_fd_isset.h
blockio.o: /usr/include/sys/_types/_fd_copy.h
blockio.o: /usr/include/sys/_types/_pthread_attr_t.h
blockio.o: /usr/include/sys/_types/_pthread_cond_t.h
blockio.o: /usr/include/sys/_types/_pthread_condattr_t.h
blockio.o: /usr/include/sys/_types/_pthread_mutex_t.h
blockio.o: /usr/include/sys/_types/_pthread_mutexattr_t.h
blockio.o: /usr/include/sys/_types/_pthread_once_t.h
blockio.o: /usr/include/sys/_types/_pthread_rwlock_t.h
blockio.o: /usr/include/sys/_types/_pthread_rwlockattr_t.h
blockio.o: /usr/include/sys/_types/_pthread_t.h
blockio.o: /usr/include/sys/_types/_pthread_key_t.h
blockio.o: /usr/include/sys/_types/_fsblkcnt_t.h
blockio.o: /usr/include/sys/_types/_fsfilcnt_t.h /usr/include/unistd.h
blockio.o: /usr/include/_types.h /usr/include/sys/unistd.h
blockio.o: /usr/include/sys/_types/_posix_vdisable.h
blockio.o: /usr/include/sys/_types/_seek_set.h /usr/include/Availability.h
blockio.o: /usr/include/AvailabilityInternal.h
blockio.o: /usr/include/sys/_types/_null.h /usr/include/sys/select.h
blockio.o: /usr/include/sys/_types/_timespec.h
blockio.o: /usr/include/sys/_types/_timeval.h
blockio.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/_select.h
blockio.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
blockio.o: /usr/include/string.h /usr/include/strings.h
blockio.o: /usr/include/secure/_string.h /usr/include/secure/_common.h
blockio.o: blockio.h /usr/include/stdlib.h /usr/include/sys/wait.h
blockio.o: /usr/include/sys/signal.h /usr/include/machine/signal.h
blockio.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
blockio.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
blockio.o: /usr/include/sys/_types/_sigaltstack.h
blockio.o: /usr/include/sys/_types/_ucontext.h /usr/include/sys/resource.h
blockio.o: /usr/include/stdint.h /usr/include/_types/_uint8_t.h
blockio.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
blockio.o: /usr/include/_types/_uint64_t.h /usr/include/_types/_intmax_t.h
blockio.o: /usr/include/_types/_uintmax_t.h /usr/include/alloca.h
blockio.o: /usr/include/sys/_types/_ct_rune_t.h
blockio.o: /usr/include/sys/_types/_rune_t.h
blockio.o: /usr/include/sys/_types/_wchar_t.h
wordio.o: wordio.h
fatfs.o: /usr/include/fcntl.h /usr/include/sys/fcntl.h
fatfs.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
fatfs.o: /usr/include/sys/_symbol_aliasing.h
fatfs.o: /usr/include/sys/_posix_availability.h /usr/include/machine/_types.h
fatfs.o: /usr/include/i386/_types.h /usr/include/Availability.h
fatfs.o: /usr/include/AvailabilityInternal.h
fatfs.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_mode_t.h
fatfs.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_pid_t.h
fatfs.o: /usr/include/sys/_types/_o_sync.h /usr/include/sys/_types/_o_dsync.h
fatfs.o: /usr/include/sys/_types/_seek_set.h
fatfs.o: /usr/include/sys/_types/_s_ifmt.h
fatfs.o: /usr/include/sys/_types/_timespec.h
fatfs.o: /usr/include/sys/_types/_filesec_t.h /usr/include/stdio.h
fatfs.o: /usr/include/_types.h /usr/include/sys/_types/_va_list.h
fatfs.o: /usr/include/sys/_types/_null.h /usr/include/sys/_types/_ssize_t.h
fatfs.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
fatfs.o: /usr/include/sys/stat.h /usr/include/sys/_types/_blkcnt_t.h
fatfs.o: /usr/include/sys/_types/_blksize_t.h
fatfs.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_ino_t.h
fatfs.o: /usr/include/sys/_types/_ino64_t.h
fatfs.o: /usr/include/sys/_types/_nlink_t.h /usr/include/sys/_types/_uid_t.h
fatfs.o: /usr/include/sys/_types/_gid_t.h /usr/include/sys/_types/_time_t.h
fatfs.o: /usr/include/sys/types.h /usr/include/sys/appleapiopts.h
fatfs.o: /usr/include/machine/types.h /usr/include/i386/types.h
fatfs.o: /usr/include/sys/_types/_int8_t.h /usr/include/sys/_types/_int16_t.h
fatfs.o: /usr/include/sys/_types/_int32_t.h
fatfs.o: /usr/include/sys/_types/_int64_t.h
fatfs.o: /usr/include/sys/_types/_intptr_t.h
fatfs.o: /usr/include/sys/_types/_uintptr_t.h
fatfs.o: /usr/include/sys/_types/___offsetof.h /usr/include/machine/endian.h
fatfs.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
fatfs.o: /usr/include/libkern/_OSByteOrder.h
fatfs.o: /usr/include/libkern/i386/_OSByteOrder.h
fatfs.o: /usr/include/sys/_types/_in_addr_t.h
fatfs.o: /usr/include/sys/_types/_in_port_t.h
fatfs.o: /usr/include/sys/_types/_key_t.h /usr/include/sys/_types/_id_t.h
fatfs.o: /usr/include/sys/_types/_clock_t.h
fatfs.o: /usr/include/sys/_types/_useconds_t.h
fatfs.o: /usr/include/sys/_types/_suseconds_t.h
fatfs.o: /usr/include/sys/_types/_rsize_t.h
fatfs.o: /usr/include/sys/_types/_errno_t.h /usr/include/sys/_types/_fd_def.h
fatfs.o: /usr/include/sys/_types/_fd_setsize.h
fatfs.o: /usr/include/sys/_types/_fd_set.h /usr/include/sys/_types/_fd_clr.h
fatfs.o: /usr/include/sys/_types/_fd_zero.h
fatfs.o: /usr/include/sys/_types/_fd_isset.h
fatfs.o: /usr/include/sys/_types/_fd_copy.h
fatfs.o: /usr/include/sys/_types/_pthread_attr_t.h
fatfs.o: /usr/include/sys/_types/_pthread_cond_t.h
fatfs.o: /usr/include/sys/_types/_pthread_condattr_t.h
fatfs.o: /usr/include/sys/_types/_pthread_mutex_t.h
fatfs.o: /usr/include/sys/_types/_pthread_mutexattr_t.h
fatfs.o: /usr/include/sys/_types/_pthread_once_t.h
fatfs.o: /usr/include/sys/_types/_pthread_rwlock_t.h
fatfs.o: /usr/include/sys/_types/_pthread_rwlockattr_t.h
fatfs.o: /usr/include/sys/_types/_pthread_t.h
fatfs.o: /usr/include/sys/_types/_pthread_key_t.h
fatfs.o: /usr/include/sys/_types/_fsblkcnt_t.h
fatfs.o: /usr/include/sys/_types/_fsfilcnt_t.h /usr/include/sys/mman.h
fatfs.o: fatfs.h /usr/include/stdlib.h /usr/include/sys/wait.h
fatfs.o: /usr/include/sys/signal.h /usr/include/machine/signal.h
fatfs.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
fatfs.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
fatfs.o: /usr/include/sys/_types/_sigaltstack.h
fatfs.o: /usr/include/sys/_types/_ucontext.h
fatfs.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/resource.h
fatfs.o: /usr/include/stdint.h /usr/include/_types/_uint8_t.h
fatfs.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
fatfs.o: /usr/include/_types/_uint64_t.h /usr/include/_types/_intmax_t.h
fatfs.o: /usr/include/_types/_uintmax_t.h /usr/include/sys/_types/_timeval.h
fatfs.o: /usr/include/alloca.h /usr/include/sys/_types/_ct_rune_t.h
fatfs.o: /usr/include/sys/_types/_rune_t.h /usr/include/sys/_types/_wchar_t.h
fatfs.o: fat12.h fat32.h
fat12.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
fat12.o: /usr/include/sys/_symbol_aliasing.h
fat12.o: /usr/include/sys/_posix_availability.h /usr/include/Availability.h
fat12.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
fat12.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
fat12.o: /usr/include/i386/_types.h /usr/include/sys/_types/_va_list.h
fat12.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_null.h
fat12.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_ssize_t.h
fat12.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h fat12.h
fat32.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
fat32.o: /usr/include/sys/_symbol_aliasing.h
fat32.o: /usr/include/sys/_posix_availability.h /usr/include/Availability.h
fat32.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
fat32.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
fat32.o: /usr/include/i386/_types.h /usr/include/sys/_types/_va_list.h
fat32.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_null.h
fat32.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_ssize_t.h
fat32.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h fat32.h
fat32.o: fat12.h
