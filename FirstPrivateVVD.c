#include<iostream.h>
#include<omp.h>
using namespace std;
int main(){
	int i;
	int index=0;
	int n;
	cout<<"Vector Space:";
	cin>>n;
	int a[n+1];
	int b[n+1];
	int c[n+1];
	printf("First vector:");
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	printf("Second vector:");
	for(i=0;i<n;i++){
		cin>>b[i];
	}
   #pragma omp parallel private(index)
	{
        int thread=omp_get_thread_num();
        for(i=index;i<n;i++){
        	if(i==thread-1){
        		c[i]=a[i]+b[i];
        		break;
        	}
        }
	}
	for(i=0;i<n;i++){
		cout<<c[i];
	}
    return 0;
}