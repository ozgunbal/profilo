/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_LINUX_QUOTA_
#define _UAPI_LINUX_QUOTA_
#include <museum/7.0.0/bionic/libc/linux/errno.h>
#include <museum/7.0.0/bionic/libc/linux/types.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __DQUOT_VERSION__ "dquot_6.6.0"
#define MAXQUOTAS 3
#define USRQUOTA 0
#define GRPQUOTA 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PRJQUOTA 2
#define INITQFNAMES { "user", "group", "project", "undefined", \
};
#define SUBCMDMASK 0x00ff
#define SUBCMDSHIFT 8
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define QCMD(cmd,type) (((cmd) << SUBCMDSHIFT) | ((type) & SUBCMDMASK))
#define Q_SYNC 0x800001
#define Q_QUOTAON 0x800002
#define Q_QUOTAOFF 0x800003
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define Q_GETFMT 0x800004
#define Q_GETINFO 0x800005
#define Q_SETINFO 0x800006
#define Q_GETQUOTA 0x800007
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define Q_SETQUOTA 0x800008
#define QFMT_VFS_OLD 1
#define QFMT_VFS_V0 2
#define QFMT_OCFS2 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define QFMT_VFS_V1 4
#define QIF_DQBLKSIZE_BITS 10
#define QIF_DQBLKSIZE (1 << QIF_DQBLKSIZE_BITS)
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  QIF_BLIMITS_B = 0,
  QIF_SPACE_B,
  QIF_ILIMITS_B,
  QIF_INODES_B,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  QIF_BTIME_B,
  QIF_ITIME_B,
};
#define QIF_BLIMITS (1 << QIF_BLIMITS_B)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define QIF_SPACE (1 << QIF_SPACE_B)
#define QIF_ILIMITS (1 << QIF_ILIMITS_B)
#define QIF_INODES (1 << QIF_INODES_B)
#define QIF_BTIME (1 << QIF_BTIME_B)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define QIF_ITIME (1 << QIF_ITIME_B)
#define QIF_LIMITS (QIF_BLIMITS | QIF_ILIMITS)
#define QIF_USAGE (QIF_SPACE | QIF_INODES)
#define QIF_TIMES (QIF_BTIME | QIF_ITIME)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define QIF_ALL (QIF_LIMITS | QIF_USAGE | QIF_TIMES)
struct if_dqblk {
  __u64 dqb_bhardlimit;
  __u64 dqb_bsoftlimit;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 dqb_curspace;
  __u64 dqb_ihardlimit;
  __u64 dqb_isoftlimit;
  __u64 dqb_curinodes;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 dqb_btime;
  __u64 dqb_itime;
  __u32 dqb_valid;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IIF_BGRACE 1
#define IIF_IGRACE 2
#define IIF_FLAGS 4
#define IIF_ALL (IIF_BGRACE | IIF_IGRACE | IIF_FLAGS)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  DQF_ROOT_SQUASH_B = 0,
  DQF_SYS_FILE_B = 16,
  DQF_PRIVATE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define DQF_ROOT_SQUASH (1 << DQF_ROOT_SQUASH_B)
#define DQF_SYS_FILE (1 << DQF_SYS_FILE_B)
struct if_dqinfo {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 dqi_bgrace;
  __u64 dqi_igrace;
  __u32 dqi_flags;
  __u32 dqi_valid;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define QUOTA_NL_NOWARN 0
#define QUOTA_NL_IHARDWARN 1
#define QUOTA_NL_ISOFTLONGWARN 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define QUOTA_NL_ISOFTWARN 3
#define QUOTA_NL_BHARDWARN 4
#define QUOTA_NL_BSOFTLONGWARN 5
#define QUOTA_NL_BSOFTWARN 6
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define QUOTA_NL_IHARDBELOW 7
#define QUOTA_NL_ISOFTBELOW 8
#define QUOTA_NL_BHARDBELOW 9
#define QUOTA_NL_BSOFTBELOW 10
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  QUOTA_NL_C_UNSPEC,
  QUOTA_NL_C_WARNING,
  __QUOTA_NL_C_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define QUOTA_NL_C_MAX (__QUOTA_NL_C_MAX - 1)
enum {
  QUOTA_NL_A_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  QUOTA_NL_A_QTYPE,
  QUOTA_NL_A_EXCESS_ID,
  QUOTA_NL_A_WARNING,
  QUOTA_NL_A_DEV_MAJOR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  QUOTA_NL_A_DEV_MINOR,
  QUOTA_NL_A_CAUSED_ID,
  __QUOTA_NL_A_MAX,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define QUOTA_NL_A_MAX (__QUOTA_NL_A_MAX - 1)
#endif