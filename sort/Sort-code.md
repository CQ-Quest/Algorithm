# 插入排序        稳定性：稳定  
原理：每次将一个排序元素按照关键字大小插入到已排序的序列中。  
Key code：  

	void insert_sort (int a[],int n){
		int i,j,temp;
		for(i=0;i<n;i++){
			temp=a[i];                     /*temp起到储存作用，防止a[i]丢失*/ 
			j=i-1;
			while(j>=0&&temp<a[j]){
				a[j+1]=a[j];
				j--;                        /*一个个后移*/ 
			} 
			a[j+1]=temp; 
		}
	}



# 冒泡排序     稳定性：稳定     
原理：依次比较两相邻数，若是按从小到大顺序，小数在前，大数在后，直至比较最后两位数。                        
结束条件：一趟排序未发生元素交换。  

Key code：  

	void Bubble_sort(int a[],int n){
		int i,j,temp;
		for(i=0;i<n-1;i++){                             /*最多比较n-1轮*/ 
			bool isSorted = true;
			for(j=0;j<n-1-i;j++){
				if(a[j]>a[j+1]){                        /*按从小到大的顺序排序*/ 
				isSorted=false;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				}
			} 
			if(isSorted)
			break;
		}

	}

# 希尔排序   稳定性：不稳定  
原理：等同于插入排序，区别在插入排序每次只间隔一个元素，而希尔排序间隔gap个元素，但最后一趟仍为真正的插入排序。  

适用场景：大规模乱序。  

Key code：  

	void shellsort(int a[],int size,int* compare,int* move) {
	    int i,j,temp,gap;
		gap = size/2 ;	// gap的值若分3等分，gap需+1 
	    while ( gap ){
	       for (int k=0;k<gap;k++) {	//对于gap所分的每一个组
			for (i = k+gap ; i <size ; i += gap) {      //进行插入排序
				temp = a[i];
			      for (j=i-gap; j >= 0 &&a[j] > temp ; j = j - gap){
				    a[j+gap] = a[j] ;
				    (*move)++ ;        //数字移动次数
				    (*compare)++ ;     //比较次数
				}
				a[j+gap] = temp;
				(*move)++ ; 
			}
	       }
	       gap/=2;
	    } 
	}






# 选择排序      稳定性：不稳定  
 原理：如果有n个元素需要排序，那么首先从n个元素中找到最小的那个(称为第0小的)放在第0个位置上(和原来第0个位置上的元素交换位置)，  
 然后再从剩下的n-1个元素找到最小的放在第一个位置上，将剩下的n-2个中找到最小的放在第二个位置上，以此类推，直到所有的元素就位。  

	Key code:  
	void selectionSort(int a[],int size){
		int i,j,temp;
		for(i=0;i<size-1;i++){              /*每次循环后将第i小的元素放好*/ 
		 int  tmpMin = i;       /*tmpMin用来记录第i个到size-1个元素中最小元素的下标*/ 
			for(int j=i+1;j<size;j++) {
				if(a[j] < a[tmpMin])
				tmpMin = j;
			}
		      /*下面将第i小的元素放在第i个位置上，并将原来位置上的元素移到后面*/	
			temp=a[i];
			a[i]=a[tmpMin];
			a[tmpMin]=temp;
		}
	} 
	




# 快速排序       稳定性：不稳定  
  
    快排思想：  
先从数列中取出一个数作为基准数分区过程，将比这个数大的数全放到它的右边，  
小于或等于它的数全放到它的左边 再对左右区间重复第二步，直到各区间只有一个数   
最优的情况下空间复杂度为：O(log2n)  ；每一次都平分数组的情况，基准数尽量为中间数。  
    适用于解决前m大的数等问题

		void Quicksort(int a[],int l,int r){     //从小到大
		   int i,j;
		   i=l;
		   j=r;
		   a[0]=a[i];
		   while(i<j){
			while(i<j&&a[j]>a[0])  j--;
			if(i<j)    a[i++]=a[j];
			while(i<j&&a[i]<a[0])  i++;
			if(i<j)    a[j--]=a[i];
		   } 
		   a[i]=a[0];
		   if(l<r){
			Quicksort(a,l,i-1);
			Quicksort(a,i+1,r);
		   }
		}
		
		void quick_sort(ll a[],ll l,ll r){    //从大到小
			int i=l,j=r;
			a[0]=a[i];
			while(i<j){
				while(i<j&&a[j]<a[0]) j--;
			  if(i<j)	a[i++]=a[j];
				while(i<j&&a[i]>a[0]) i++;
				if(i<j)  a[j--]=a[i];
			}
			a[i]=a[0];
			if(l<r){
				quick_sort(a,l,i-1);
				quick_sort(a,i+1,r);
			}
		} 

# 归并排序       稳定性：稳定  
原理：将以有序的子序列合并，得到完全有序的序列；即使每一个子序列有序，再使子序列段间有序。若将两个有序表合成一个有序表，称为二路归并排序。  
解决逆序反转问题

