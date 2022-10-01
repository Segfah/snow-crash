l'executable lance le script de nom `level06.php`



```sh
chmod +wr .
rm -f level06.php
```

Faire un nouveau fichier level06.php

#### ~/level06.php 
```
<?php
echo exec("getflag")
?>
```

puis:

```
./level06
```
