-----------------------------------------
	Utilisation de l'interface
-----------------------------------------

Nouveau r�seau: choisir le dossier contenant toutes les images(JPEG) qui vont �tre utilis�es comme donn�es d'entr�e.
R�initialiser: reinitialisation du reseau (non fonctionnel).

Taille du r�seau: doit �tre comprise entre 1x1 et 99x99.

Alpha: doit �tre compris entre 0 et 1. 
Taux alpha: doit �tre compris entre 0 et 1, inferieur � taux beta.
Periode alpha: doit �tre compris entre 1 et 5.

Beta: Valeur maximale �gale au minimum entre le nombre de ligne et le nombre de colonne du r�seau.
      Bug: La valeur affich�e ne correspond pas forcement � la valeur du slider.

Taux beta: doit �tre compris entre 0 et 1, sup�rieur � taux alpha.
Periode beta: doit �tre compris entre 1 et 5.

Pause apprentissage: Non implement�.

It�rations: affiche l'it�ration en cours et le nombre d'it�rations totales.
Temps: affiche la dur�e totale de l'apprentissage � la fin de l'algorithme.

-------------------------------------------------
	Exemple de valeurs fonctionnelles
-------------------------------------------------

Taille du r�seau : 20*20

Alpha : 1
Taux Alpha : 0.80
Periode Alpha : 5

Beta : 1
Taux Beta : 0.81
Periode Beta : 5