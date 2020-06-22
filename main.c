#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define INT_MAX 2147483647

int main() {
	FILE* fp;
	char strTemp[255];
	int i = 0;
	int j = 0;
	int k = 0;
	int lineCount=0;
	int cityCount=0;
    int** pNum;
	char* pStr;
	char** cities = malloc(sizeof(char*) * 30);

	fp = fopen("hw7_data.txt", "r");
	if (fp == NULL){
		printf("%s\n", "ERROR");
		exit(1);
	}
	
	while(!feof(fp))
	{ 
		printf("line %d\n", lineCount);
		pStr = fgets(strTemp, sizeof(strTemp), fp);
		char* pTok;
		pTok = strtok(strTemp, " \t");
		if(lineCount==0){
			while(pTok!=NULL){
			printf("%s ", pTok);
			cities[cityCount]=malloc(30);
				//도시 이름 글자수는 30 미만으로 설정
				strncpy(cities[cityCount],pTok,sizeof(char*));
				printf("\nadd city :%s \n", cities[cityCount]);
				cityCount++;
				pTok = strtok(NULL, " \t");
			}
			pNum = malloc(sizeof(int*)*cityCount);
			for(i=0;i<cityCount;i++){
				pNum[i]=malloc(sizeof(int)*cityCount);
			}
		} else {
			while(pTok!=NULL){
				if(pTok[0]>=48 && pTok[0]<=57){
					pNum[lineCount-1][j]=atoi(pTok);
					printf("%d ", pNum[lineCount-1][j]);
					j++;
				} 
				else if(pTok[0]=='i' || pTok[0]=='I'){
					pNum[lineCount-1][j]=INT_MAX;
					printf("INF ");
					j++
				}
				pTok = strtok(NULL, " \t");
			}
		}
		lineCount++;
	}
	fclose(fp);

}