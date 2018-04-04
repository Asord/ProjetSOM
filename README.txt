-----------------------------------------
	Utilisation de l'interface
-----------------------------------------

Nouveau réseau: choisir le dossier contenant toutes les images(JPEG) qui vont être utilisées comme données d'entrée.
Réinitialiser: reinitialisation du reseau (non fonctionnel).

Taille du réseau: doit être comprise entre 1x1 et 99x99.

Alpha: doit être compris entre 0 et 1. 
Taux alpha: doit être compris entre 0 et 1, inferieur à taux beta.
Periode alpha: doit être compris entre 1 et 5.

Beta: Valeur maximale égale au minimum entre le nombre de ligne et le nombre de colonne du réseau.
      Bug: La valeur affichée ne correspond pas forcement à la valeur du slider.

Taux beta: doit être compris entre 0 et 1, supérieur à taux alpha.
Periode beta: doit être compris entre 1 et 5.

Pause apprentissage: Non implementé.

Itérations: affiche l'itération en cours et le nombre d'itérations totales.
Temps: affiche la durée totale de l'apprentissage à la fin de l'algorithme.

-------------------------------------------------
	Exemple de valeurs fonctionnelles
-------------------------------------------------

Taille du réseau : 20*20

Alpha : 1
Taux Alpha : 0.80
Periode Alpha : 5

Beta : 1
Taux Beta : 0.81
Periode Beta : 5