//Nie potrafiłem zrobić odszyfrowania szyfru cezara bez podania klucza, którym tekst został zaszyfrowany.
//Działa, ale przy uruchamianiu programu trzeba podać zaszyfrowany tekst i klucz, którym został zaszyfrowany
#include <iostream>
#include <string>
#include <functional>

using namespace std;

void cezar(string &zdanie, int k){
    for(int i=0;i<=zdanie.length();i++){
if(zdanie[i]>=65 && zdanie[i]<=90-k) zdanie[i]=int(zdanie[i])+k; 
else if(zdanie[i]>=91-k && zdanie[i]<=90) zdanie[i]=int(zdanie[i])-26+k; 
else if(zdanie[i]>=97 && zdanie[i]<=122-k) zdanie[i]=int(zdanie[i])+k; 
else if(zdanie[i]>=123-k && zdanie[i]<=122) zdanie[i]=int(zdanie[i])-26+k; 
}
}

int main()
{
    cout << "Wprowadz zdanie: " << endl;
    unsigned i;
    int typ;
    string zdanie;
    getline(cin, zdanie);
    cout << "Twoje zdanie: " << zdanie << endl;
    
    start:
    cout << "Wybierz funkcje szyfrujaca(Wpisz 1 dla szyfru cezara, 2 dla szyfru przestawieniowego, 3 dla szyfru cezara i przestawieniowego, 4 dla odszyfrowania): " << endl;
    int szyfr;
    int klucz;
    cin>>szyfr;
    
    switch(szyfr)
    {
        case 1:
            cout<<"Podaj klucz z przedziału [-26..26]: ";
	        cin>>klucz;
	        cezar(zdanie, klucz);
	        cout << zdanie << endl;
	        break;
        
        case 2:
            for( i = 0; i < zdanie.length( ) - 1; i += 2 )
              swap ( zdanie [ i ], zdanie [ i + 1 ] );
            
            cout << zdanie << endl;
            break;
        
        case 3:
            cout<<"Podaj klucz z przedziału [-26..26]: ";
	        cin>>klucz;
	        cezar(zdanie, klucz);
	        
            for( i = 0; i < zdanie.length( ) - 1; i += 2 )
                swap ( zdanie [ i ], zdanie [ i + 1 ] );
            
            cout << zdanie << endl;
            break;
            
        case 4:
            cout<<"W jaki sposób zaszyfrowany jest tekst?(Wprowadz 1 dla szyfru cezara, 2 dla szyfru przestawieniowego, 3 dla tekstu zaszyfrowanego dwoma szyframi): " << endl;
            cin>>typ;
            break;
        default:
            goto start;
            break;
    }
        switch(typ)
    {
        case 1:
            cout<<"Podaj klucz, którym zaszyfrowany jest tekst: " <<endl;
            cin>>klucz;
            klucz=negate<int>()(klucz); //aby odszyfrować szyfr cezara podajemy liczbę przeciwną dla klucza, którym został zaszyfrowany
            cezar(zdanie, klucz);
            cout << zdanie << endl;
            break;
            
        case 2:
            for( i = 0; i < zdanie.length( ) - 1; i += 2 )
                swap ( zdanie [ i ], zdanie [ i + 1 ] );
            cout << zdanie << endl;
            break;
        
        case 3:
            for( i = 0; i < zdanie.length( ) - 1; i += 2 )
                swap ( zdanie [ i ], zdanie [ i + 1 ] );
            cout<<"Podaj klucz, którym zaszyfrowany jest tekst: " <<endl;
            cin>>klucz;
            klucz=negate<int>()(klucz); //aby odszyfrować szyfr cezara podajemy liczbę przeciwną dla klucza, którym został zaszyfrowany
            cezar(zdanie, klucz);
            cout << zdanie << endl;
            break;
    }
        
    }

