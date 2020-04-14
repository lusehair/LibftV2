
~*"C'est dans les vieux pots que l'ont fait les meilleurs confitures"*

C'est dans cette nouvelles version, plus complète, que nous allons pouvoir retrouver les fonctions originels du premier projet : **La Libft**  avec des fonctions 
supplémentaires, mais essentielles (*putchar, putstr, putnbr, itoabase, etc ...*) qui proviennent des projets suivants. 

Tiens ! En parlant des projets suivants ! Vous allez également retrouver dans cette LibftV2 les fonctions suivantes : 

 - **Get Next Line** (avec le simple FD uniquement) 
 - **ft_printf** (avec les conversions suivantes :   `cspdiuxX%` et les options    `-0.*`)

Le *Makefile* à également été refait pour l'occasion, pour être ... un peu plus conviviale. 

Pour inclure la lib dans vos .c n'oubliez pas : 

    #include "libft.h"
    #include "get_next_line.h"
    #include "ft_printf/ft_printf.h"

 

Et pour la compilation : 

    gcc main.c functions.c libft.a

