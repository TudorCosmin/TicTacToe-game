#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

void pos(short C, short R)
{
    COORD xy ;
    xy.X = C ;
    xy.Y = R ;
    SetConsoleCursorPosition(
    GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
void cls()
{
    pos(0,0);
    for(int j=0; j<100; j++)
        cout << string(100, ' ');
    pos(0,0);
}

class TicTacToe
{
private:
    int n;
    char **a;
    char jucator, calculator;

public:
    void AfisareTabla();

    void AfisarePozitii();

    void InstructiuniDeInceput();

    void AlegereJucator();

    int AlegereOrdine();

    void VerificarePozitiiGresite(int i, int j);

    void AsteaptaNSecunde(int secunde);


    void Muchie12(); ///Dupa PrimaMutareCalculatorMijloc
    void Muchie23(); ///Dupa PrimaMutareCalculatorMijloc
    void Muchie32(); ///Dupa PrimaMutareCalculatorMijloc
    void Muchie21(); ///Dupa PrimaMutareCalculatorMijloc

    void Colt11(); ///Dupa PrimaMutareCalculatorMijloc
    void Colt13(); ///Dupa PrimaMutareCalculatorMijloc
    void Colt33(); ///Dupa PrimaMutareCalculatorMijloc
    void Colt31(); ///Dupa PrimaMutareCalculatorMijloc

    void PrimaMutareCalculatorMijloc();


    void MIJLOC_ADouaMutareJucatorMuchie12();
    void MIJLOC_ADouaMutareJucatorMuchie23();
    void MIJLOC_ADouaMutareJucatorMuchie32();
    void MIJLOC_ADouaMutareJucatorMuchie21();

    void MIJLOC_ADouaMutareJucatorColt11();
    void MIJLOC_ADouaMutareJucatorColt13();
    void MIJLOC_ADouaMutareJucatorColt31();

    void PrimaMutareJucatorMIJLOC();


    void COLT11_ADouaMutareJucatorMuchie(int x, int y);
    void COLT11_ADouaMutareJucatorColt(int x, int y);

    void COLT13_ADouaMutareJucatorMuchie(int x, int y);
    void COLT13_ADouaMutareJucatorColt(int x, int y);

    void COLT33_ADouaMutareJucatorMuchie(int x, int y);
    void COLT33_ADouaMutareJucatorColt(int x, int y);

    void COLT31_ADouaMutareJucatorMuchie(int x, int y);
    void COLT31_ADouaMutareJucatorColt(int x, int y);

    void PrimaMutareJucatorCOLT(int x, int y);


    void MUCHIE12_ADouaMutareJucatorMuchie(int x1, int y1);
    void MUCHIE12_ADouaMutareJucatorColt(int x1, int y1);

    void MUCHIE23_ADouaMutareJucatorMuchie(int x1, int y1);
    void MUCHIE23_ADouaMutareJucatorColt(int x1, int y1);

    void MUCHIE32_ADouaMutareJucatorMuchie(int x1, int y1);
    void MUCHIE32_ADouaMutareJucatorColt(int x1, int y1);

    void MUCHIE21_ADouaMutareJucatorMuchie(int x1, int y1);
    void MUCHIE21_ADouaMutareJucatorColt(int x1, int y1);

    void PrimaMutareJucatorMUCHIE(int x1, int y1);


    /// CONSTRUCTORI
    TicTacToe(int dim) /// Initializari
    {
        n = dim;
        a = new char*[n];
        for(int i = 0; i < n; i++)
        {
            a[i] = new char[n];
            for(int j = 0; j < n; j++)
                a[i][j] = ' ';
        }

        InstructiuniDeInceput();
        AlegereJucator();
    }

    ///DESTRUCTOR
    ~TicTacToe()
    {
        for(int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
        n = 0;
    }

    /// REDEFINIREA OPERATORILOR
    friend void operator +=(TicTacToe& joculet, int nr) ///pune x si y pe tabla
    {
        int x,y;
        y = nr % 10;
        x = nr / 10;
        joculet.a[x-1][y-1] = joculet.jucator;
    }

    friend ostream& operator<<(ostream& out, TicTacToe& joculet)
    {
        out<<"\n\n";
        out<<"\t     |     |     \n";
        out<<"\t  "<<joculet.a[0][0]<<"  |  "<<joculet.a[0][1]<<"  |  "<<joculet.a[0][2]<<"\n";
        out<<"\t_____|_____|_____\n";
        out<<"\t     |     |     \n";
        out<<"\t  "<<joculet.a[1][0]<<"  |  "<<joculet.a[1][1]<<"  |  "<<joculet.a[1][2]<<"\n";
        out<<"\t_____|_____|_____\n";
        out<<"\t     |     |     \n";
        out<<"\t  "<<joculet.a[2][0]<<"  |  "<<joculet.a[2][1]<<"  |  "<<joculet.a[2][2]<<"\n";
        out<<"\t     |     |     \n\n";

        return out;
    }

};


int main()
{
    TicTacToe joc(3);

    if(joc.AlegereOrdine() == 1)
        joc.PrimaMutareCalculatorMijloc(); ///calculator muta primul
    else ///jucator muta primul
    {
        cls();
        int x,y,nr;

        cout<<joc;
        cout<<"\nCare este prima ta mutare? \n\n";
        cin>>x>>y;
        joc.VerificarePozitiiGresite(x,y);
        nr = x * 10 + y;
        joc += nr;
        cout<<joc;

        if(x == 2 && y == 2)
            joc.PrimaMutareJucatorMIJLOC();
        else if((x + y) % 2 == 0)
            joc.PrimaMutareJucatorCOLT(x,y);
        else
            joc.PrimaMutareJucatorMUCHIE(x,y);
    }

    return 0;
}

inline void TicTacToe :: AfisareTabla()
{
    cout<<"\n\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<"\n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<a[1][0]<<"  |  "<<a[1][1]<<"  |  "<<a[1][2]<<"\n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |  "<<a[2][2]<<"\n";
    cout<<"\t     |     |     \n\n";
}

inline void TicTacToe :: AfisarePozitii()
{
    cout<<"\n";
    cout<<"\t     |     |     \n";
    cout<<"\t 1 1 | 1 2 | 1 3 \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t 2 1 | 2 2 | 2 3 \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t 3 1 | 3 2 | 3 3 \n";
    cout<<"\t     |     |     \n\n";
}

inline void TicTacToe :: InstructiuniDeInceput()
{
    cout<<"\n";
    cout<<"X si O este un joc pentru doi jucatori, X respectiv O, \n";
    cout<<"care marcheaza pe rand cate o casuta dintr-un tabel cu \n";
    cout<<"3 linii si 3 coloane. Jucatorul care reuseste primul sa \n";
    cout<<"marcheze 3 casute adiacente pe orizontala, verticala \n";
    cout<<"sau diagonala castiga jocul. \n\n";

    cout<<"Asa arata tabla pe care vei juca astazi: ";
    AfisareTabla();

    cout<<"Pentru a marca un patrat, trebuie sa introduci \n";
    cout<<"pozitia corespunzatoare patratului pe care vrei\n";
    cout<<"sa il marchezi. \n";
    cout<<"Acestea sunt pozitiile patratelor tablii de joc: \n";
    AfisarePozitii();

    cout<<"De exemplu, daca introduci pozitia 2 3 \n";
    cout<<"tabla de joc va arata asa dupa marcare: ";
    a[1][2] = 'X';
    AfisareTabla();
    a[1][2] = ' ';

    cout<<"ATENTIE! Pozitiile vor fi introduse ca doua numere \n";
    cout<<"separate prin spatiu. Orice alt mod de introducere a \n";
    cout<<"datelor nu va fi luat in considerare!\n";
    cout<<"exemplu:\n";
    cout<<"2 3 sau 3 1 sau 2 1 sunt date de intrare corecte\n";
    cout<<"2,3 sau 3;1 sau 21 sunt date de intrare incorecte\n";
    cout<<" \n";

    cout<<"Sa incepem! Scrie X daca vrei sa fii juatorul care \n";
    cout<<"va folosi X sau scrie O in caz contrar. \n";
    cout<<" \n";
}

inline void TicTacToe :: AlegereJucator()
{
    /// daca pune "X asd" nu e bine ca mai citesc chestii dupa :(
    char c[2];
    cin>>c;
    if(c[1] != NULL)
    {
        cout<<"\n\nDATE DE INTRARE GRESITE!\n\n";
        exit(0);
    }
    if(c[0] == 'X' || c[0] == 'x')
    {
        jucator = 'X';
        calculator = 'O';
    }
    else if(c[0] == 'O' || c[0] == 'o' || c[0] == '0')
    {
        jucator = 'O';
        calculator = 'X';
    }
    else
    {
        cout<<"\n\nDATE DE INTRARE GRESITE!\n\n";
        exit(0);
    }
    cout<<" \n";
}

inline int TicTacToe :: AlegereOrdine()
{
    /// daca pune "DA asd" nu e bine ca mai citesc chestii dupa :(
    cout<<"Vrei sa fii primul care marcheaza? ( Raspuns: DA / NU )\n\n";
    char c[5];
    cin>>c;
    cout<<"\n";
    if(c[2] != NULL)
    {
        cout<<"\n\nDATE DE INTRARE GRESITE!\n\n";
        exit(0);
    }
    if((c[0] == 'D' || c[0] == 'd') && (c[1] == 'A' || c[1] == 'a'))
        return 0;
    else if((c[0] == 'N' || c[0] == 'n') && (c[1] == 'U' || c[1] == 'u'))
        return 1;
    else
    {
        cout<<"\n\nDATE DE INTRARE GRESITE!\n\n";
        exit(0);
    }
    return 1;
}

inline void TicTacToe :: VerificarePozitiiGresite(int i, int j)
{
    if(i < 1 || j < 1 || i > n || j > n)
    {
        cout<<"\nPatratul de la pozitia "<<i<<" "<<j<<" nu se afla pe tabla de joc!\n";
        cout<<"Pentru ca ai incercat sa fentezi sistemul vei fi penalizat cu un joc pierdut!\n";
        cout<<"Chiar daca nu ai avut intentii rele, tot esti penalizat pentru ca nu ai fost atent!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else if(a[i-1][j-1] == 'X' || a[i-1][j-1] == 'O')
    {
        cout<<"\nPatratul de la pozitia "<<i<<" "<<j<<" este deja ocupat!\n";
        cout<<"Pentru ca ai incercat sa fentezi sistemul vei fi penalizat cu un joc pierdut!\n";
        cout<<"Chiar daca nu ai avut intentii rele, tot esti penalizat pentru ca nu ai fost atent!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}

inline void TicTacToe :: AsteaptaNSecunde(int secunde)
{
    int limita;
    time_t now;
    now = time(0);
    limita = now + secunde;

    while(now < limita)
        now = time(0);
}


inline void TicTacToe :: Muchie12() ///Dupa Prima Mutare Calculator Mijloc
{
    int x,y;

    a[0][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 3 || y != 1)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[2][2] = calculator;
    cls(); AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls(); AfisareTabla();
    cout<<"\nMuta calculatorul: \n\n";

    if(x == 1 && y == 1)
    {
        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    if(x == 2 && y == 2)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    a[0][0] = calculator;
    cls(); AfisareTabla();
    cout<<"\nAi pierdut!\n\n";
    cout<<"------------------- SFARSIT JOC! -------------------";
    exit(0);
}

inline void TicTacToe :: Muchie23() ///Dupa Prima Mutare Calculator Mijloc
{
    int x,y;

    a[2][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 1 || y != 1)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[2][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x == 1 && y == 3)
    {
        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    if(x == 2 && y == 1)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    a[0][2] = calculator;
    cls(); AfisareTabla();
    cout<<"\nAi pierdut!\n\n";
    cout<<"------------------- SFARSIT JOC! -------------------";
    exit(0);
}

inline void TicTacToe :: Muchie32() ///Dupa Prima Mutare Calculator Mijloc
{
    int x,y;

    a[2][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 1 || y != 3)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[0][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x == 2 && y == 1)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    if(x == 3 && y == 3)
    {
        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    a[1][0] = calculator;
    cls(); AfisareTabla();
    cout<<"\nAi pierdut!\n\n";
    cout<<"------------------- SFARSIT JOC! -------------------";
    exit(0);
}

inline void TicTacToe :: Muchie21() ///Dupa Prima Mutare Calculator Mijloc
{
    int x,y;

    a[0][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 3 || y != 3)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[0][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x == 1 && y == 2)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    if(x == 3 && y == 1)
    {
        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    a[0][1] = calculator;
    cls(); AfisareTabla();
    cout<<"\nAi pierdut!\n\n";
    cout<<"------------------- SFARSIT JOC! -------------------";
    exit(0);
}


inline void TicTacToe :: Colt11() ///Dupa Prima Mutare Calculator Mijloc
{
    int x,y;

    a[2][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if((x + y) % 2 == 1) ///pune pe muchie
    {
        if(x == 1 && y == 2) ///sus
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 2 && y == 3)
            {
                a[2][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 3 && y == 1)
            {
                a[1][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 3 && y == 2) ///jos
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 3 && y == 1)
            {
                a[1][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 2 && y == 3)
            {
                a[2][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 2 && y == 1) ///stanga
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 1 && y == 3)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 3 && y == 2)
            {
                a[0][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 2 && y == 3) ///dreapta
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 1 && y == 3)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 3 && y == 2)
            {
                a[0][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
    }
    else ///pune pe colt
    {
        if(x == 1 && y == 3) ///dreapta sus
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 3 || y != 2)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 2 || y != 1)
            {
                a[1][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 3 && y == 1) ///stanga jos
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 2 || y != 3)
            {
                a[1][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 3 || y != 2)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
    }
}

inline void TicTacToe :: Colt13() ///Dupa Prima Mutare Calculator Mijloc
{
    int x,y;

    a[2][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if((x + y) % 2 == 1) ///pune pe muchie
    {
        if(x == 1 && y == 2) ///sus
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 2 && y == 1)
            {
                a[2][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 3 && y == 3)
            {
                a[1][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 3 && y == 2) ///jos
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 2 && y == 1)
            {
                a[2][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 3 && y == 3)
            {
                a[1][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 2 && y == 1) ///stanga
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 3 && y == 2)
            {
                a[0][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 1 && y == 1)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 2 && y == 3) ///dreapta
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 3 && y == 2)
            {
                a[0][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 1 && y == 1)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
    }
    else ///pune pe colt
    {
        if(x == 1 && y == 1) ///stanga sus
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 3 || y != 2)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 2 || y != 3)
            {
                a[1][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 3 && y == 3) ///dreapta jos
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 2 || y != 1)
            {
                a[1][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 3 || y != 2)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
    }
}

inline void TicTacToe :: Colt33() ///Dupa Prima Mutare Calculator Mijloc
{
    int x,y;

    a[0][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if((x + y) % 2 == 1) ///pune pe muchie
    {
        if(x == 1 && y == 2) ///sus
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 2 && y == 1)
            {
                a[0][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 1 && y == 3)
            {
                a[1][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 3 && y == 2) ///jos
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 2 && y == 1)
            {
                a[0][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 1 && y == 3)
            {
                a[1][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 2 && y == 1) ///stanga
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 3 && y == 1)
            {
                a[0][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 1 && y == 2)
            {
                a[2][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 2 && y == 3) ///dreapta
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 3 && y == 1)
            {
                a[0][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 1 && y == 2)
            {
                a[2][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
    }
    else ///pune pe colt
    {
        if(x == 1 && y == 3) ///dreapta sus
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 2 || y != 1)
            {
                a[1][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 3 || y != 2)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 3 && y == 1) ///stanga jos
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 1 || y != 2)
            {
                a[0][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 2 || y != 3)
            {
                a[1][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
    }
}

inline void TicTacToe :: Colt31() ///Dupa Prima Mutare Calculator Mijloc
{
    int x,y;

    a[0][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if((x + y) % 2 == 1) ///pune pe muchie
    {
        if(x == 1 && y == 2) ///sus
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 1 && y == 1)
            {
                a[1][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 2 && y == 3)
            {
                a[0][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 3 && y == 2) ///jos
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 1 && y == 1)
            {
                a[1][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 2 && y == 3)
            {
                a[0][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 2 && y == 1) ///stanga
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 1 && y == 2)
            {
                a[2][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 3 && y == 3)
            {
                a[0][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 2 && y == 3) ///dreapta
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 1 && y == 2)
            {
                a[2][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            if(x == 3 && y == 3)
            {
                a[0][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
    }
    else ///pune pe colt
    {
        if(x == 1 && y == 1) ///stanga sus
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 2 || y != 3)
            {
                a[1][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 3 || y != 2)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        if(x == 3 && y == 3) ///dreapta jos
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 1 || y != 2)
            {
                a[0][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 2 || y != 3)
            {
                a[1][2] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
    }
}


inline void TicTacToe :: PrimaMutareCalculatorMijloc()
{
    int x,y;

    a[1][1] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    ///muchii
    if(x == 1 && y == 2)
        Muchie12(); ///sus
    if(x == 2 && y == 3)
        Muchie23(); ///dreapta
    if(x == 3 && y == 2)
        Muchie32(); ///jos
    if(x == 2 && y == 1)
        Muchie21(); ///stanga

    ///colturi
    if(x == 1 && y == 1)
        Colt11(); ///stanga sus
    if(x == 1 && y == 3)
        Colt13(); ///dreapta sus
    if(x == 3 && y == 3)
        Colt33(); ///dreapta jos
    if(x == 3 && y == 1)
        Colt31(); ///stanga jos
}



inline void TicTacToe :: MIJLOC_ADouaMutareJucatorMuchie12()
{
    int x,y;

    a[2][1] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 3 || y != 1)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[0][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 2 || y != 3)
    {
        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[1][0] = calculator;
    cls(); AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls(); AfisareTabla();
    cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
    cout<<"------------------- SFARSIT JOC! -------------------";
    exit(0);
}

inline void TicTacToe :: MIJLOC_ADouaMutareJucatorMuchie23()
{
    int x,y;

    a[1][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    ///muchii:
    if(x == 1 && y == 2)
    {
        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nMuta calculatorul: \n\n";

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else if(x == 3 && y == 2)
    {
        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nMuta calculatorul: \n\n";

        if(x == 3 || y == 1)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else

        ///colturi:
        if(x == 1 && y == 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 3 || y != 2)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }

            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
        else if(x == 1 && y == 3)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x != 1 || y != 1)
            {
                a[0][0] = calculator;
                cls(); AfisareTabla();
                cout<<"\nAi pierdut!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            else
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nE randul tau! \n\n";

                cin>>x>>y;
                VerificarePozitiiGresite(x,y);
                a[x-1][y-1] = jucator;
                cls(); AfisareTabla();
                cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
        }
        else if(x == 3 && y == 1)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nMuta calculatorul: \n\n";

            if(x == 1 && y == 2)
            {
                a[2][1] = calculator;
                cls(); AfisareTabla();
                cout<<"\nE randul tau! \n\n";

                cin>>x>>y;
                VerificarePozitiiGresite(x,y);
                a[x-1][y-1] = jucator;
                cls(); AfisareTabla();
                cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
                cout<<"------------------- SFARSIT JOC! -------------------";
                exit(0);
            }
            else

                a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
}

inline void TicTacToe :: MIJLOC_ADouaMutareJucatorMuchie32()
{
    int x,y;

    a[0][1] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x == 2 && y == 1)
    {
        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nMuta calculatorul: \n\n";

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else if(x == 2 && y == 3)
    {
        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nMuta calculatorul: \n\n";

        if(x == 3 || y == 1)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x == 1 && y == 1)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nMuta calculatorul: \n\n";

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else if(x == 1 && y == 3)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nMuta calculatorul: \n\n";

        if(x == 2 && y == 3)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    else if(x == 3 && y == 1)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nMuta calculatorul: \n\n";

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
        else
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";

            cin>>x>>y;
            VerificarePozitiiGresite(x,y);
            a[x-1][y-1] = jucator;
            cls(); AfisareTabla();
            cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
    }
}

inline void TicTacToe :: MIJLOC_ADouaMutareJucatorMuchie21()
{
    int x,y;

    a[1][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 1 || y != 3)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[2][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 3 || y != 2)
    {
        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[0][1] = calculator;
    cls(); AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls(); AfisareTabla();
    cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
    cout<<"------------------- SFARSIT JOC! -------------------";
    exit(0);
}


inline void TicTacToe :: MIJLOC_ADouaMutareJucatorColt11()
{
    int x,y;

    a[0][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 2 || y != 3)
    {
        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[1][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x == 1 && y == 2)
    {
        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else if(x == 3 && y == 2)
    {
        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    {
        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}

inline void TicTacToe :: MIJLOC_ADouaMutareJucatorColt13()
{
    int x,y;

    a[2][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 3 || y != 2)
    {
        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[0][1] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x == 2 && y == 1)
    {
        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else if(x == 2 && y == 3)
    {
        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    {
        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}

inline void TicTacToe :: MIJLOC_ADouaMutareJucatorColt31()
{
    int x,y;

    a[0][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x != 2 || y != 3)
    {
        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }

    a[1][0] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if(x == 1 && y == 2)
    {
        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else if(x == 3 && y == 2)
    {
        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    {
        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}


inline void TicTacToe :: PrimaMutareJucatorMIJLOC()
{
    int x,y;

    a[2][2] = calculator;
    cls();
    AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;
    cls();
    AfisareTabla();

    if((x + y) % 2 == 1)
    {
        if(x == 1 && y == 2)
            MIJLOC_ADouaMutareJucatorMuchie12();
        if(x == 2 && y == 3)
            MIJLOC_ADouaMutareJucatorMuchie23();
        if(x == 3 && y == 2)
            MIJLOC_ADouaMutareJucatorMuchie32();
        if(x == 2 && y == 1)
            MIJLOC_ADouaMutareJucatorMuchie21();
    }
    else
    {
        if(x == 1 && y == 1)
            MIJLOC_ADouaMutareJucatorColt11();
        if(x == 1 && y == 3)
            MIJLOC_ADouaMutareJucatorColt13();
        if(x == 3 && y == 1)
            MIJLOC_ADouaMutareJucatorColt31();
    }

}


inline void TicTacToe :: COLT11_ADouaMutareJucatorMuchie(int x1, int y1)
{
    int x,y;

    if(x1 == 1 && y1 == 2)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 2 && y1 == 3)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
        }
        else
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 3 && y1 == 2)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
        }
        else
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 2 && y1 == 1)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
}

inline void TicTacToe :: COLT11_ADouaMutareJucatorColt(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1  == 3)
    {
        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1  == 3)
    {
        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1  == 1)
    {
        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}


inline void TicTacToe :: COLT13_ADouaMutareJucatorMuchie(int x1, int y1)
{
    int x,y;

    if(x1 == 1 && y1 == 2)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 2 && y1 == 3)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 3 && y1 == 2)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 2 && y1 == 1)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }

}

inline void TicTacToe :: COLT13_ADouaMutareJucatorColt(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1  == 1)
    {
        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1  == 3)
    {
        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1  == 1)
    {
        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}


inline void TicTacToe :: COLT33_ADouaMutareJucatorMuchie(int x1, int y1)
{
    int x,y;

    if(x1 == 1 && y1 == 2)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }
        else
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }


        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 2 && y1 == 3)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 3 && y1 == 2)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 2 && y1 == 1)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";
        }
        else
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
}

inline void TicTacToe :: COLT33_ADouaMutareJucatorColt(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1  == 1)
    {
        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 1 && y1  == 3)
    {
        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1  == 1)
    {
        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}


inline void TicTacToe :: COLT31_ADouaMutareJucatorMuchie(int x1, int y1)
{
    int x,y;

    if(x1 == 1 && y1 == 2)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";
        }
        else
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }


        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 2 && y1 == 3)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }
        else
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 3 && y1 == 2)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }
    if(x1 == 2 && y1 == 1)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);

    }

}

inline void TicTacToe :: COLT31_ADouaMutareJucatorColt(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1  == 1)
    {
        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1  == 3)
    {
        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 1 && y1  == 3)
    {
        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}


inline void TicTacToe :: PrimaMutareJucatorCOLT(int x1, int y1)
{
    int x,y;

    a[1][1] = calculator;
    cls(); AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;

    if(x1 == 1 && y1== 1)
    {
        if((x + y) % 2 == 1) COLT11_ADouaMutareJucatorMuchie(x,y);
        else COLT11_ADouaMutareJucatorColt(x,y);
    }
    if(x1 == 1 && y1== 3)
    {
        if((x + y) % 2 == 1) COLT13_ADouaMutareJucatorMuchie(x,y);
        else COLT13_ADouaMutareJucatorColt(x,y);
    }
    if(x1 == 3 && y1 == 3)
    {
        if((x + y) % 2 == 1) COLT33_ADouaMutareJucatorMuchie(x,y);
        else COLT33_ADouaMutareJucatorColt(x,y);
    }
    if(x1 == 3 && y1 == 1)
    {
        if((x + y) % 2 == 1) COLT31_ADouaMutareJucatorMuchie(x,y);
        else COLT31_ADouaMutareJucatorColt(x,y);
    }

}


inline void TicTacToe :: MUCHIE12_ADouaMutareJucatorMuchie(int x1, int y1)
{
    int x, y;

    if(x1 == 2 && y1 == 3)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 2)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 2 && y1 == 1)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}

inline void TicTacToe :: MUCHIE12_ADouaMutareJucatorColt(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1 == 1)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 1 && y1 == 3)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 3)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
        }
        else
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 1)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
        }
        else
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}


inline void TicTacToe :: MUCHIE23_ADouaMutareJucatorMuchie(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1 == 2)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 2)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 2 && y1 == 1)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}

inline void TicTacToe :: MUCHIE23_ADouaMutareJucatorColt(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1 == 1)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }
        else
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 1 && y1 == 3)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 3)
    {
        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 1)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
        }
        else
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}


