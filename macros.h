#ifndef MACROS_H
#define MACROS_H

#define langN       26
#define block_size  512

#define key_name    "key"
#define ptex_name   "plaintext"
#define ctex_name   "ciphertext"

#define sub_sfx     ".txt"
#define otp_sfx     ".dat"

#define key_sub     key_name  sub_sfx
#define key_otp     key_name  sub_otp
#define ptex_sub    ptex_name sub_sfx
#define ptex_otp    ptex_name sub_otp
#define ctex_sub    ctex_name sub_sfx
#define ctex_otp    ctex_name sub_otp

#endif
