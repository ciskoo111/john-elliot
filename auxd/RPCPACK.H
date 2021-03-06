/***************************************************************************
 *                                                                         *
 *    LIBDSK: General floppy and diskimage access library                  *
 *    Copyright (C) 2001,2005  John Elliott <jce@seasip.demon.co.uk>       *
 *                                                                         *
 *    This library is free software; you can redistribute it and/or        *
 *    modify it under the terms of the GNU Library General Public          *
 *    License as published by the Free Software Foundation; either         *
 *    version 2 of the License, or (at your option) any later version.     *
 *                                                                         *
 *    This library is distributed in the hope that it will be useful,      *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    *
 *    Library General Public License for more details.                     *
 *                                                                         *
 *    You should have received a copy of the GNU Library General Public    *
 *    License along with this library; if not, write to the Free           *
 *    Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,      *
 *    MA 02111-1307, USA                                                   *
 *                                                                         *
 ***************************************************************************/

/* Format of an RPC packet: 
 *
 * All integers are encoded in big-endian style (network byte order). 
 * INT16s take 2 bytes; INT32s take 4.
 * Byte arrays are encoded as an INT16 length followed by the data. 
 * Strings are encoded as a byte array including the null terminator.
 *
 * A packet consists of a header (generated by win32_mailslot() in drvwin32.c) 
 * and a body (generated by rpccli.c and parsed by rpcserv.c). Other RPC 
 * implementations may use a different header, or none.
 *
 * Structures are packed as each of their members, one after the other.
 * Driver pointers are mapped to integer handles.
 *
 * The first INT16 of the body is the function number defined just below. The
 * rest of the body varies according to what function is being performed.
 * */

/* Note: Although RPC IDs are defined for all libdsk functions, 
 * only a small subset are currently implemented. */
#define RPC_DG_PS2LS		10
#define RPC_DG_LS2PS		11
#define	RPC_DG_PT2LT		12
#define	RPC_DG_LT2PT		13
#define	RPC_DG_STDFORMAT	14
#define RPC_DG_DOSGEOM		15
#define RPC_DG_PCWGEOM		16
#define RPC_DG_CPM86GEOM	17

#define	RPC_DSK_STRERROR	20
#define	RPC_DSK_GET_PSH		21
#define RPC_DSK_TYPE_ENUM	22
#define	RPC_DSK_COMP_ENUM	23

#define RPC_DSK_OPEN			101
#define	RPC_DSK_CREAT			102
#define RPC_DSK_CLOSE			103
#define RPC_DSK_DRIVE_STATUS	104
#define RPC_DSK_PREAD			105
#define	RPC_DSK_LREAD			106
#define	RPC_DSK_XREAD			107
#define RPC_DSK_PWRITE			108
#define	RPC_DSK_LWRITE			109
#define	RPC_DSK_XWRITE			110
#define RPC_DSK_PCHECK			111
#define	RPC_DSK_LCHECK			112
#define	RPC_DSK_XCHECK			113
#define	RPC_DSK_PFORMAT			114
#define	RPC_DSK_LFORMAT			115
#define RPC_DSK_XTREAD			116
#define RPC_DSK_PTREAD			117
#define	RPC_DSK_LTREAD			118
#define	RPC_DSK_APFORM		    119
#define RPC_DSK_ALFORM		    120
#define RPC_DSK_GETGEOM			121
#define	RPC_DSK_PSECID			122
#define RPC_DSK_LSECID			123
#define RPC_DSK_PSEEK			124
#define RPC_DSK_LSEEK			125
#define RPC_DSK_SET_FORCEHEAD	126
#define	RPC_DSK_GET_FORCEHEAD	127
#define RPC_DSK_DRVNAME			128
#define	RPC_DSK_DRVDESC			129
#define RPC_DSK_COMPNAME		130
#define RPC_DSK_COMPDESC		131
#define RPC_DSK_OPTION_ENUM		132
#define RPC_DSK_OPTION_SET		133
#define RPC_DSK_OPTION_GET		134
#define RPC_DSK_TRACKIDS		135
#define RPC_DSK_RTREAD			136
/* These aren't exported libdsk functions (yet) but they may become so */
#define RPC_DSK_RAW765READ		137
#define RPC_DSK_RAW765WRITE		138
#define RPC_DSK_PROPERTIES		139
#define RPC_DSK_GETCOMMENT      	140
#define RPC_DSK_SETCOMMENT      	141


/* RPC pack functions */
dsk_err_t dsk_pack_err   (unsigned char **output, int *out_len, dsk_err_t e);
dsk_err_t dsk_pack_i16   (unsigned char **output, int *out_len, int16 value);
dsk_err_t dsk_pack_i32   (unsigned char **output, int *out_len, int32 value);
dsk_err_t dsk_pack_bytes (unsigned char **output, int *out_len, const unsigned char *buf, size_t len);
dsk_err_t dsk_pack_string(unsigned char **output, int *out_len, const char *str);
dsk_err_t dsk_pack_geom  (unsigned char **output, int *out_len, const DSK_GEOMETRY *g);
dsk_err_t dsk_pack_format(unsigned char **output, int *out_len, const DSK_FORMAT *f);

/* RPC unpack functions */
dsk_err_t dsk_unpack_err   (unsigned char **input, int *inp_len, dsk_err_t *e);

dsk_err_t dsk_unpack_i16   (unsigned char **input, int *inp_len, int16 *function);
dsk_err_t dsk_unpack_i32   (unsigned char **input, int *inp_len, int32 *function);

dsk_err_t dsk_unpack_bytes (unsigned char **input, int *inp_len, unsigned char **buf);
dsk_err_t dsk_unpack_string(unsigned char **input, int *inp_len, char **buf);
dsk_err_t dsk_unpack_geom  (unsigned char **input, int *inp_len, DSK_GEOMETRY *g);
dsk_err_t dsk_unpack_format(unsigned char **input, int *inp_len, DSK_FORMAT *f);

