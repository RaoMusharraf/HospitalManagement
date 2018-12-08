#include <stdio.h>
#include <stdlib.h>
void show()	;
void inf()	;
void med()  ;
void time() ;
void total();
void delet();
void table();
void remo();
void newd();
int main() 
{
	int i,n,w,mom;
	for(i=0;i!=-1;i++)
	{
		system("CLS");
		printf("\n     To enter new patient:<---------------Press n------>\n");
		printf("     For patient information:<------------Press i------>\n");
		printf("     For patient Medician:<---------------Press m------>\n");
		printf("     For Doctor Time table:<--------------Press t------>\n");
		printf("     Total charges of patient:<-----------Press o------>\n");
		printf("     Delete record of the patient:<-------Press d------>\n");
		printf("     >> ");
		scanf(" %c",&n);
		switch(n)
		{
		    case 'n':
		    inf();
		    break;
		    case 'i':
		    show();
		    break;
		    case 'm':
		    med();
		    break;
		    case 't':
		    time();
		    break;
		    case 'o':
		    total();
			break;
			case 'd':
			delet();	
			break;	
		    default: 
		    printf("\n     PRESS ONLY <------n--i--m--t--o--d------>\n");
		    printf("\n     Enter Any Digit OR Ctrl+Z for End \n");
			printf("\n     %s", "? " );
            scanf( "%d", &mom);   
		    break;
	    }								
	}
}	
void inf()	
			{
				system("CLS");
            	unsigned int a,b,z,r,p,mom;
                char e[30],f[30],d[30],g[30],m[30];
                FILE *cfPtr;
                if((cfPtr=fopen("hospitalm.txt", "a" ))==NULL)
                {
	                puts("File could not be opened");
                }
                else 
				{
			    	puts( "\n     Information of the Patient\n" );
                    while (!feof( stdin) )
			    	{
                        printf( "     Name of the Patient:  " );
                        fflush(stdin);
                        gets(e) ;
                        printf("     Age of the patient:  ");
                        scanf("%d",&a);
                        printf( "     Father Name of the Patient:  " );
                        fflush(stdin);
                        gets(f) ;
                        printf( "     Bed No of the patient:  " );
                        scanf( "%d",&b);
				        printf( "     Disease of the Patient:  " );
                        fflush(stdin);
                        gets(d) ;
			        	printf( "     Gender of the Patient:  " );
                        fflush(stdin);
                        gets(g) ; 
			        	printf( "     Doctor Fee:  " );
                        scanf( "%d",&r);
                        fprintf( cfPtr, "%29s %d %29s %d %29s %29s %d\n",e,a,f,b,d,g,r);
                        printf("\n     Enter ctrl+z for end OR 1,2,3... to new patient\n\n");
				        printf( "     %s", "? " );
                        scanf( "%d", &mom);
                    }
					fclose( cfPtr ); 
                }
            }
void show()			
            {
                system("CLS");
            	unsigned int a,b,z,r,p,mom,non_bed;
                char e[30],f[30],d[30],g[30],m[30];
				FILE *cfptr;
                if((cfptr=fopen("hospitalm.txt", "rb+" ))==NULL)
                {
	                puts("     File could not be opened");
                }
                else
                {
                    printf("\n     Enter Bed No: ");
                    scanf("%d",&z);
                	non_bed = 1;                
	                while(!feof(cfptr))
            	    {
               	        fscanf(cfptr, "%29s%d%29s%d%29s%29s%d\n",e,&a,f,&b,d,g,&r);
		                if(b==z)
	                    {
	                        non_bed = 0;
		                    printf("\n       Name  =  %s\n",e);
		                    printf("        Age  =  %d\n",a); 
		                    printf("     F_Nane  =  %s\n",f);
		                    printf("     Bed_No  =  %d\n",b);
		                    printf("     Disease =  %s\n",d);
		                    printf("     Gender  =  %s\n",g);
		                    printf("     Charges =  %d\n\n",r);
		                    break;
    	                }
                    }
				    if (non_bed==1)
			    	{
    	                printf("\n     Bed no: %d don't have any patient!\n", z);
				    }
				    printf("\n     Enter ctrl+z for end OR 1,2,3\n\n");
					printf( "\n     %s", "? " );
                    scanf( "%d", &mom);	
	                fclose( cfptr );
                }               
		    }
