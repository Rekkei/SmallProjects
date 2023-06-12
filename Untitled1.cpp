#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Section {
	int SectionID; 
	char SectionName[20];   // The code in which the partition operations are written
	int employeeNumber; 
} section ;

typedef struct Personel {
	char birthDate[20]; 
	char birthPlace[20];   // The place where personal information is taken and the personnel are recorded in the system
	char gender; 
	char maritalStatus; 

} personel ;

typedef struct Communication {
	char city[20]; 
	char district[20];   // Gets contact information for registration
	char adress[30]; 
	char phone[20]; 
	char email[30]; 	
}communication ;

typedef struct Employee {
	char TC[20]; 
	int SectionID; 
	char nameSurname[30]; 
	char startDate[20];   // Writes the line of code where the staff finishes the registration part
	float wage; 
	personel k1; 
	communication i1; 	
}employee ;


void AddSection() 
{
	system("cls") ; 
	printf("Section add  \n\n") ;  // named section 
	section b1; 
	int number=0; 

	FILE * numPtr = fopen("bolumNumaralar.dat", "a+b") ; 
	while( fread (&number, sizeof(int), 1, numPtr )  != NULL  )  // The line of code that specifies the numbers of the sections
	{		
	}
	number++;
 	fwrite  (&number, sizeof(int), 1, numPtr ); 
	fclose(numPtr) ; 


	b1.SectionID= number; 	
	printf("Section name : ") ; scanf(" %[^\n]s", b1.SectionName );  // Section name 
	b1.employeeNumber= 0; 	

	FILE * ptr = fopen("bolumler.dat", "a+b") ;  // All sections
	fwrite  (&b1, sizeof(section ), 1, ptr ); 
	fclose(ptr); 
	printf("Section registration complete \n") ;  // Succesfully done

}
void SectionList () 
{
	system("cls") ; 
	printf("Section lists... \n\n") ; // Section list
	section b1; 	

	printf("%-20s%-20s%-20s\n", "Section-ID", "Section-NAME", "EMP.NUMBER" )  ; 
	FILE * ptr = fopen("Sections.dat", "r+b") ;
	while( fread  (&b1, sizeof(section ), 1, ptr ) !=NULL  ) 
	{
		printf("%-20d%-20s%-20d\n", b1.SectionID, b1.SectionName, b1.employeeNumber); 	
	}
	fclose(ptr); 	
}

void SectionEdit() 
{
	system("cls") ; 
	printf("Section edit... \n\n") ;  // Fixed section 
	section b1; 	
	int number, counter=0, result=0; 
	SectionList() ; 
	printf("Section No : ") ; scanf("%d", &number ) ; 


	FILE * ptr = fopen("Sections.dat", "r+b") ;

	while( fread  (&b1, sizeof(section ), 1, ptr ) !=NULL  ) 
	{
		if( number== b1.SectionID  ) 
		{
			printf("%-20s%-20s%-20s\n", "Section-ID", "Section-NAME", "EMP.NUMBER" )  ; 
			printf("%-20d%-20s%-20d\n", b1.SectionID, b1.SectionName, b1.employeeNumber); 
			result=1; 
			break; 			
		}				
		counter++; 
	}
	if( result==0  )
	printf("%d section number not found ! \n", number ); // If you enter the wrong section number, it will warn that the section was not found.
	else
	{
		rewind(ptr); 
		printf("Section New Name : ") ; scanf(" %[^\n]s", b1.SectionName ) ; 	// Line of code written to change section name
		fseek( ptr, (counter) * sizeof(section), 0 ) ; 
		fwrite  (&b1, sizeof(section ), 1, ptr ) ; 
		printf("Section Name Changed. \n") ; 		
	}	
	fclose(ptr); 		

}
void SectionDelete () 
{
	system("cls") ; 
	printf("Section delete... \n\n") ; // Delete section
	section b1; 	
	SectionList() ; 
	int number, result=0; 

	printf("Section No : "); scanf("%d", &number  ) ;  // Number of section 


	printf("%-20s%-20s%-20s\n", "Section-ID", "Section-AD", "EMP.SAYISI" )  ; 
	FILE * ptr = fopen("bolumler.dat", "r+b") ;
	while( fread  (&b1, sizeof(section ), 1, ptr ) !=NULL  ) 
	{
		if(  number== b1.SectionID   ) 
		{
			
			result=1; 
			break; 
		}
	}	
	if( result==0)
	{
		fclose(ptr); 
		printf("%d  numbered section not found ! \n", number ); 			
	}
	else if( b1.employeeNumber !=0 )
	{
		fclose(ptr); 
		printf(" You cannot delete %d the numbered section. There are registered employees in this section. \n", number ); 			

	}


	else
	{
		rewind(ptr); 
		FILE * yptr = fopen("yedek.dat", "w+b") ;
		while( fread  (&b1, sizeof(section ), 1, ptr ) !=NULL  ) 
		{
			if(  number != b1.SectionID ) 
			{
				fwrite  (&b1, sizeof(section ), 1, yptr ) ; 			 				 
			}
		} 
		fclose(ptr)	; 
		fclose(yptr); 

		remove("bolumler.dat"); 
		rename("yedek.dat", "bolumler.dat") ; 
		printf("Section record deleted \n") ; 		
	}

}





