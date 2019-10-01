#include <iostream>
#include <array>
#include <string.h>
#include <typeinfo>

using namespace std;

void afficherTaille(const array<int, 5> &tb)
{
    cout << "    size: " << tb.size() << " elements" << endl;
}

int main() // global entry point, only one
{
    cout << "++" << endl; // or std::cout << "++" << std::endl; if not using namespace std at top

    // :: resolution operator
    // << insertion operator

    cout << "ff++" << endl;

    // entiers
    // declaration
    int n; // entier signé (+/-)
    n = 1;
    int k = -2;
    int a = sizeof(n);
    int b = sizeof(int);
    cout << "sizeof(n): " << a << ", sizeof(int): " << b << endl;

    long li;
    cout << "sizeof(long): " << sizeof(li) << endl;

    int32_t i32;
    cout << "sizeof(int32_t): " << sizeof(i32) << endl;

    uint64_t ui64; //unsigned int
    cout << "sizeof(uint64_t): " << sizeof(ui64) << endl;

    float f1;
    cout << f1 << " 0 default sizeof(f1) " << sizeof(f1) << endl;
    f1 = 0.123456789;
    f1 = 0.1234567;
    cout << f1 << " new f1, sizeof(f1) " << sizeof(f1) << endl;

    double d1 = 0.123456789123456789;
    cout << d1 << " sizeof(d1) " << sizeof(d1) << endl;

    // configure cout for better output precision
    cout.precision(50);
    cout << "new precision f1:" << f1 << endl; // 7 decimales precision
    cout << "new precision d1:" << d1 << endl; //  17 decimales precision

    //bool
    bool bl = true;
    bl = f1 > d1;
    cout << bl << "  sizeof bl:" << sizeof(bl) << endl;

    f1 = 0.;
    if (f1)
        cout << "f1 float 0. true" << endl;
    else
        cout << "f1 false 0." << endl;

    // pointers
    float *pf = &f1;

    cout << "adresse f1:" << pf << endl;

    double *pd1 = &d1;
    cout << "adresse d1:" << pd1 << endl;

    // pointer on pointer

    double **ppd1 = &pd1;

    cout << "l'adresse de l'adresse de d1 est: " << ppd1 << endl;
    cout << "la valeur à l'adresse de l'adresse de ppd1 est: " << **ppd1 << endl;
    cout << "la valeur à l'adresse de ppd1 est: " << *ppd1 << endl;

    //references
    int &ri = n; //definition

    cout << "valeur referencee:" << ri << ", adresse de ri: " << &ri << ", adresse de n" << &n << endl;

    n = 7;
    ri = 8;
    cout << "valeur referencee:" << ri << ", n:" << n << ", adresse de ri: " << &ri << ", adresse de n: " << &n << endl;

    // un pointeur peut etre null, ne contient meme pas une adresse
    // une reference ne peut pas

    //pf = nullptr;

    // on ne peut aps avoir une référence de référence
    //int &refri = &ri;

    // reference sur un pointeur (on obtient un alias pour le pointeur)

    float *&rpf = pf;

    cout << "reference sur un poitneru: " << rpf << " et donc sur la valeur" << *rpf << endl;
    cout << "pointeur: " << *&rpf << endl;

    // modif une reference, c'est souvent une mauvaise idee
    //rpf = 0;
    //cout << "reference sur un poitneru: " << rpf << " et donc sur la valeur" << *rpf  << endl;

    // 2 types de tableaux en c++

    // tableaux langage C

    int tbEntier[]{5, 3, 6, 7}; // déclaration d'un tableau monodimensionnel et son initialisation à l'aide d'une liste d'initialisation

    int autreTbEntier[] = {5, 3, 6, 7}; // uniform initialization

    cout << "tbEntier: " << tbEntier << endl; //adresse du premier element du tableau
    cout << "valtbEntier: " << *tbEntier << endl;
    cout << "size  tbEntier: " << sizeof(tbEntier) << endl;
    cout << "nb elem tbEntier: " << sizeof(tbEntier) / sizeof(int) << endl;

    cout << "autreTbEntier: " << autreTbEntier << endl;
    cout << "autreTbEntier: " << *autreTbEntier << endl;

    //tableau de chaines
    string tbNoms[] = {"marie", "pierre", "cécile"};   //possibilité d'utiliser des "é" en c++
    string autreTbNoms[]{"marie", "pierre", "cécile"}; //probablement + rapide car n'instantie pas l'objet avant

    // afficher conte nu tableau
    cout << "tbNoms contient " << sizeof(tbNoms) / sizeof(tbNoms[0]) << " elements" << endl;
    for (string &x : tbNoms)
    {
        cout << "\t " << x << endl;
    }

    // toutes les memes valeurs
    int zeros[10]{0};
    for (int x : zeros)
    {
        cout << "\t " << x << endl;
    }

    // les tableaux peuvent être multidimensionnels
    int tbMulti[][3] = {{1, 2}, {3, 4}, {5, 6}};
    // ou
    int autreTbMulti[][3]{{1, 2}, {3, 4}, {5, 6}};

    // acces en ecriture
    autreTbMulti[2][1] *= 10;

    cout << "autreTbMulti[2][1]: " << autreTbMulti[2][1] << endl;

    // tableau C++
    //needs #include <array>
    array<int, 3> tbEntier2{11, 101, 10001};
    cout << "Type du tableau autreTbEntier   " << typeid(autreTbEntier).name() << endl; // needs #include <typeinfo>
    cout << "Type du tableau tbMulti         " << typeid(tbMulti).name() << endl;       // needs #include <typeinfo>

    // infered type, si le type peut être déduit par le compilateur
    auto tbEntiers3 = {4, 5, 6, 7, 8};

    cout << "taille tbEntiers2 nb elements: " << tbEntier2.size() << endl;

    cout << "tbEntier2.at(1): " << tbEntier2.at(1) << endl;
    // at est une left value
    tbEntier2.at(1) = 22;
    cout << "tbEntier2[1]: " << tbEntier2[1] << endl;
    tbEntier2[1] = 122;
    cout << "tbEntier2[1]: " << tbEntier2[1] << endl;

    // tbEntier[20] = 1234556;
    // cout << "tbEntiers20: " << tbEntier[20000] << endl;  // !! SIGSEGV, pas de controle des bornes en C

    //la fonction at assure le controle des bornes

    try
    {
        cout << "tbEntiers2.at(5): " << tbEntier2.at(5) << endl;
    }
    catch (...)
    {
        cout << "l'operaton a levé une exception " << endl;
    }

    array<int, 5> tbEntiers4 = {4, 5, 6, 7, 8};
    //passer un tableau C++ à une fonction
    afficherTaille(tbEntiers4);

    char c = 'a';
    cout << "c = " << c << " , taille: " << sizeof(c) << endl;

    // chaines de caracteres

    // en C
    char *nom = "Pioerrr";

    cout << "nom:" << nom << " , taille: " << sizeof(nom) << " octest, longueur chaine" << strlen(nom) << "caracteres" << endl;

    // string C++
    // plusieurs façons d'instantier
    string nom2 = "cécile";
    string nom3{"Marie"};

    // string API (manip des chaines C++)

    int lc = nom2.length();
    cout << "longueur cécile: " << lc << endl; // 7car é a besoin de 2 octets

    // catch the é
    cout << "nom2[1]: " << nom2[1] << endl;
    cout << "nom2[1]: " << nom2.substr(1, 2) << endl;

    //concaténation n'est pas implémentée en C, fonctionne en C++
    //nom += "Durand";  // C
    nom3 += " Durand"; // C++
    cout << "nom concatenated: " << nom3 << endl;

    // string C++ > string C

    const char *nomC = nom2.c_str();
    cout << "nomC :" << nomC << ", longueur: " << strlen(nomC) << endl;

    // print formaté
    int n1 = 1000;
    int n2 = 20;

    printf("%i, %o, %i \n", n1, n2, n1 * n2);  // %o : octal
    printf("%2d, %d, %d \n", n1, n2, n1 * n2); // %d != %f : float

    char mon_character = 'y';
    printf("Le charactere %c a le code %i\n", mon_character, mon_character);

    n1 = 30000;
    n2 = 90000;
    printf("%i, %i, %i \n", n1, n2, n1 * n2);
    printf("%i, %i, %li \n", n1, n2, n1 * n2);

    // nombre de chiffres de la partie décimale
    float f = 0.1234567f;
    double d = 0.1234567891234567;
    printf("%lf    %lf \n", f, d);
    printf("%.12f    %.12lf \n", f, d);

    //préciser le nombre total de chiffres
    printf("%20.12f    %20.12lf \n", f, d);

    //conversion numérique > str
    n1 = 111;
    string sn1 = to_string(n1);
    cout << "n1=" << n1 << ", sn1="
         << "\"" + sn1 + "\"" << endl; // concatenation dans le stream

    //conversion str > num
    string sn2 = "2222";
    n2 = stoi(sn2);
    cout << "n2 +3=" << n2 + 3 << endl;

    string spi = "3.14159";
    double dpi = stod(spi);
    cout << "double pi: " << dpi << endl;

    cout << "fin normale de l'application" << endl;

    return 0;
}