注：内存空间不足的时候，能够并行计算的时候使用归并排序  

	Key code：
	___________________________________________________________________________________
	void Merge(int a[],int temp[], int start, int mid, int end)
	{
	  int i = start, j=mid+1;
	   int k=0; 
	  while(i!=mid+1 && j!=end+1)
	  {
	      if(a[i] >a[j])
		temp[k++] = a[j++];     /*从小到大排序，a[j]放入temp[k]，然后j,k都后移一位*/
	      else
		temp[k++] = a[i++];
	  }
	  while(i != mid+1)
	      temp[k++] = a[i++];
	  while(j != end+1)
	      temp[k++] = a[j++];
	  for(i=start; i<=end; i++)
	      a[i] = temp[i];
	}

	/*使用递归*/
	void MergeSort(int a[], int temp[], int start, int end)
	{
	  int mid;
	  if(start < end)
	  {
	      mid = (start+ end) / 2;
	      MergeSort(a, temp, start, mid);        /*左半部分归并排序*/
	      MergeSort(a, temp, mid+1, end);       /*右半部分归并排序*/
	      Merge(a, temp, start, mid, end);        /*左右部分归并*/
	  }
	}
	___________________________________________________________________________________

 vision2:最终版，推荐使用

	 void Merge(ll l,ll mid,ll r){
	    ll i=l,j=mid+1,t=0;
	    while(i<=mid&&j<=r)
	    {
		if(a[i]>a[j])
		{
		    b[t++]=a[j++];
		    cnt+=mid-i+1;
		}
		else
		{
		    b[t++]=a[i++];
		}
	    }
	    while(i<=mid) 
		b[t++]=a[i++];
	    while(j<=r) 
		b[t++]=a[j++];
	    for(i=0;i<t;i++) 
	    a[l+i]=b[i];
	}

	void Mergesort(ll l,ll r)
	{
	    if(l<r)
	    {
		ll mid=(l+r)/2;
		Mergesort(l,mid);
		Mergesort(mid+1,r);
		Merge(l,mid,r);
	    }
	}
	int main(){
	   int n;
	   while(scanf("%d",&n)!=EOF){
		cnt=0;
	      for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	      Mergesort(0,n-1);
	      printf("%d\n",cnt);
	   }
	   return 0;
	}

# 堆排序  
原理：将各个父节点与其自己的孩子结点进行对比，然后交换的过程，  
其中堆是一个完全二叉树。堆排序的实质是一种选择排序  

算法思想：建立堆，调整堆，及交换堆顶元素和堆的最后一个元素。  

	————————————————————————————————————
	完全二叉树的父节点和子节点的关系  
	对于角标从0开始的元素，其节点关系如下：   
	双亲：（i-1）/2 
	左孩子：2*i+1 
	右孩子：2*i+2 
	对于角标从1开始的元素，其节点关系如下： 
	双亲：i/2 
	左孩子：2*i 
	右孩子：2*i+1
	—————————————————————————————————————

Key code:  

	————————————————————————————————————————————————————————————————————————————————
	void swap(int* a, int* b) {
		int p;
		p = *a;
		*a = *b;
		*b = p;
	}
	/* 调整堆 */
	void adjustheap(int* arr, int i, int len) {
		int j = i * 2 + 1;
		while (j < len) {
			if (j + 1 < len && arr[j] < arr[j + 1]) { 
	/*建立大堆,若左孩子小于右孩子,将j取值为右孩子的下标,右孩子再与父结点比较*/
				j++;
			}
	/*将左右孩子中，数值最大的与父结点进行比较,当孩子结点比父结点大时，进行交换*/
			if (arr[i] > arr[j])
				break;
			swap(&arr[i], &arr[j]);
			i = j;
			j = i * 2 + 1;
		}
	}
		   /* 建立堆 */
	void Buildheap(int* arr, int n) {
		int i;
		for (i = n / 2 - 1; i >= 0; i--) {      /*要从最后一个父节点开始调整堆*/
			adjustheap(arr, i, n);
		}
	}
	void heapsort(int* arr, int len) {
		int i = 0;
		Buildheap(arr, len);
	/*每次排出最大的一个元素之后，将该元素排除在堆外,调整堆后交换堆顶元素和堆的最后一个元素*/
		for (i = len - 1; i > 0; i--) {
			swap(&arr[i], &arr[0]);
			adjustheap(arr, 0, i);
		}
	}
	——————————————————————————————————————————————————————————————————————————————————



# 桶排序  
原理：将数组分到有限数量桶里，每个桶再各自排序。  
当排序的数组的数值是均匀分配时，桶排序使用线性时间O（n）.  

算法复杂度：  
1.最好情况：放入的数值比原来的都大  

	___________________________________________________________________________
	Key code:
	void BucketSort(int *A,int *B,int N,int K) 
	{ 
	 int *C=new int[K+1];                   //new函数可申请内存和初始化对象
	 int i,j,k; 
	 memset(C,0,sizeof(int)*(K+1));       //memset 函数可初始化任意想得到的值
	 for (i=1;i<=N;i++) 
	 C[A[i]]++; 
	 for (i=j=1;i<=K;i++,j=k) 
	 for (k=j;k<j+C[i];k++) 
	 B[k]=i; 
	} 
	int main() 
	{ 
	int *A,*B,N=1000,K=1000,i; 
	  A=new int[N+1]; 
	 B=new int[N+1]; 
	 for (i=1;i<=N;i++) 
	 A[i]=rand()%K+1; 
	 BucketSort(A,B,N,K); 
	 for (i=1;i<=N;i++) 
	 printf("%d ",B[i]); 
	 return 0; 
	} 
	____________________________________________________________________________