int SectionMenu() 
{
	int choice; 
	printf("\n\tSection Operations\n\n") ; 
	printf("\t1- Section Add  \n\n"); 
	printf("\t2- Section Edit \n\n"); 
	printf("\t3- Section Delete \n\n");    // Menu of section
	printf("\t4- Section List \n\n"); 	
	printf("\t0- Quit \n\n"); 
	printf("Your Choice : "); scanf("%d", &choice) ; 
	system("cls") ; 
	return choice; 

}



void SectionOperations() 
{
	int choice= SectionMenu(); 

	while( choice != 0)
	{
		switch(choice )
		{
			case 1: AddSection(); break; 
			case 2: SectionEdit(); break; 
			case 3: SectionDelete(); break; 
			case 4: SectionList(); break; 			
			case 0: break; 
			default : printf("Wrong choice ! \n") ;  // If you make a wrong choice, it will warn you as a wrong choice.
		}
		choice= SectionMenu(); 		

	}

	printf("You logged out... ")  ;  // Out the system



}

void SectionUpdate(int number, int score )
{
	FILE *ptr = fopen("Sectionler.dat", "r+b" ) ; 
	section b1; 
	int counter=0; 
	while( fread ( &b1, sizeof(section), 1, ptr ) != NULL  )
	{
		if( number == b1.SectionID ) 
		{
			break; 
		}
		counter++; 
	}
	rewind(ptr); 
	fseek ( ptr, (counter) * sizeof(section), 0 ) ; 
	b1.employeeNumber += score; 
	fwrite ( &b1, sizeof(section), 1, ptr ) ; 
	fclose(ptr); 
	printf("\nSection Updated \n") ; 

}


void employeeAdd() 
{
	system("cls") ; 
	printf("Employee Add  \n\n") ; 
	employee p1; 


	printf("TC             : "); scanf(" %[^\n]s", p1.TC ) ; 
	printf("Name Surname       : "); scanf(" %[^\n]s", p1.nameSurname ) ; 	// Lines of code for adding employee
	SectionList() ; 
	printf("Section No       : "); scanf(" %d", &p1.SectionID ) ; 
	printf("Start Date : "); scanf(" %[^\n]s", p1.startDate ) ; 
	printf("Wage  (TL)     : "); scanf(" %f", &p1.wage ) ; 


	system("cls"); 
	printf("Personel Informations... : \n\n"); 

	printf("Birth Date   : "); scanf(" %[^\n]s", p1.k1.birthDate ) ; 
	printf("Birth Place     : "); scanf(" %[^\n]s", p1.k1.birthPlace ) ;  // Line of code in which personal information of the personnel is written
	printf("Gender       : "); scanf(" %[^\n]s", &p1.k1.gender ) ; 
	printf("Marital Status   : "); scanf(" %[^\n]s", &p1.k1.maritalStatus ) ; 


	system("cls"); 
	printf("Comminucation Information... : \n\n"); 

	printf("City          : "); scanf(" %[^\n]s", p1.i1.city ) ; 
	printf("District           : "); scanf(" %[^\n]s", p1.i1.district ) ; 
	printf("Adress         : "); scanf(" %[^\n]s", p1.i1.adress ) ; // Line of code in which personal information of the personnel is written
	printf("Phone        : "); scanf(" %[^\n]s", p1.i1.phone ) ; 
	printf("E-Mail        : "); scanf(" %[^\n]s", p1.i1.email ) ; 

	FILE *ptr= fopen("employee.dat", "a+b") ; 
	fwrite( &p1, sizeof(employee), 1, ptr  ) ; 
	fclose(ptr); 
	printf("Employee Record Done\n") ; 
	SectionUpdate(p1.SectionID, 1); 

}

