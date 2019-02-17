//Bubble sort
void bubble_sort(double *a,long long int n)
{
	int i,j;
	double temp;
	for(i=0;i<n-1;i++)
	{
		int flag=0;
		for(j=0;j<n-1-i;j++)
		{  
			if(a[j]>a[j+1])
			{   
				flag=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			} 
		
		}
		if(flag==0) return;
	} 
	
}


//Two way bubble sort
void impbubble_sort(double *a,long long int n)
{
	int i,j,count1=0,count2=0,flag;
	double temp;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		if(i%2==0)
		{	
			for(j=count2;j<n-1-count1;j++)
			{  
				if(a[j]>a[j+1])
				{   
					flag=1;
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}	 
		
			}
			if(flag==0) return;
			count1++;
		}
		
		else
		{
			for(j=n-count1-1;j>count2;j--)
			{  
				if(a[j]<a[j-1])
				{   
					flag=1;
					temp=a[j];
					a[j]=a[j-1];
					a[j-1]=temp;
				}	 
			
			}
			if(flag==0) return;
			count2++;
		}   
	
	
	
	} 
}


//quick sort first element as pivot
long long int normpartation(double *a,long long int lower,long long int upper)
{
	long long int i=lower,j=upper;
	double t=a[lower],temp;
	while(i<=j)
	{
		while(i<=upper&&a[i]<=t) i++;
		while(a[j]>t) j--;
		if(i<=j)
		{
			temp=a[i]; a[i]=a[j]; a[j]=temp;
		}
	}
	temp=a[lower];
	a[lower]=a[j];
	a[j]=temp;
	return j;
	
}

void normquick_sort(double *a,long long int lower,long long int upper)
{	long long int j;
	static int i=0;
	while(lower<upper)
	{
		j=normpartation(a,lower,upper);
		if(j-lower<upper-j)
		{		
			normquick_sort(a,lower,j-1);
			lower=j+1;
		}
		else
		{
			normquick_sort(a,j+1,upper);
			upper=j-1;
		}
	}
}




//Quick sort with middle elements as pivot
long long int middlepartation(double *a,long long int lower,long long int upper)
{	
	int i=lower,j=upper,m;
	double temp,t;
	m=(lower+upper)/2;
	temp=a[lower];
	a[lower]=a[m];
	a[m]=temp;
	t=a[lower];
	while(i<=j)
	{
		while(i<=upper&&a[i]<=t) i++;
		while(a[j]>t) j--;
		if(i<=j)
		{
			temp=a[i]; a[i]=a[j]; a[j]=temp;
		}
	}
	temp=a[lower];
	a[lower]=a[j];
	a[j]=temp;
	return j;
	
}


void middlequick_sort(double *a,long long int lower,long long int upper)
{	int j;
	if(lower>=upper) return;
	else
	{	
		j=middlepartation(a,lower,upper);
		middlequick_sort(a,lower,j-1);
		middlequick_sort(a,j+1,upper);
	}
}



//Reverse Quick sort with middle elements as pivot
long long int rmiddlepartation(double *a,long long int lower,long long int upper)
{	
	int i=lower,j=upper,m;
	double temp,t;
	m=(lower+upper)/2;
	temp=a[lower];
	a[lower]=a[m];
	a[m]=temp;
	t=a[lower];
	while(i<=j)
	{
		while(i<=upper&&a[i]>=t) i++;
		while(a[j]<t) j--;
		if(i<=j)
		{
			temp=a[i]; a[i]=a[j]; a[j]=temp;
		}
	}
	temp=a[lower];
	a[lower]=a[j];
	a[j]=temp;
	return j;
	
}



void rmiddlequick_sort(double *a,long long int lower,long long int upper)
{	int j;
	if(lower>=upper) return;
	else
	{
		j=rmiddlepartation(a,lower,upper);
		rmiddlequick_sort(a,lower,j-1);
		rmiddlequick_sort(a,j+1,upper);
	}
}


//Quick sort with median of first,middle and last as pivot
long long int medianpartation(double *a,long long int lower,long long int upper)
{
	int i=lower,j=upper,m,p;
	double temp,t;
	m=(lower+upper)/2;
	if((a[lower]-a[m])*(a[upper]-a[lower])>=0) p=lower;
	else if((a[upper]-a[m])*(a[lower]-a[upper])>=0) p=upper;
	else p=m;
	t=a[p];
	while(i<=j)
	{
		while(i<=upper&&a[i]<=t) i++;
		while(a[j]>t) j--;
		if(i<=j)
		{
			temp=a[i]; a[i]=a[j]; a[j]=temp;
		}
	}
	if(j==upper) return INT_MIN; else return j;
	
}


