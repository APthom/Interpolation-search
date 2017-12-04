#include<iostream>
#define A_S(a) sizeof(a)/sizeof(a[0])
#include<vector>
using namespace std;

int Interpolation(vector<int> a, int Find)
{
    int low = 0;
    int high = a.size();
    int mid;
    while(a[low] <= Find && a[high] >= Find)
    {
        mid = low + ((Find - a[low]) * (high - low))/
                                     (a[high] - a[low]);
        if(a[mid] > Find)
            high = mid - 1;
        else if(a[mid] < Find)
            low = mid + 1;
        else
            return mid;
    }

    if(a[low] == Find)
        return low;
    else
        return -1;
}


int main()
{
    //int i[14] = {11,12,15,20,25,30,45,56,64,78,95,105,200,421};

    vector<int> data;
    for(int n = 0; n < 100; n++ ){
        int number = n*2;
        data.push_back(number);
    }
    for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
            cout<<endl;
        }

    int tofind;
    cout<<"Enter number to find : ";
    cin>>tofind;
    cout<<"Position of number : "<<Interpolation(data, tofind);

    return 0;
}
