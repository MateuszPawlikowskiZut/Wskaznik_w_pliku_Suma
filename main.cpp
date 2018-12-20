#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	//Odpowiednio - zapis sumy; iloœæ wierszy; aktualnie wczytywana liczba; iteracje w petli
	int suma, wiersz, liczba = 1, i;
	
	//Znak do sprawdzenia iloœci wierszy w pliku
	char znak;
	
	//Wczytanie pliku do wskaznika typu FILE
	FILE *plik = fopen("we.txt", "r");
	
	//Zliczanie ilosci wierszy w pliku
    while((znak = getc(plik)) != EOF)
    {
        if(znak == '\n')
          ++wiersz;
    }
    
    wiersz++;
    
    
    while(liczba != 0)
    {
    	//Przejœcie na pocz¹tek pliku
    	fseek(plik, 0, 0);
    
    	//Jeœli suma sama w sobie przekracza iloœæ wierszy
    	//to zakoñcz pêtle bo w tym przypadku dalsza czêœæ nie ma sensu
    	if (suma > wiersz)
    		break;
    	
    	//"Zjadanie" kolejnych wierszy aby dojœæ do tego, z którego chcemy
    	//pobraæ zmienn¹
    	for(i = 1; i <= suma; i++)
    		fscanf(plik, "%d", &liczba);
   	
   	
   		//Jeœli pêtla  wy¿ej dosz³a do ostatniego wiersza to zakoñcz program
    	if(feof(plik))
    		break;
    			
    	//Pobierz liczbê z aktualnego wiersza
        fscanf(plik, "%d", &liczba);
        
        
        //Dodaj pobran¹ liczbê do sumy
        suma += liczba;
	}
    
	fclose(plik);
	
	printf("suma = %d", suma);
	
	return 0;
}
