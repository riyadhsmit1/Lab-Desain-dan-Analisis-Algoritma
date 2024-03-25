#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> vec, int begin, int end)
{
    int i; //for left element index
    int j; //for right element index
    int pivot_idx = (begin+end)/2;
    int pivot = vec[pivot_idx]; //pivot element

    //cout<<"Pivot = "<<pivot<<endl;

    i = begin;
    j = end;
    //partition data into smaller and larger parts relative to the pivot
    while(1)
    {
       while(vec[i]>pivot)
       {
           ++i;
       }
       while(vec[j]<pivot)
       {
           ++j;
       }
       //Once the left index pass right index, partitioning is done
       if(i>=j)
       {
           break;
       }
       //otherwise do swapping
       int temp; 
       temp = vec[i];
       vec[i] = vec[j];
       vec[j] = temp;

       //keep moving indices
       i++;
       j--;
    }

    //recurse into two smaller parts
    if(begin<i-1)
    {
        quick_sort(vec, begin, i-1);
    }
    if(j+1<end)
    {
        quick_sort(vec, j+1, end);
    }
}

int main()
{  
    vector<int> v;
    v.push_back(9);
    v.push_back(5);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);
    v.push_back(11);
    v.push_back(3);

    cout<<"Before sorting:"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }

    quick_sort(v,0,v.size()-1);
    cout<<"After sorting:"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }

    return 0;
}
