#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<math.h>
#include"sort.h" //Contains all sorting algorithms implementations


//Copys containts of arr1 to arr2
void copy(double *arr1,double *arr2,long long int SIZE);


int main()
{   		
	const char *algorithms[]={"Bubble Sort","Two-Way Bubble Sort","Quick Sort First Element AS Pivot","Quick Sort Middle Element As Pivot","Quick Sort With Median Of First,Middle And Last As Pivot","Bsort","Meansort Sort","Selection Sort","Tree Sort","Heap Sort","Insertion Sort","Shell Sort With Shell Increment Squence","Shell Sort With Kunth Increment Sequence","Merge Sort"};
	
	const void (*functions[])( double *,long long int )={&bubble_sort,&impbubble_sort,&wrapper_normquick_sort,&wrapper_middlequick_sort,&wrapper_medianquick_sort,&wrapper_bquick_sort,&wrapper_meanquick_sort,&selection_sort,&tree_sort,&heap_sort,&simpleinsertion_sort,&shellshell_sort,&kunthshell_sort,&wrapper_mergesort};

	long long int SIZE,MAX_NUMBER,i,starting_size,max_size,step;

	int dis,total,N=14;

	int comparing[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};//List of index of algorithms to be compared.

	double *arr1,*arr2;

	double MAXIUM_NUMBER=100000000000.0;

	//For measuring time for each algorithm
	clock_t start,end;

	//Giving time(seconds) as seed to random number generator 
	time_t  sec=time(NULL);
	srand(sec);

	printf("Please Enter starting array size,max_array_size and step. Example 100000 500000 100000: ");
	scanf("%lld %lld %lld",&starting_size,&max_size,&step);

	printf("\nAll availiable algorithms:\n");
	for(i=0;i<N;i++)
	{
		printf("%lld. %s\n",i,algorithms[i]);
	
	}

	printf("\nHow many algorithms you want to compare.Example 3:");
	scanf(" %d",&total);
	if (total<N)
	{
		printf("Enter index of chosen algorithms. Example 0 8 13: ");
		for(i=0;i<total;i++) scanf(" %d",&comparing[i]);
	}

	//Looping over various array size
	for(SIZE=starting_size;SIZE<=max_size;SIZE+=step)
	{


		//Allocating memory for two arrays  
		arr1=(double *)malloc(sizeof(double)*SIZE);
		arr2=(double *)malloc(sizeof(double)*SIZE);
		
		
		//Generating array of random numbers of size "SIZE"	
		for(i=0;i<SIZE;i++)
		{
			//Generating random number between 0 to MAX_NUMBER
			double number=(((double)rand())/RAND_MAX)*MAXIUM_NUMBER;
			arr1[i]=number;
		}

		//Looping over various distributions of data
		for(dis=0;dis<4;dis++)
		{

			if(dis==0)
			{

				//Random 
				printf("\n\nOn Randomly Generated Distribution of %lld real numbers\n\n",SIZE);

			}

			else if(dis==1)
			{

				//Reversed sorted 
				printf("\n\nOn Reversed Sorted Distribution of %lld real numbers\n\n",SIZE);
				//Sort arr1 in descending order
				rmiddlequick_sort(arr1,0,SIZE-1);

			}

			else if(dis==2)
			{

				//Already sorted
				printf("\n\nOn Alreadly Sorted Distribution of %lld real numbers\n\n",SIZE);
				//Sort arr1 in ascending order
				middlequick_sort(arr1,0,SIZE-1);

			}	

			else
			{

				//some % sorted

				float x=0.2; //80% sorted
				printf("\n\nOn %d Percentage Sorted Distribution of %lld real numbers\n\n",(int)(100-x*100),SIZE);

				//arr1 is already sorted in ascending order
				
				//Replace x fraction of array by random values
				for(i=0;i<SIZE*x;i++)
				{
					//Random Integer between 0 to SIZE
					long long int position=(long long int)((((double)rand())/RAND_MAX)*SIZE);
					arr1[position]=(((double)rand())/RAND_MAX)*MAXIUM_NUMBER;

				}

			}

			//Looping over various algorithms
			for(i=0;i<total;i++)
			{
				copy(arr1,arr2,SIZE);
				start=clock();
				functions[comparing[i]](arr2,SIZE);
				end=clock();
				printf("Time required for %s is %lf miliseconds.\n",algorithms[comparing[i]],(double)(end-start)/1000);
			}

		}	

	}
return 0;
}



void copy(double *arr1,double *arr2,long long int SIZE)
{
	
	long long int i;
	for(i=0;i<SIZE;i++)
	{
		arr2[i]=arr1[i];
	}
}