void med()
			{
				system("CLS");
				unsigned int p,b,mom;
				char m[30];
                FILE *cfpt;
                if ( (cfpt = fopen( "Medicin.txt", "a" ) ) == NULL ) 
				{
                    puts( "File could not be opened" );
			    }
			    else
			    {
	                while(!feof(stdin))
			        {
			            printf("\n     Patient Bed_NO =  ");
			            scanf("%d",&m);			        
			            printf("     Medician Name  =  ");
			            fflush(stdin);
                        gets(m) ;
			            printf("     Medician Price =  ");
			            scanf("%d",&p);
			            fprintf( cfpt, "%d %29s %d \n",b,m,p);
                        printf("\n     Enter ctrl+z for end OR 1,2,3... to new patient\n\n");
				        printf( "     %s", "? " );
                        scanf( "%d", &mom);			            
	                }	
                    fclose( cfpt ); 
                }
            }
void time()
		    {
		        system("CLS");
				char o[30],f[30],r[5];
				unsigned int s,d,h,m,a,z,mom,stop=0,i;
				
				for(i=0;i!=-1;i++)
				{
					system("CLS");
				    printf("\n\n     To Enter New Doctor T_Table <----------Press 2-------->\n");
				    printf("     For One Doctor Time Table   <--------- Press 3-------->\n");
				    printf("     Remove Doctor Time Table   <---------- Press 4-------->\n");
				    printf("     >> ");
				    scanf(" %d",&s);
				    if(s > 1 && s <= 4)
					{
                    switch(s)
                    {
                    	case 2:
                    		newd();
                    		break;
                    	case 3:
						    table();
							break;
						case 4:
						    remo();
							break;
						}
				   	}
				   	else{
				   			printf("\n     Press Only <2---3---4--->\n");
							printf("\n     Enter Any Digit OR Ctrl+Z for End \n");
		                	printf("\n     %s", "? " );
                            scanf( "%d", &mom);   
						    break;
					   }
				   }
			}
				void newd()	
					{
						char o[30],f[30],r[5];
			        	unsigned int s,d,h,m,a,z,mom,stop=0,i;
                        FILE *cfp;	
	                    if((cfp=fopen("Doctor.txt", "a" ))==NULL)
                        {
	                        puts("File could not be opened");
                        }
                        else
                        {
                            while (!feof( stdin) )
						    {
				                printf("     Doctor Name: ");
					            fflush(stdin);
                                gets(o) ;
					            printf("     Doctor ID  : ");
					            scanf("%d",&d);
				            	printf("     Doctor Age: ");
				            	scanf("%d",&a);
				                printf("     Gender : ");
				            	fflush(stdin);
                                gets(f) ;
				            	printf("     Doctor Time Hour: ");
				            	scanf("%d",&h);
				            	printf("     Doctor Time Min : ");
				            	scanf("%d",&m);	
					            printf("     AM OR PM : ");
					            fflush(stdin);
                                gets(r) ;				
					            fprintf(cfp,"%29s %d %d %29s %d %d %4s\n",o,d,a,f,h,m,r);
					            printf("\n     Enter ctrl+z for end OR 1,2,3... to new Doctor\n\n");
			                    printf( "     %s", "? " );
                                scanf( "%d", &mom);					
					        }
				    	    fclose(cfp);
				        }
		         	}
				void table()
					{
					    char o[30],f[30],r[5];
			         	unsigned int s,d,h,m,a,z,mom,stop=0,i;								
				    	FILE *read;
                        if((read=fopen("Doctor.txt", "r" ))==NULL)
                        {
	                        puts("File could not be opened");
                        }
                        else
					    {
				            printf("     Write Doctor ID = ");
					        scanf("%d",&z);	
	                        while(!feof(read))
                	        {
                	            fscanf(read,"%29s %d %d %29s %d %d %4s",o,&d,&a,f,&h,&m,r);
                	            if(d==z)
	                            {
	                        	    stop=1;
		                            printf("\n        D_Name  =  %s\n",o);
		                            printf("     Doctor ID  =  %d\n",d);
		                            printf("           Age  =  %d\n",a);
								    printf("        Gender  =  %s\n",f); 
		                            printf("       D_Timing =  %d:%d %s\n",h,m,r);
    	                            break;		                    
    	                        }
							}
    	                    if (stop==0)
							{
    	                        printf("\n     This ID: %d Don't Match With Doctor ID!\n", z);
			            	}
			            	printf("\n     Enter ctrl+z for End \n");
							printf( "\n     %s", "? " );
                            scanf( "%d", &mom);
							fclose( read );
					    }
				    }
				void remo()	
				    {
				    	char o[30],f[30],r[5];
			        	unsigned int s,d,h,m,a,z,mom,stop=0,i;
			        	int ruk=0;
				    	system ("CLS");
                        FILE *cfr,*cr;
                        if((cfr=fopen("Doctor.txt", "r" ))==NULL)
                        {
		                    puts("File could not be opened");
	                    }
                        else
                        {
                          	printf("     Doctor ID: ");
            	            scanf("%d",&z);
	                        while(!feof(cfr))
        	                {
	        	                fscanf(cfr,"%29s %d %d %29s %d %d %4s",o,&d,&a,f,&h,&m,r);
		                        if(d==z)
			                   	{
			                   	    ruk=1;
				                    if(!feof(cfr))
			                    	{
		                                printf("\n        D_Name  =  %s\n",o);
		                                printf("     Doctor ID  =  %d\n",d);
		                                printf("           Age  =  %d\n",a);
								        printf("        Gender  =  %s\n",f); 
		                                printf("       D_Timing =  %d:%d %s\n",h,m,r);
		                                printf("\n     Record Of Doctor <%s> Has Been Delete\n",o);
	                                }
								}
                                else
		                     	{
		                            if((cr=fopen("hosp.txt","a"))==NULL)
				                    {
	                                    puts("File could not be opened");
		                            }
            	                    else
				                    {
		                                if(!feof(cfr))
				                 	    {
    		                                fprintf(cr,"%29s %d %d %29s %d %d %4s\n",o,d,a,f,h,m,r);
		                                }
	                                }
	                                fclose(cr);
                                }
                            }  
                                fclose(cfr);
                        }
                        remove("Doctor.txt");
                        rename("hosp.txt","Doctor.txt");
				    	if(ruk==0)
			        	{
    		    	    	printf("\n     Doctor of ID: %d Not Exist\n",z);
					    }
					    printf("\n     Enter Any Digit OR Ctrl+Z for End \n");
						printf( "\n     %s", "? " );
                        scanf( "%d", &mom);
			    	}
