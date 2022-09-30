Aucun fichier apparent ou qui appartient a level14 ou flag14.

On essaie alors de casser `getflag`

```sh
$> gdb -q /bin/getflag

(gdb) run
Starting program: /bin/getflag 
You should not reverse this
[Inferior 1 (process 2283) exited with code 01]


(gdb) disassemble main

Dump of assembler code for function main:
   0x08048946 <+0>:	push   %ebp
   0x08048947 <+1>:	mov    %esp,%ebp
   0x08048949 <+3>:	push   %ebx
   0x0804894a <+4>:	and    $0xfffffff0,%esp
   0x0804894d <+7>:	sub    $0x120,%esp
   0x08048953 <+13>:	mov    %gs:0x14,%eax
   0x08048959 <+19>:	mov    %eax,0x11c(%esp)
[...]
```

On explore les differents `call` etn retrouve un appel a la fonction `getuid`. Ceci est surement utiliser pour ensuite faire un switch et donne le token approprie. A la suite, on voit une logique qui ressemble bien a un switch.


```
[...]
   0x08048af8 <+434>:	call   0x80484c0 <fwrite@plt>
   0x08048afd <+439>:	call   0x80484b0 <getuid@plt>
   0x08048b02 <+444>:	mov    %eax,0x18(%esp)
   0x08048b06 <+448>:	mov    0x18(%esp),%eax
   0x08048b0a <+452>:	cmp    $0xbbe,%eax
   0x08048b0f <+457>:	je     0x8048ccb <main+901>
   0x08048b15 <+463>:	cmp    $0xbbe,%eax
   0x08048b1a <+468>:	ja     0x8048b68 <main+546>
   0x08048b1c <+470>:	cmp    $0xbba,%eax
   0x08048b21 <+475>:	je     0x8048c3b <main+757>
   0x08048b27 <+481>:	cmp    $0xbba,%eax
   0x08048b2c <+486>:	ja     0x8048b4d <main+519>
   0x08048b2e <+488>:	cmp    $0xbb8,%eax
   0x08048b33 <+493>:	je     0x8048bf3 <main+685>
   0x08048b39 <+499>:	cmp    $0xbb8,%eax
   0x08048b3e <+504>:	ja     0x8048c17 <main+721>
   0x08048b44 <+510>:	test   %eax,%eax
   0x08048b46 <+512>:	je     0x8048bc6 <main+640>
   0x08048b48 <+514>:	jmp    0x8048e06 <main+1216>
   0x08048b4d <+519>:	cmp    $0xbbc,%eax
   0x08048b52 <+524>:	je     0x8048c83 <main+829>
   0x08048b58 <+530>:	cmp    $0xbbc,%eax
   0x08048b5d <+535>:	ja     0x8048ca7 <main+865>
[...]
```

on peut alors sauter artificielement a une de ces instructions pour voir ce qu'elles effectuent.

```sh
(gdb) b main
Breakpoint 1 at 0x804894a


(gdb) run
Starting program: /bin/getflag 
Breakpoint 1, 0x0804894a in main ()


(gdb)ju *0x08048b21
Continuing at 0x8048b21.
kooda2puivaav1idi4f57q8iq
*** stack smashing detected ***: /bin/getflag terminated

Program received signal SIGSEGV, Segmentation fault.
0xb7e1cb19 in ?? () from /lib/i386-linux-gnu/libgcc_s.so.1

```

On retrouve ./level03/passwd:kooda2puivaav1idi4f57q8iq
Il semble qu'on puisse alors trouver notre dernier flag (et n'importe quel autre d'ailleurs) de cette facon.

```sh
(gdb) ju *0x08048bbb
Continuing at 0x8048bbb.
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
*** stack smashing detected ***: /bin/getflag terminated
```

Et le voila!

