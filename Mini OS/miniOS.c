#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
#include <pthread.h>

void* run_notepad(void* arg){
    // Use system call to run notepad in a new terminal window
    system("gnome-terminal --title=\"Notepad\" -x sh -c './Tasks/notepad; exec bash'");
    pthread_exit(NULL);
}

void* run_calculator(void* arg){
    system("gnome-terminal --title=\"Calculator\" -x sh -c './Tasks/calculator; exec bash'");
    pthread_exit(NULL);
}

void* run_time(void* arg){
    system("gnome-terminal --title=\"Time\" -x sh -c './Tasks/time; exec bash'");
    pthread_exit(NULL);
}

void* run_createFile(void* arg){
    system("gnome-terminal --title=\"Create File\" -x sh -c './Tasks/createFile; exec bash'");
    pthread_exit(NULL);
}

void* run_moveFile(void* arg){
    system("gnome-terminal --title=\"MoveFile\" -x sh -c './Tasks/moveFile; exec bash'");
    pthread_exit(NULL);
}

void* run_copyFile(void* arg){
    system("gnome-terminal --title=\"CopyFile\" -x sh -c './Tasks/copyFile; exec bash'");
    pthread_exit(NULL);
}

void* run_deleteFile(void* arg){
    system("gnome-terminal --title=\"DeleteFile\" -x sh -c './Tasks/deleteFile; exec bash'");
    pthread_exit(NULL);
}

void* run_checkFileInfo(void* arg){
    system("gnome-terminal --title=\"CheckFileInfo\" -x sh -c './Tasks/checkFileInfo; exec bash'");
    pthread_exit(NULL);
}

void* run_textEditor(void* arg){
    system("gnome-terminal --title=\"TextEditor\" -x sh -c './Tasks/textEditor; exec bash'");
    pthread_exit(NULL);
}

void* run_fileRenamingTool(void* arg){
    system("gnome-terminal --title=\"FileRenamingTool\" -x sh -c './Tasks/fileRenamingTool; exec bash'");
    pthread_exit(NULL);
}

void* run_fileSearchingTool(void* arg){
    system("gnome-terminal --title=\"FileSearchingTool\" -x sh -c './Tasks/fileSearchingTool; exec bash'");
    pthread_exit(NULL);
}

void* run_calender(void* arg){
    system("gnome-terminal --title=\"Calender\" -x sh -c './Tasks/calender; exec bash'");
    pthread_exit(NULL);
}

void* run_contactManager(void* arg){
    system("gnome-terminal --title=\"contactManager\" -x sh -c './Tasks/contactManager; exec bash'");
    pthread_exit(NULL);
}

void* run_ticTacToe(void* arg){
    system("gnome-terminal --title=\"TicTacToe\" -x sh -c './Tasks/ticTacToe; exec bash'");
    pthread_exit(NULL);
}


void startSystem();
void menu();
int menuSelection_validation();


int main()
{
    startSystem();		//Start the OS
    printf("\033[0;38m");
    menu();				//Display Menu
    int select = menuSelection_validation();
    

    pthread_t th;   
    int rc; 
    while(1){
    	if(select == 1){
		rc = pthread_create(&th, NULL, run_notepad, NULL);
        	pthread_join(th, NULL);	    	
    	}
	else if(select == 2){
		rc = pthread_create(&th, NULL, run_calculator, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 3){
		rc = pthread_create(&th, NULL, run_time, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 4){
		rc = pthread_create(&th, NULL, run_createFile, NULL);
        	pthread_join(th, NULL);		
	}
	else if(select == 5){
		rc = pthread_create(&th, NULL, run_moveFile, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 6){
		rc = pthread_create(&th, NULL, run_copyFile, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 7){
		rc = pthread_create(&th, NULL, run_deleteFile, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 8){
		rc = pthread_create(&th, NULL, run_checkFileInfo, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 10){
		rc = pthread_create(&th, NULL, run_textEditor, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 11){
		rc = pthread_create(&th, NULL, run_fileRenamingTool, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 12){
		rc = pthread_create(&th, NULL, run_fileSearchingTool, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 13){
		rc = pthread_create(&th, NULL, run_calender, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 14){
		rc = pthread_create(&th, NULL, run_contactManager, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 15){
		rc = pthread_create(&th, NULL, run_ticTacToe, NULL);
	        pthread_join(th, NULL);		
	}
	else if(select == 16){
	        printf("\n\t\tOS SHUTS DOWN\n");
		exit(EXIT_FAILURE);
	}

        if (rc) {
            printf("Error creating thread\n");
            exit(1);
        }	
        
        menu();
    	select = menuSelection_validation();

    }    
    
    return 0;
}

void startSystem(){
    printf("\033[0;32m"); // set text color to yellow
    system("clear");
    unsigned int bar1 = 61; 

    printf("\n\n\n\n\n\n\n\t\t\t WELCOME to Aaiza_Ayesha_Nimra OS");
    printf("\n\n\n\t\t\t");

    for(int i=0; i<35; i++){
        printf("%c", (char)bar1);
    }
    printf("\r");
    printf("\t\t\t");
    for(int i=0; i<35; i++){
        printf("\u2588");
        fflush(stdout); // flush output buffer
        usleep(150000); // sleep for 150 milliseconds
    }

    sleep(2);
    printf("\n\n\t\t\t  \u1F600! Press Enter to continue...");
    getchar(); 
    
}



void menu(){
    system("clear");
	printf("\n\n==========================================================\n");
	printf("\tPress  1 to open the   NotePad\n");
	printf("\tPress  2 to open the   Calculator\n");
	printf("\tPress  3 to open the   Date and Time\n");
	printf("\tPress  4 to open the   Crete File Tool\n");
	printf("\tPress  5 to open the   Move File Tool\n");
	printf("\tPress  6 to open the   Copy File Tool\n");
	printf("\tPress  7 to open the   Delete File Tool\n");
	printf("\tPress  8 to open the   Check File Info Tool\n");
	printf("\tPress  9 to open the   Image Viewer\n");
	printf("\tPress 10 to open the   Text Editor\n");
	printf("\tPress 11 to open the   File Renaming Tool\n");
	printf("\tPress 12 to open the   File Searching Tool\n");
	printf("\tPress 13 to open the   Calender\n");
	printf("\tPress 14 to open the   Contact Manager\n");
	printf("\tPress 15 to play the   TicTacToe Game\n");
	printf("\tPress 16 to play the   EXIT\n");
	printf("\n===========================================================\n");
}


int menuSelection_validation(){
	int select;
    printf("\n\t\tEnter your choice: ");
    scanf("%d",&select);
    if(select<1 || select>16){
    	while(select < 1 || select > 16){
    		printf("\t\t  INVALID SELECTION\n");
   		    printf("\t\tEnter choice again: ");
   		    scanf("%d",&select);
    	}
    }
    return select;
}