void employeeSearch() 
{
	system("cls") ; 
	printf("Employee search \n\n") ; 
	employee p1; 
	int result=0; 	
	char tc[20]; 
	printf("TC             : "); scanf(" %[^\n]s", tc ) ; 



	FILE *ptr= fopen("employee.dat", "r+b") ; 
	while( fread ( &p1, sizeof(employee), 1, ptr  )  != NULL  )
	{
		if( strcmp( tc, p1.TC ) == 0  )
		{			
			result=1; 
			break; 			
		}
	}		
	fclose(ptr); 
	if( result==0 )
	printf("Employee record with %s TC number could not be found ! \n", tc ); 
	else
	{
		system("cls"); 
		printf("%-20s%-20s%-30s%-20s%-20s\n", "TC", "Section-ID", "NAME-SURNAME", "START-DATE", "WAGE (TL)" ) ; 
		printf("%-20s%-20d%-30s%-20s%.2f\n", p1.TC, p1.SectionID, p1.nameSurname, p1.startDate, p1.wage ); 

		printf("\nPersonel Informations : \n"); 
		printf("Birth Date : %s \n", p1.k1.birthDate ) ; 
		printf("Birth Place  : %s\n", p1.k1.birthPlace ) ; 
		printf("Gender    : %c\n", p1.k1.gender ) ; 
		printf("Marital Status : %c\n", p1.k1.maritalStatus ) ; 

		printf("\nILETISIM BILGILER : \n"); 
		printf("City       : %s\n", p1.i1.city ) ; 
		printf("District        : %s\n", p1.i1.district ) ; 
		printf("Adress       : %s\n", p1.i1.adress ) ; 
		printf("Phone     : %s\n", p1.i1.phone ) ; 
		printf("E-Mail     : %s\n", p1.i1.email ) ; 

	}	

}

void employeeDelete () 
{
	system("cls") ; 
	printf("Employee delete \n\n") ; 
	employee p1; 
	int result=0; 	
	char tc[20]; 
	printf("TC             : "); scanf(" %[^\n]s", tc ) ; 


	FILE *ptr= fopen("personel.dat", "r+b") ; 
	while( fread ( &p1, sizeof(employee), 1, ptr  )  != NULL  )
	{
		if( strcmp( tc, p1.TC ) == 0  )
		{			
			result=1; 
			break; 			
		}
	}		

	if( result==0 )
	{
		fclose(ptr); 
		printf("Employee record with %s TC number could not be found ! \n", tc ); 

	}

	else
	{
		rewind(ptr) ; 		

		system("cls"); 
		printf("%-20s%-20s%-30s%-20s%-20s\n", "TC", "Section-ID", "NAME-SURNAME", "START-DATE", "WAGE (TL)" ) ; 
		printf("%-20s%-20d%-30s%-20s%.2f\n", p1.TC, p1.SectionID, p1.nameSurname, p1.startDate, p1.wage ); 

		char preference; 
		printf("Do you want %s numbered employee ? [e] : ", p1.nameSurname ); scanf(" %c", &preference ); 


		FILE *yPtr= fopen("yedek.dat", "w+b") ; 

		if( preference=='e' || preference =='E') 
		{
			while( fread ( &p1, sizeof(employee), 1, ptr  )  != NULL  )
			{
				if( strcmp( tc, p1.TC ) != 0  )
				{			
					 fwrite( &p1, sizeof(employee), 1, yPtr ) ; 					 	
				}
			}

			fclose(ptr); 
			fclose(yPtr) ; 

			remove("employee.dat") ; 
			rename("yedek.dat", "employee.dat") ; 
			printf("Deletion done \n")	 ; 
			SectionUpdate(p1.SectionID, -1) ; 
		}
		else
		printf("Deletion canceled \n") ; 	

	}	

	fclose(ptr); 

}

void employeeList() 
{
	system("cls") ; 
	printf("Employee list \n\n") ; 
	employee p1; 
	int number ; 	
	SectionList() ; 	

	printf("Section No  : "); scanf(" %d", &number  ) ; 


	FILE *ptr= fopen("employee.dat", "r+b") ; 

	printf("%-20s%-20s%-30s%-20s%-20s\n", "TC", "Section-ID", "NAME-SURNAME", "START-DATE", "WAGE (TL)" ) ; 	
	while( fread ( &p1, sizeof(employee), 1, ptr  )  != NULL  )
	{
		if(  number == p1.SectionID   )
		{			

		 printf("%-20s%-20d%-30s%-20s%.2f\n", p1.TC, p1.SectionID, p1.nameSurname, p1.startDate, p1.wage ); 

		}

	}		
	fclose(ptr);  

}