void total()
		    {
                system("CLS");
            	unsigned int a,b,i,z,r,p,mom,non_bed,sum=0;
                char e[30],f[30],d[30],g[30],m[30];
                for(i=0;i!=-1;i++)
				{
                    printf("\n     Enter Beb No: ");
                    scanf("%d",&z);                	
				    FILE *cfptr;
                    if((cfptr=fopen("hospitalm.txt", "r" ))==NULL)
                    {
	                    puts("     File could not be opened");
                    }
                    else
                    {
            	        non_bed = 1;                
	                    while(!feof(cfptr))
            	        {
            	            fscanf(cfptr, "%29s%d%29s%d%29s%29s%d",e,&a,f,&b,d,g,&r);
		                    if(b==z)
	                        {
	                            non_bed = 0;
		                        printf("\n             Name  =  %s\n",e);
		                        printf("     Admition Fee  =  %d\n",r);
		                        break;
    	                    }
                        }
				        if (non_bed==1)
				        {
    	                    printf("\n     Bed no: %d don't have any patient!", z);
				        }	
	                    fclose( cfptr );
				        FILE *cftr;
                        if((cftr=fopen("Medicin.txt", "r" ))==NULL)
                        {
	                        puts("     File could not be opened");
                        }
                        else
                        {
				            non_bed = 0;               
	                        while(!feof(cftr))
            	            {
				                for(i=0;i<=25;i++)
							    {	
            	                    fscanf(cftr, "%d %29s %d \n",&b,m,&p);
            	                    if(b==z)
	                                {
	            	                    non_bed = 1;
		                                printf("     Medicin Name  =  %s\n",m);
		                                printf("     Medicin Price =  %d\n\n",p);
					                    sum+=p;	
    	                            }
    	                            break; 
                                }
				            }	
				            if (non_bed==0)
				            {
    	                        printf("\n     Bed no: %d don't take any medicin!\n\n", z);
				            }
				            else{
				            	printf("     Total price = %d\n",sum+r);
							}
                            fclose(cftr);
		                } 
				    }
					printf("\n     Enter Any Digit OR Ctrl+Z for End \n");
					printf( "\n     %s", "? " );
                    scanf( "%d", &mom);             
		            break;
			    }
		    }
