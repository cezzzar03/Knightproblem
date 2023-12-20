/*Circuitul calului: Se dă o tablă de șah de N x N elemente pe care se află un cal la coordonatele
(i,j). Se cere să se scrie un program care determină mutările calului (respectând săritura calului
din jocul de șah) astfel încât toate pozițiile tablei să fie acoperite.
*/
#include<iostream>
#include<iomanip>
using namespace std;

//mutarile pe care le poate face calul pe tabla
int mutare_x[8]={2,1,-1,-2,-2,-1,1,2};
int mutare_y[8]={1,2,2,1,-1,-2,-2,-1};

//functie pentru afisarea matricei(tablei)
void afisare_matrice(int solutie[8][8])
{
    int rand=0,coloana=0;

    for(rand=0;rand<8;rand++)
        {
           for(coloana=0;coloana<8;coloana++)     
            {
                cout<<" "<<setw(2)<<solutie[rand][coloana]<<" ";
            }
            cout<<endl;
        }

}

//functie pentru a vedea daca o miscare este buna
bool miscare_valida(int solutie[8][8],int pozx,int pozy)
{
    return (solutie[pozx][pozy]==-1 && pozx>=0 && pozx<8 && pozy>=0 && pozy<8);
}

//functie care efectueaza pasii si ne rezolva problema
bool rezolvare(int solutie[8][8],int pozx,int pozy,int contor_mutare)
{
    if(contor_mutare==64)
    {
        cout<<"\nFelicitari! Am parcurs toata tabla.\n"<<endl;
        afisare_matrice(solutie);
        return 1;
    }
    else
    {
        for(int mutare=0;mutare<8;mutare++)
        {
            if(miscare_valida(solutie,pozx+mutare_x[mutare],pozy+mutare_y[mutare]))
            {   
                solutie[pozx+mutare_x[mutare]][pozy+mutare_y[mutare]]=contor_mutare;
                if(rezolvare(solutie,pozx+mutare_x[mutare],pozy+mutare_y[mutare],contor_mutare+1))
                {
                return 1;
                }
                else
                {
                    solutie[pozx+mutare_x[mutare]][pozy+mutare_y[mutare]]=-1;
                }
            }
        }
        return 0;
    }

}

int main()
{
    int solutie[8][8];
    int pozx=0,pozy=0;
    int rand=0,coloana=0;
    
    //initializam matricea(tabla) cu -1 pentru a vedea locurile libere
    for(rand=0;rand<8;rand++)
    {
        for(coloana=0;coloana<8;coloana++)
        {
            solutie[rand][coloana]=-1;
        }
    }

    int contor_mutare=1;
    solutie[0][0]=0;

    rezolvare(solutie,pozx,pozy,contor_mutare);

    return 0;
}