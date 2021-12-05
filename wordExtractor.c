#include <stdio.h>
#include <string.h>

int wordExtract() {
	char input[40];
	const char s[5] = " ,.-";
	char *token;
    int i;
	int j;
	printf("Type in the word and press Enter: ");
	fgets(input,sizeof(input),stdin);

/*
    int len = sizeof(input)/sizeof(input[i]);
    for(i=0; i<len; i++){
        if(input[i] == ' '){
            for(j=i;j<len;j++){
                input[j]=input[j+1];
            }
            len--;
        }
    }
    */

    token = strtok(input, s);
	while(token != NULL){

        printf("%s\n",token);
        token = strtok(NULL, s);
	}



	return 0;
}

int main(){
	wordExtract();
	return 0 ;
}

