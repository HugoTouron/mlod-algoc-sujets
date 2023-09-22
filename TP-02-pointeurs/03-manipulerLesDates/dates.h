typedef enum {
    Janvier = 1,
    Fevrier,
    Mars,
    Avril,
    Mai,
    Juin,
    Juillet,
    Aout,
    Septembre,
    Octobre,
    Novembre,
    Decembre
}Mois;

typedef struct {
    int jour;
    Mois mois;
    int annee;
}Date;

void initialiseDate(Date *d);

void afficheDate(Date *d);

Date creerDateParCopie();


Date* newDate();

