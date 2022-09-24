#include<stdio.h>
#include<stdlib.h>
#define RECORD "entries"
#define MAX_ENTRY 10

/* *
	* @about: an accountant journal entry program
	* features like search, edit, delete of entry
	* @todo: implement 2. Modify
	*/

FILE *entryfile; // main record file
struct date{ // date format
	short int day, month, year;
}; // 6 bytes
struct entry{ // entry format
	int SL;
	char DEBIT[80], CREDIT[80], NARRATION[80];
	struct date d;
	float AMOUNT;
}; // 256 bytes
void prompt(void); // start of program
void entryReader(FILE*); // reads max entrie(s) from file
void entryReaderX(struct entry); // reads entry to output
void entryReaderRaw(struct entry); // one line entry output
struct entry makeEntry(void); // create an entry and add to file, returns data written

int main(void){
	prompt();
	return 0;
}

void prompt(void){
	char choice=0;
	puts("Hello, accountant!");
	puts("What would you like to do?");
	puts("1. Create new entry\
	\n2. Modify an entry\
	\n3. Search an entry\
	\n4. Delete an entry\
	\n5. View all entries\n");
	printf("Choose: ");
	scanf("%c", &choice);
	switch(choice){
		case '1':
			makeEntry();
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			entryReader(entryfile);
			break;
		default:
			puts("Invalid input.");
	}
}
void entryReader(FILE *rdfrom){
	struct entry ent[MAX_ENTRY];
	rdfrom=fopen(RECORD, "rb");
	int i=0;
	while(i<MAX_ENTRY){
		if(fread(&ent[i],sizeof(struct entry), 1, rdfrom)!=1) {
			printf("\n%d entries read.\n", i);
			return;
		}
		printf("SN: %d\n", ent[i].SL);
		printf("Date: %d/%d/%d\n", ent[i].d.day, ent[i].d.month, ent[i].d.year);
		printf("Debit: %s\n", ent[i].DEBIT);
		printf("Credit: %s\n", ent[i].CREDIT);
		printf("Amount: %f\n", ent[i].AMOUNT);
		printf("Narration: %s\n\n", ent[i].NARRATION);
		i++;
	}
	fclose(rdfrom);
}
void entryReaderX(struct entry ent){
	printf("SN: %d\n", ent.SL);
	printf("Date: %d/%d/%d\n", ent.d.day, ent.d.month, ent.d.year);
	printf("Debit: %s\n", ent.DEBIT);
	printf("Credit: %s\n", ent.CREDIT);
	printf("Amount: %f\n", ent.AMOUNT);
	printf("Narration: %s\n\n", ent.NARRATION);
}
void entryReaderRaw(struct entry ent){
	printf("%d,%d/%d/%d,%s,%s,%f,%s\n\n",
	ent.SL, ent.d.day, ent.d.month, ent.d.year, 
	ent.DEBIT, ent.CREDIT, ent.AMOUNT, ent.NARRATION);
}
struct entry makeEntry(void){
	struct entry ent;
	printf("SN: "); scanf("%d", &ent.SL);
	printf("Date[dd/mm/yyyy]: "); scanf("%d%*c%d%*c%d", &ent.d.day, &ent.d.month, &ent.d.year);
	printf("Debit: "); scanf("%s", &ent.DEBIT);
	printf("Credit: "); scanf("%s", &ent.CREDIT);
	printf("Amount: "); scanf("%f", &ent.AMOUNT);
	printf("Narration: "); scanf("%s", &ent.NARRATION);

	entryfile=fopen(RECORD, "ab");
	if(entryfile==NULL){
		puts("Error opening file.");
		exit(1);
	}
	if(fwrite(&ent,sizeof(struct entry), 1, entryfile)!=1){
		puts("Error write. Data lost.");
		exit(1);
	}
	fclose(entryfile);
	entryReaderRaw(ent);
	return ent;
}