#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
char input[10];
int i,error;
void E(),T(),F(),Eprime(),Tprime();

int main() {
	system("clear");
	i=0;
	error=0;
	printf("ENTER INPUT STRING:");
	scanf("%s",input);
	E();
	if(strlen(input)==i && error==0)
		printf("\nAccepted..!!!\n");
	else 
		printf("\nRejected..!!!\n");
}
void E() {
	T();
	Eprime();
}
void Eprime() {
	if(input[i]=='+'){
		i++;
		T();
		Eprime();
	}
}
void T() {
	F();
	Tprime();
}
void Tprime() {
	if(input[i]=='*') {
		i++;
		F();
		Tprime();
	}
}
void F() {
	if(isalnum(input[i])){
		i++;
		while(isalnum(input[i])){
			i++;
		}
	}
	else if(input[i]=='(') {
		i++;
		E();
	if(input[i]==')')
		i++;
	else 
		error=1;
	}
	else 
		error=1;
}
