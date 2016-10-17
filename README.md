# INCS 741 - Project 01 - Team 18
## Authors
Rajan Khullar | Ying Xuan Hu

## Easy Compile Instructions
``` sh
# move into the sub or otp directory
cd <cipher>
make
```

## Hard Compile Instructions
1. Substitution Cipher
``` sh
cd sub
gcc -c support.c -o support.o
gcc -c target.c -D mode=1 -o gen.o
gcc -c target.c -D mode=2 -o enc.o
gcc -c target.c -D mode=3 -o dec.o
gcc gen.o support.o -o gen
gcc enc.o support.o -o enc
gcc dec.o support.o -o dec
rm *.o
```

2. One Time Pad Cipher
``` sh
cd otp
gcc -c support.c -o support.o
gcc -c target.c -D mode=1 -o enc.o
gcc -c target.c -D mode=2 -o dec.o
gcc enc.o support.o -o enc
gcc dec.o support.o -o dec
rm *.o
```

## Execution Instructions
``` sh
# generate the key
./gen
# create a test file
echo hello world > secret
# encrypt
./enc secret
# decrypt
./dec <ciphertext>
```
## Question
Describe how you would determine whether a given ciphertext was generated using substitution cipher or one-time pad, without access to the decryption key.

## Response
The substitution cipher we implemented filters character outside of a through z. The resulting ciphertext will only include characters that pass the filter. If the ciphertext was generated with one time pad, it would include unreadable characters.

Furthermore the output of the one time pad cipher is supposed to be indistinguishable from random bytes. The output of the substitution cipher will carry some properties from its input. For example if the plaintext is English then the most common expected character is 'e'. If the cipher substitutes all e's with c's then the number of c's in the ciphertext will match the number of e's in the plaintext. In other words the frequency distribution of the ciphertext will be similar to that of English.
