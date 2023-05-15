#include<stdio.h>
#include<string.h>
#include<stdlib.h>




	struct file{
		char fileName[15][20];
		char dirName[10];
		int fno;

	};



	struct file dir[10];
	int i,n;	

	//FUNCTION TO INSERT A FILE INTO DIRECTORY i
	void InsertFile(int i){
		printf("n Enter the File name ");
		scanf("%s",dir[i].fileName[dir[i].fno]);	
		dir[i].fno++;
	}


	//FUNCTION TO DISPLAY ALL FILES AND DIRECTORIES
	void DisplayFiles(){
		int j;
		printf("nnnn");	
		printf("+------------------------+");
		printf("n Directorytfiles    | n");
		printf("+------------------------+");
		for(j=0;j<n;j++){
			printf("n %s",dir[j].dirName);
			for(i=0;i<dir[j].fno;i++){
				printf("n tt%s",dir[j].fileName[i]);

			}
			printf("n+------------------------+");
		}
		printf("nnnn");

	}



//FUNCTION TO DELETE A FILE FROM DIRECTORY 
	void DeleteFile(int z){
		char name[20];
		printf("n Enter the file to be deleted : ");
		scanf("%s",name);
		for(i=0;i<dir[z].fno;i++){
			if(strcmp(dir[z].fileName[i],name)==0){
				printf("%s is deleted t",dir[z].fileName[i]);
				strcpy(dir[z].fileName[i],dir[z].fileName[dir[z].fno-1]);
				dir[z].fno--;
			}	
		}
	}	



//FUNCTION TO SEARCH FOR A FILE	
	void SearchFile(int z){
		char name[20];
		int found=-1;
		printf("n Enter the file to be searched :");
		scanf("%s",name);
		for(i=0;i<dir[z].fno;i++){
			if(strcmp(dir[z].fileName[i],name)==0){
				printf("n The File is found at position %dn",i+1);
				found=1;
				break;
			}
		}
		if(found==-1)
			printf("n The file is not found ");		
	}



//FUNCTION TO FIND THE INDEX OF A DIRECTORY FOR A GIVEN name	
	int getdir(char name[30]){
		for(i=0;i<n;i++){
			if(strcmp(dir[i].dirName,name)==0){
				return i;
				break;	
			}

		}
		return i;	
	}


//FUNCTION TO CHOOSE AN OPERATION
	int option(int i){
		while(1){
			int op;
			printf("choose the option \n1:Insert a file in directory %s",dir[i].dirName);
			printf("n2:Display Files and Directories");
			printf("n3:Delete File from %s",dir[i].dirName);
			printf("n4:Search File in %s",dir[i].dirName);
			printf("n5:choose another directoryn6:Exitn>>> ");
			scanf("%d",&op);
			switch(op){
				case 1:InsertFile(i);
						 break;
				case 2:DisplayFiles();	 
						 break;	
				case 3:DeleteFile(i);
						 break;	
				case 4:SearchFile(i);
						 break;		
				case 5:return 1;
						break;
				case 6:exit(0);	 	 
			}			

		}
	}


  int main(){
		char name[20];
		printf("n Enter the no of directories ");
		scanf("%d",&n);
		for(i=0;i<n;i++){
			dir[i].fno=0;
			printf("For directory %d Enter the directory name:  \n",i+1);
			scanf("%s",dir[i].dirName);
		}
		while(1){
			printf("choose a directory to perform operation "); 
			for(i=0;i<n;i++){
				printf("nt%s",dir[i].dirName);

			}
			printf("n>>");
			scanf("%s",name);
			option(getdir(name));
		}
		return 0;
	}
