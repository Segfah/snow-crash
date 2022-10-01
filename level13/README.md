Il faut faire croire au programme que notre uid est 4242.

On peut utiliser un exploit de LD_PRELOAD pour donner a l'executable notre propre fonction `getuid`

```
chmod +wr .
cat > exploit.c << EOF
#include <unistd.h>
#include <sys/types.h>


uid_t getuid(void)
{
	return (4242);
}
EOF
gcc -shared exploit.c -o exploit.so
export LD_PRELOAD=/home/user/level13/exploit.so
```

Maintenant, on execute dans le debugger

```
gdb ./level13
```
```
(gdb) run
```

