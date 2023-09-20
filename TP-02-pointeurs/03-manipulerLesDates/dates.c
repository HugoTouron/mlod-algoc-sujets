enum Mois {
    Janvier,
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
};

struct Date {
    int jour;
    enum Mois mois;
    int annee;
};
