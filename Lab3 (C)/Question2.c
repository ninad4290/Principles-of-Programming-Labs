#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"




student **create_class_list(char *filename, int *sizePtr){
	/*write your implementation here*/
			student **class_list;



			FILE *fp = fopen(filename, "r");
			fscanf(fp, "%d", sizePtr);
			class_list = calloc(*sizePtr,sizeof(student));

	        for(int i = 0;i<*sizePtr;i++){
	        	student *s = calloc(1,sizeof(student));
	        	fscanf(fp,"%d",&s->student_id);
	        	fscanf(fp,"%d",&s->first_name);
	        	fscanf(fp,"%d",&s->last_name);
	        	class_list[i] = s;
	        }
	         //get no . of records

	        fclose(fp);


	/* finally return the created class list*/
	        return class_list;
}

int find(int idNo, student **list, int size){
	/*write your implementation here and update the return accordingly*/
	for (int i = 0; i < size; i++){
		int id = list[i]->student_id;
		if (id == idNo){
			return i;
		}
	}

	return -1;
}

void input_grades(char *filename, student **list, int size)
{
	/*write your implementation here*/
	FILE *fp = fopen(filename, "r");

	int id;
	int pos;


	for(int i =0; i<size; i++){
		fscanf(fp,"%d",&list[pos]->project1_grade);
		fscanf(fp,"%d",&list[pos]->project2_grade);
	}

	fclose(fp);
}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	for (int i = 0;i<size;i++){
		list[i]->final_grade = (list[i]->project1_grade + list[i]->project2_grade)/2.0;
	}
}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/
	FILE *fp = fopen(filename, "w");
	fprintf(fp,"%d\n",size);

	for(int i = 0;i<size;i++){
		fprintf(fp,"%d %f\n",list[i]->student_id,list[i]->final_grade);
	}
	fclose(fp);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int pos = find(idNo,list,sizePtr);

	if (pos!= -1){
		(*sizePtr)--;
		free(list[pos]);

	}
	for(int i = pos; i<*sizePtr;i++){
		list[i] = list[i+1];
	}
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for(int i = 0; i<*sizePtr;i++){
			free(list[i]);
		}
			free(list);
			*sizePtr = 0;
}
void call_all_functions(char *filename_classlist,char *filename_classgrades,char *filename_classfinal_grades){
	int size;

	student **list = create_class_list(filename_classlist, &size);
	input_grades(filename_classgrades,list,size);
	compute_final_course_grades(list,size);
	output_final_course_grades(filename_classfinal_grades,list,size);

	withdraw(5555,list,&size);
	withdraw(1200,list,&size);
	withdraw(9000,list,&size);

	destroy_list(list,&size);

}
