#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	//Odpowiednio - zapis sumy; ilo�� wierszy; aktualnie wczytywana liczba; iteracje w petli
	int suma, wiersz, liczba = 1, i;
	
	//Znak do sprawdzenia ilo�ci wierszy w pliku
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
    	//Przej�cie na pocz�tek pliku
    	fseek(plik, 0, 0);
    
    	//Je�li suma sama w sobie przekracza ilo�� wierszy
    	//to zako�cz p�tle bo w tym przypadku dalsza cz�� nie ma sensu
    	if (suma > wiersz)
    		break;
    	
    	//"Zjadanie" kolejnych wierszy aby doj�� do tego, z kt�rego chcemy
    	//pobra� zmienn�
    	for(i = 1; i <= suma; i++)
    		fscanf(plik, "%d", &liczba);
   	
   	
   		//Je�li p�tla  wy�ej dosz�a do ostatniego wiersza to zako�cz program
    	if(feof(plik))
    		break;
    			
    	//Pobierz liczb� z aktualnego wiersza
        fscanf(plik, "%d", &liczba);
        
        
        //Dodaj pobran� liczb� do sumy
        suma += liczba;
	}
    
	fclose(plik);
	
	printf("suma = %d", suma);
	
	return 0;
}
