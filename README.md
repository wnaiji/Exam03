# Exam03

## Objectif
Reproduire la fonction `get_next_line` en moins de trois heures.

## Préparation des tests
Pour évaluer correctement la fonction avant de la faire corriger, créez quatre fichiers distincts :
1. **Fichier A** : Contient plusieurs lignes, avec plusieurs sauts de ligne.
2. **Fichier B** : Est complètement vide.
3. **Fichier C** : Ne contient qu’un seul retour à la ligne.
4. **Fichier D** : Contient uniquement la chaîne "42" sans retour à la ligne (vérifiez avec `ls -l`).

## Vérification du comportement
Sur chacun de ces fichiers, assurez-vous de compter correctement les retours `NULL` renvoyés par `get_next_line`.  
- **Exemple** : Si vous appelez 10 fois `get_next_line` sur le fichier qui ne contient qu’un seul retour à la ligne, vous devez obtenir :
  - `"\n"` lors du premier appel,
  - puis `NULL` pour les 9 appels suivants.
  
Si une seule occurrence de `NULL` manque, c’est que `get_next_line` renvoie `"\0"` au lieu de `NULL`. Assurez-vous alors de corriger ce comportement.