void delet()
        {	
            system ("CLS");
            unsigned int b=0;
            unsigned int z,r,a,mom,p,i;
            unsigned int stop=1;
            char e[30],f[30],d[30],g[30],m[30];
            for(i=0;i<=-1;i++)
            {
            FILE *cfptr,*ctr;
            if((cfptr=fopen("hospitalm.txt", "r" ))==NULL)
            {
		        puts("File could not be opened");
	        }
            else
            {
            	printf("     Enter Bed No: ");
            	scanf("%d",&z);
	            while(!feof(cfptr))
        	    {
	            	fscanf(cfptr, "%29s%d%29s%d%29s%29s%d",e,&a,f,&b,d,g,&r);
		            if(b==z)
			    	{
			        	stop=0;
			        	if(!feof(cfptr))
			        	{
		                    printf("         Name=%s\n",e);
	        	            printf("          Age=%d\n",a);
	                    	printf("       F_nane=%s\n",f);
		                    printf("       Bed_no=%d\n",b);
		                    printf("      Disease=%s\n",d);
		                    printf("       Gender=%s\n",g);
		                    printf("      Charges=%d\n\n",r);
	                    }
	                }
                    else
		        	{
		                if((ctr=fopen("hospita.txt","a"))==NULL)
				        {
	                        puts("File could not be opened");
		                }
            	        else
				        {
		                    if(!feof(cfptr))
					        {
    		                    fprintf(ctr, "%29s %d %29s %d %29s %29s %d\n",e,a,f,b,d,g,r);
		                    }
	                    }
	                    fclose(ctr);
                    }
                }
                fclose(cfptr);
            }
            remove("hospitalm.txt");
            rename("hospita.txt","hospitalm.txt");
            FILE *cftr,*med;
            if((cftr=fopen("Medicin.txt", "r" ))==NULL)
            {
		        puts("File could not be opened");
	        }
            else
            {
            	
	            while(!feof(cftr))
        	    {	
	            	fscanf(cftr, "%d %29s %d\n",&b,m,&p);
		            if(b==z)
				    {
		                printf("     Medicin Name  =  %s\n",m);
		                printf("     Medicin Price =  %d\n\n",p);
	                }
                    else
		   	        {
		                if((med=fopen("hos.txt","a"))==NULL)
				        {
	                        puts("File could not be opened");
		                }
            	        else
				        {
    		                fprintf(med, "%d %29s %d \n",b,m,p);
	                    }
	                    fclose(med);
                    }
                }
                printf("\n     Patient of Bed No:%d has been Discharged\n\n",z);
                fclose(cftr);
            }
            remove("Medicin.txt");
            rename("hos.txt","Medicin.txt");
            if(stop==1)
            {
            	printf("\n     Patient of Bed No:%d already has been Discharged\n\n",z);
			}
			printf("\n     Enter Any Digit OR Ctrl+Z for End \n");
			printf( "\n     %s", "? " );
            scanf( "%d", &mom); 
			break;
			}
        }