void employeeWageUpdate() 
{
	 system("cls") ; 
	printf("Employee wage update \n\n") ; 
	employee p1; 
	int result=0, counter=0; 
	char tc[20]; 

	printf("TC    : "); scanf(" %[^\n]s", tc  ) ; 


	FILE *ptr= fopen("employee.dat", "r+b") ; 

	while( fread ( &p1, sizeof(employee), 1, ptr  )  != NULL  )
	{
		if(  strcmp( tc, p1.TC ) ==0  )
		{			
		 result= 1; 
		 break; 			 	
		}
		counter++; 
	}		

	if( result==0)
	{
		printf("%s numbered employee not found \n", tc ) ; 		
	}
	else
	{ 
		rewind(ptr) ; 
		printf("%-20s%-20s%-30s%-20s%-20s\n", "TC", "Section-ID", "NAME-SURNAME", "START-DATE", "WAGE (TL)" ) ; 							 
		 printf("%-20s%-20d%-30s%-20s%.2f\n", p1.TC, p1.SectionID, p1.nameSurname, p1.startDate, p1.wage ); 

		 printf("Yeni Maas  (TL)  : ") ; scanf("%f", &p1.wage ); 

		 fseek( ptr, (counter) *sizeof(employee), 0 ) ; 
		 fwrite ( &p1, sizeof(employee), 1, ptr  )  ; 
		 printf("Maas guncellendi \n") ; 	 

	}	
	fclose(ptr);  	

}

void employeeSectionChange()  
{
	system("cls") ; 
	printf("Employee Section Change \n\n") ; 
	employee p1; 
	int result=0, counter=0; 
	char tc[20]; 

	printf("TC    : "); scanf(" %[^\n]s", tc  ) ; 


	FILE *ptr= fopen("employee.dat", "r+b") ; 

	while( fread ( &p1, sizeof(employee), 1, ptr  )  != NULL  )
	{
		if(  strcmp( tc, p1.TC ) ==0  )
		{			
		 result= 1; 
		 break; 			 	
		}
		counter++; 
	}		

	if( result==0)
	{
		printf("%s numbered employee not found \n", tc ) ; 		
	}
	else
	{ 
		rewind(ptr) ; 

		printf("%-20s%-20s%-30s%-20s%-20s\n", "TC", "Section-ID", "NAME-SURNAME", "START-DATE", "WAGE (TL)" ) ; 							 
		 printf("%-20s%-20d%-30s%-20s%.2f\n", p1.TC, p1.SectionID, p1.nameSurname, p1.startDate, p1.wage ); 

		 int oldSectionNo= p1.SectionID; 		 
		 SectionList() ; 	

		 printf("New Section  No : ") ; scanf("%d", &p1.SectionID );  		 		 
		 fseek( ptr, (counter) *sizeof(employee), 0 ) ; 
		 fwrite ( &p1, sizeof(employee), 1, ptr  )  ; 
		 printf("Section changed  \n") ; 	 	

		 SectionUpdate( oldSectionNo , -1)    ; 
		 SectionUpdate( p1.SectionID, 1 )    ; 




	}	
	fclose(ptr);  	





}



int employeeMenu() 
{
	int choice; 
	printf("\n\temployee Operations\n\n") ; 
	printf("\t1- Employee Add  \n\n"); 
	printf("\t2- Employee Search  \n\n"); 
	printf("\t3- Employee Delete  \n\n"); 
	printf("\t4- Employee List  \n\n"); 
	printf("\t5- Employee Wage Update  \n\n"); 
	printf("\t6- Employee Sectionunu Change  \n\n"); 


	printf("\t0- Quit \n\n"); 
	printf("Your choice : "); scanf("%d", &choice) ; 
	system("cls") ; 
	return choice; 

}





void employeeOperations() 
{

	int choice= employeeMenu(); 

	while( choice != 0)
	{
		switch(choice )
		{
			case 1: employeeAdd(); break; 
			case 2: employeeSearch(); break; 
			case 3: employeeDelete(); break; 
			case 4: employeeList(); break; 
			case 5: employeeWageUpdate(); break; 
			case 6: employeeSectionChange(); break; 
			case 0: break; 
			default : printf("Wrong choice! \n") ; 
		}
		choice= employeeMenu(); 		

	}

	printf("You logged out... ")  ; 





}

int menu() 
{
	int choice; 
	printf("\n\nCOMPANY EMPLOYEE ORGANIZATIONAL AUTOMATION \n\n") ; 
	printf("\t1- CHOICE OPERATIONS \n\n"); 
	printf("\t2- EMPLOYEE OPERATIONS \n\n"); 
	printf("\t0- CLOSE THE PROGRAM \n\n"); 
	printf("Your choice : "); scanf("%d", &choice) ; 
	system("cls") ; 
	return choice; 

}



int main() 
{
	int choice= menu(); 

	while( choice != 0)
	{
		switch(choice )
		{
			case 1: SectionOperations(); break; 
			case 2: employeeOperations(); break; 
			case 0: break; 
			default : printf("Wrong choice ! \n") ; 
		}
		choice= menu(); 		

	}

	printf("You have closed the program... ")  ; 


	return 0; 
}