inline void TicTacToe :: MUCHIE32_ADouaMutareJucatorMuchie(int x1, int y1)
{
    int x, y;

    if(x1 == 2 && y1 == 3)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 1 && y1 == 2)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 2 && y1 == 1)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}

inline void TicTacToe :: MUCHIE32_ADouaMutareJucatorColt(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1 == 1)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";
        }
        else
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 1 && y1 == 3)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";
        }

        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 3)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 1)
        {
            a[1][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 1)
    {
        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 1)
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 2 || y != 3)
        {
            a[1][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}


inline void TicTacToe :: MUCHIE21_ADouaMutareJucatorMuchie(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1 == 2)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 2)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 2 && y1 == 3)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 1)
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nAi pierdut!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}

inline void TicTacToe :: MUCHIE21_ADouaMutareJucatorColt(int x1, int y1)
{
    int x, y;

    if(x1 == 1 && y1 == 1)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 1 && y1 == 3)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 2)
        {
            a[2][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";
        }
        else
        {
            a[2][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 3)
    {
        a[2][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 3)
        {
            a[0][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[1][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau! \n\n";
        }
        else
        {
            a[0][0] = calculator;
            cls(); AfisareTabla();
            cout<<"\nE randul tau!\n\n";
        }

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
    else
    if(x1 == 3 && y1 == 1)
    {
        a[0][0] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 3 || y != 3)
        {
            a[2][2] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[2][1] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau! \n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;

        if(x != 1 || y != 2)
        {
            a[0][1] = calculator;
            cls(); AfisareTabla();
            cout<<"\nAi pierdut!\n\n";
            cout<<"------------------- SFARSIT JOC! -------------------";
            exit(0);
        }

        a[0][2] = calculator;
        cls(); AfisareTabla();
        cout<<"\nE randul tau!\n\n";

        cin>>x>>y;
        VerificarePozitiiGresite(x,y);
        a[x-1][y-1] = jucator;
        cls(); AfisareTabla();
        cout<<"\nEste remiza! Pana acum este cel mai bun rezulat al tau!\n\n";
        cout<<"------------------- SFARSIT JOC! -------------------";
        exit(0);
    }
}


inline void TicTacToe :: PrimaMutareJucatorMUCHIE(int x1, int y1)
{
    int x,y;

    a[1][1] = calculator;
    cls(); AfisareTabla();
    cout<<"\nE randul tau! \n\n";

    cin>>x>>y;
    VerificarePozitiiGresite(x,y);
    a[x-1][y-1] = jucator;

    if(x1 == 1 && y1== 2)
    {
        if((x + y) % 2 == 1) MUCHIE12_ADouaMutareJucatorMuchie(x,y);
        else MUCHIE12_ADouaMutareJucatorColt(x,y);
    }
    if(x1 == 2 && y1== 3)
    {
        if((x + y) % 2 == 1) MUCHIE23_ADouaMutareJucatorMuchie(x,y);
        else MUCHIE23_ADouaMutareJucatorColt(x,y);
    }
    if(x1 == 3 && y1 == 2)
    {
        if((x + y) % 2 == 1) MUCHIE32_ADouaMutareJucatorMuchie(x,y);
        else MUCHIE32_ADouaMutareJucatorColt(x,y);
    }
    if(x1 == 2 && y1 == 1)
    {
        if((x + y) % 2 == 1) MUCHIE21_ADouaMutareJucatorMuchie(x,y);
        else MUCHIE21_ADouaMutareJucatorColt(x,y);
    }
}