void medianquick_sort(double *a,long long int lower,long long int upper)
{	int j;
	if(lower>=upper) return;
	else
	{

		j=medianpartation(a,lower,upper);
		if(j!=INT_MIN)
		{
			medianquick_sort(a,lower,j);
			medianquick_sort(a,j+1,upper);
		}
	}
}



//Bsort
long long int bpartation(double *a,long long int lower,long long int upper)
{
	int i=lower,j=upper,m,flag=0;
	double temp,t;
	m=(lower+upper)/2;
	temp=a[lower];
	a[lower]=a[m];
	a[m]=temp;
	t=a[lower];
	while(i<=j)
	{
		while(i<=upper&&a[i]<=t)
		{ 
			i++; if(a[i]<a[i-1]) {temp=a[i]; a[i]=a[i-1]; a[i-1]=temp; flag=1;}
		}
		while(a[j]>t) 
		{
			j--; if(a[j]>a[j+1]) {temp=a[j]; a[j]=a[j+1]; a[j+1]=temp; flag=1;}
		}
		if(i<=j)
		{
			temp=a[i]; a[i]=a[j]; a[j]=temp;
		}
	}
	temp=a[lower];
	a[lower]=a[j];
	a[j]=temp;
	if(flag==1) return j; else return(INT_MIN);
	
}

void bquick_sort(double *a,long long int lower,long long int upper)
{	int j;
	if(lower>=upper) return;
	else
	{
		j=middlepartation(a,lower,upper);
		if(j!=INT_MIN)
		{
			bquick_sort(a,lower,j-1);
			bquick_sort(a,j+1,upper);
		}
	}
}



//Meansort sort
long long int meanpartation(double *a,long long int lower,long long int upper)
{
	int i=lower,j=upper,p;
	double temp,sum=0,t;
	int all_values_same=1;
	for(p=lower;p<=upper;p++)
	{	
		if(p<upper && a[p]!=a[p+1]) all_values_same=0;
		sum+=a[p];
	}
	if(all_values_same==1) return -1;
	t=sum/(upper-lower+1);
	while(i<=j)
	{
		while(i<=upper&&a[i]<=t) i++;
		while(a[j]>t) j--;
		if(i<=j)
		{
			temp=a[i]; a[i]=a[j]; a[j]=temp;
		}
	}
	return j;
	
}

void meanquick_sort(double *a,long long int lower,long long int upper)
{	int j;
	if(lower>=upper) return;
	else
	{
		j=meanpartation(a,lower,upper);
		if(j!=-1)
		{
			meanquick_sort(a,lower,j);
			meanquick_sort(a,j+1,upper);
		}
	}
}





//Selection Sort
void selection_sort(double *a,long long int n)
{

	long long int i,largest,j,p;
	for(i=n-1;i>0;i--)
	{
		p=0;
		largest=a[p];
		for(j=1;j<=i;j++)
		{
			if(a[j]>largest)
			{
				largest=a[j];
				p=j;
			}			
		}
		a[p]=a[i];
		a[i]=largest;	
	}
}




//Tree Sort
struct node
{
	double data;
	struct node * right;
	struct node * left;
	unsigned int thread:1;
};


struct node* maketree(double x)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	temp->thread=1;
	return temp;
}


void free_tree(struct node * temp)
{
	if(temp==NULL) return;
	struct node *temp1=temp,*temp2;
	while(1)
	{
		while(temp1->left!=NULL) temp1=temp1->left;
		while(temp1->thread) 
		{
			temp2=temp1; 
			temp1=temp1->right; 
			free(temp2); 
			if(temp1==NULL) return;
		}
		temp2=temp1;
		temp1=temp1->right;
		free(temp2);
	}
}


void inorder(struct node *temp,double *a)
{
	long long int i=0;
	if(temp==NULL) return;
	struct node *temp1=temp;
	while(1)
	{
		while(temp1->left!=NULL) temp1=temp1->left;
		a[i++]=temp1->data;
		while(temp1->thread) 
		{
			temp1=temp1->right; 
			if(temp1==NULL) return; 
			a[i++]=temp1->data;
		}
		temp1=temp1->right;
	}
}


