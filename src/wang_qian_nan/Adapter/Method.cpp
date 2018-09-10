
#include <iostream>
#include <algorithm>
using namespace std;


//IDataOperation 抽象数据操作类：目标接口

class DataOperation
{
public:

    //Methods
    virtual int* sort(int array[]){};
public:

    virtual int search(int array[],int key){};

};


//QuickSort 快速排序类：适配者

class QuickSort
{
public:

    //Methods
    int* quickSort(int array[])
    {
        sort(array,0, sizeof(array)-1);

        int n = sizeof(array)/sizeof(array[0]);

//      std::sort(array,array+n);
        return array;
    }

    void sort(int array[], int p,int r)
    {
        int q = 0;
        if(p<r)
        {
            q = partition(array,p,r);
            sort(array,p,q-1);
            sort(array,q+1,r);
        }

    }

    int partition(int a[],int p,int r)
    {
        int x = a[r];
        int j = p-1;
        for(int i = p; i <= r-1;i++)
        {
            if(a[i]<=x)
            {
                j++;
                swap(a,j,i);
                return j+1;
            }
        }
    }

    void swap(int a[],int i, int j)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

};


//BinarySearch 二分查找类：适配者

class BinarySearch
{
public:
    int binarySearch(int array[],int key)
    {
        int low = 0;
        int high = sizeof(array)-1;
        while(low<= high)
        {
            int mid = (low+high)/2;
            int midVal = array[mid];
            if (midVal < key)
            {
                low = mid + 1;
            }
            else if(midVal > key)
            {
                high = mid - 1;
            }
            else
            {
                return 1; //找到元素返回1
            }
        }
        return -1;   //未找到元素返回-1
    }

};


//OperationAdapter 操作适配类：适配器

class OperationAdapter :public DataOperation,public QuickSort
{
private:
    QuickSort *sortObj;
    BinarySearch *searchObj;

public:
     OperationAdapter()
     {
         sortObj = new QuickSort();
         this->sortObj = sortObj;

         searchObj = new BinarySearch();
         this->searchObj = searchObj;
     }



     int* sort(int array[])
     {
         return sortObj->quickSort(array);
     };

     int search(int array[], int key)
     {
         return searchObj->binarySearch(array,key);

     }


};


//ClientTest 客户端测试类

void Print(int *a,int n)
{
    int i = 0;
    for (i = 0; i<n; i++)
    {
        cout<< *(a+i) <<endl;
    }

}
int main()
{
    int array[]={13,24,12,36,26,17,68,34};
    cout<<"排序结果："<<endl;
    int n = sizeof(array)/sizeof(array[0]);

    DataOperation *t = new OperationAdapter();
    int *a = t->sort(array);

    Print(a,n);

    return 0;
}


