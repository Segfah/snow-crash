Copier le fichier dans la machine locale

```sh
scp scp://level02@192.168.56.101:4242/~/level02.pcap .
```

```sh
chmod +r level02.pcap
wireshark level02.pcap
```

Puis dans la fenetre de wire sahark on peut faire "Follow TCP stream" pour comprendre la communication effectuee.

On voit alors un mot de passe en clair que l'on peut recuperer: `ft_waNDReL0L`


Voici le mot de passe 
```
000000B9  66                                                 f
000000BA  74                                                 t
000000BB  5f                                                 _
000000BC  77                                                 w
000000BD  61                                                 a
000000BE  6e                                                 n
000000BF  64                                                 d
000000C0  72                                                 r
000000C1  7f                                                 .
000000C2  7f                                                 .
000000C3  7f                                                 .
000000C4  4e                                                 N
000000C5  44                                                 D
000000C6  52                                                 R
000000C7  65                                                 e
000000C8  6c                                                 l
000000C9  7f                                                 .
000000CA  4c                                                 L
000000CB  30                                                 0
000000CC  4c                                                 L
000000CD  0d                                                 .
```

7f en ascii est un delete, il faut alors clean-up le string.
