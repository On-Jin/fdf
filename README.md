FDF
===

![alt tag](https://raw.github.com/Jino42/fdf/blob/master/pic/Julia_poesie.png)

Presentation
-
Ce projet consiste à créer graphiquement la representation schématique (en “fils de fer” ou “wireframe” en anglais) d’un terrain en relief en reliant différents points (x, y, z) par des segments. Les coordonnées du terrain seront stockées dans un fichier passé en paramètre, dont voici un exemple :

/*Photo*/
Resultat :
/*Photo*/

Ce qui est demandé est donc "basic". Pas forcement de couleur, de mouvement/rotation et autres fantaisies !

Defi
-
Pour cela nous disposons de la minilibx. Une bibliothèque graphique extrèmement rudimentaire !
Le defi de FDF consistait, pour ma personne, a comprendre: 

 - Comment fonctionnent les images
		*(4Octets par pixel, dont 3 dédié au RGB)*
 - Comment tracer un segment entre deux points
	*(Algorithme de Bresenham)*
 - Comprendre les notions de perspectives et de matrice
*(Perspective Isometrique pour mon cas, avec une rotation en Z)*
 - Gestion des évènements

Histoire
-
Ce projet fut mon réel premier projet a 42 (Les trois premier étant commun et assez peut massif/technique);
De ce fait, une multitude de choses s'ouvraient alors a moi. Organiser son projet, apprendre a comprendre sa premier bibliothèque, et tous les défis technique du C auquel je m'étais pas encore confronté.
N'ayant que les outils les plus basic, avec très peut d'information, il a fallut faire preuve de reflexion et d'imagination.
Je l'ai effectué en 11jours de travail, sur une période de 14jours

Pointsfortfaible
-
*Point faible*

 - Rotation matriciel, seulement sur un seul axe
 - Le degradé sur les droites
 - La gestion des faces caché
 - Pas assez sexy a mes yeux

*Point fort*

 - Creation d'une toute petite bibliothèque graphique générique basé sur la minilibx.
 *(Tracer des segments, convertion couleurs [Voir plus bas], creer une image... )*
 

 - Utilisation de HSV (Hue, saturation, value) pour les couleurs, ensuite convertie en RGB
 *Permet de faire de très jolie dégradé, mais pas assez exploité*
 - Reste jolie
 /*Photo fract*/

Conclusion
-
Sachant ou ce trouve mes "erreurs" (Ou en tout cas, les point sur lesquels j'aurait pu m'investir d'avantage.), j'ai une grande envie de le recommencer. Mais une fois la OpenGl assimilé
Le sujet etant assez gentil, de base ils nous demandent de faire juste un rendu, qui ne bouge pas, sans couleur, des Points relié entre eux.
Le reste est du bonus, donc le travail est quand meme présent.
J'aimerais juste avoir un rendu plus ... jolie, intense !
