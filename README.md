# Exam03

Reproduire la fonction get_next_line en moins de trois heures.
Pour pouvoir tester la fonction avant de grademe, il faut préalablement créer 4 fichiers de test.
- 1 contenant plusieurs lignes, ainsi que plusieurs sauts à la ligne.
- 1 contenant rien.
- 1 avec seulement un retour à la ligne.
- 1 avec seulement 42 sans retour à la ligne (vérifier avec la commande ls -l).

Sur chaque test bien vérifier le nombre de retours (null),
Si par exemple vous utilisez 10 fois la fonction get_next_line avec le fichier contenant seulement un seul retour à la ligne,
Vous devez avoir comme résultat.
\n puis 9 (null) si un seul manque à l'appel cela signifie que get_next_line retourn un \0 qui n'est pas un (null).
