Il y a uniquement une verification de nom d'argument pour eviter de faire `./level08 token`
Impossible de faire un copie du fcher ou de changer le nom, mais on peut faire un lien


```ln -s token token_link```


Il faut neanmoins que le lien ait un nom qui ne commence pas par `token`


```
chmod +wr .
ln -s token dont_say_the_t_word
./level08 dont_say_the_t_word
```