void tree_sort(double *a,long long n)
{
	struct node *temp=NULL, * temp1, * temp2;
	long long int i;
	temp=maketree(a[0]);
	for(i=1;i<n;i++)
	{
		temp1=temp;
		while(1)
		{
			if(a[i]<temp1->data) 
				if(temp1->left==NULL) 
				{
					temp1->left=maketree(a[i]); 
					temp1->left->right=temp1; 
					break;
				} 
				else temp1=temp1->left;
			else if(temp1->thread) 
			{
				temp1->thread=0; 
				temp2=temp1->right; 
				temp1->right=maketree(a[i]); 
				temp1->right->right=temp2; 
				break;
			} 
			else temp1=temp1->right;
		}
	}
	inorder(temp,a);
	free_tree(temp);
}


//HeapSort
void swap(double *a,double *b)
{
	double temp=*a;
	*a=*b;
	*b=temp;
}

int left(int i){ return 2*i+1;}

int right(int i){ return 2*i+2;}

void heapify(double *a,int n,int i)
{
	int l,r,largest;
	while(1)
	{
		l=left(i);
		r=right(i);
		largest=i;
		if(l<n&&a[l]>a[i]) largest=l;
		if(r<n&&a[r]>a[largest]) largest=r;
		if(largest==i) return;
		swap(&a[i],&a[largest]);
		i=largest;
	}
}

void heap_sort(double *a,long long int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(i=n-1;i>0;i--)
	{
		swap(&a[0],&a[i]); n--;
		heapify(a,n,0);
	}
}

//Insertion Sort
void simpleinsertion_sort(double *a,long long int n)
{
	long long int i,j;
	double temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0&&a[j]>temp) 
		{
			a[j+1]=a[j]; j--;
		} 
		a[++j]=temp;
	}
}

//Shell sort with shell increment squence
void shellshell_sort(double *a,long long int n)
{
	long long int i,j,t;
	double temp;
	t=n/2;
	while(t>0)
	{
		for(i=t;i<n;i++)
		{
			temp=a[i];
			j=i-t;
			while(j>=0&&a[j]>temp) 
			{
				a[j+t]=a[j]; 
				j-=t;
			} 
			a[j+=t]=temp;
		}
		t=t/2;
	}
}

//shell sort wiht kunth increment sequence
void kunthshell_sort(double *a,long long int n)
{
	long long int i,j,t=0,k=1;
	double temp;
	while(t<n)
	{
		t=(pow(3,k)-1)/2; 
		k++;
	}
	k-=2;
	while(k>0)
	{
		t=(pow(3,k)-1)/2;
		for(i=t;i<n;i++)
		{
			temp=a[i];
			j=i-t;
			while(j>=0&&a[j]>temp) 
			{
				a[j+t]=a[j]; 
				j-=t;
			} 
			a[j+=t]=temp;
		}
		k--;
	}
}

//Merge Sort
void merge(double *a,long long int l,long long int m,long long int h)
{
	int i,j,k;
	double *b=(double *)malloc(sizeof(double)*(m-l+1));
	double *c=(double *)malloc(sizeof(double)*(h-m));
	for(i=0;i<m-l+1;i++) b[i]=a[l+i];
	for(i=0;i<h-m;i++) c[i]=a[m+1+i];
	i=0;j=0,k=l;
	while((i<m-l+1)&&(j<h-m)) 
		if(b[i]<=c[j]) 
			a[k++]=b[i++]; 
		else 
			a[k++]=c[j++];
	if(i==m-l+1) 
		while(j<h-m) 
			a[k++]=c[j++]; 
	else 
		while(i<m-l+1) a[k++]=b[i++];
	free(b);
	free(c);
}



void mergesort(double *a,long long int l,long long int h)
{
	long long int m;
	if(l<h)
	{
		m=l+(h-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}

//Wrappers functions
void wrapper_normquick_sort(double *a,long long int n)
{
	normquick_sort(a,0,n-1);
}


void wrapper_middlequick_sort(double *a,long long int n)
{
	middlequick_sort(a,0,n-1);
}


void wrapper_medianquick_sort(double *a,long long int n)
{
	medianquick_sort(a,0,n-1);
}


void wrapper_bquick_sort(double *a,long long int n)
{
	bquick_sort(a,0,n-1);
}


void wrapper_meanquick_sort(double *a,long long int n)
{
	meanquick_sort(a,0,n-1);
}


void wrapper_mergesort(double *a,long long int n)
{
	mergesort(a,0,n-1);
}
