# POO2 2020 - Labo 03 -Rivières

*Auteurs: Walther Simon, Moreno Andres*

##### <u>Choix d'implémentations</u>

La classe Controller gère le jeu et les interaction de l'utilisateur. Pour chaque déplacement de personne, les contraintes sont vérifiés sur les Container de départ  et d'arrivée.
Les contrainte sont des objets contenant une fonction "check" qui vérifie si elle est satisfaite sur un container passé en argument. Elles contienent aussi le message d'erreur qui peux être afficher si la contrainte n'est pas respectée.
Le person sont différenciées grâce à leur nom, roles et sexe. On distingue quatre types de personnes, policier, voleur, parent et enfant. Les contraintes se servent des ces information pour vérifier si elle sont satisfaites. Par exemple, la contrainte voleur, vérifie que s'il y a un voleur il doit aussi y avoir un policier si au moins un parent ou un enfant est présent. Les contraintes pour les enfants se servent aussi du sex pour savoir si c'est un garçon ou une fille. 

Annexes
Diagramme de classe (UML)

