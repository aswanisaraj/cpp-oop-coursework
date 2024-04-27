#include <iostream>

using namespace std;

void getPosNeg(const int ar[], const int n_ar, int *&pos, int &n_pos, int *&neg, int &n_neg)
{

    for (int i = 0; i < n_ar; i++)
    {
        if (ar[i] > 0)
        {
            n_pos++;
        }
        else
        {
            n_neg++;
        }
    }

    pos = new int[n_pos];

    neg = new int[n_neg];

    int j=0;
    int k=0;

    for (int i = 0; i < n_ar; i++)
    {

        if (ar[i] > 0)
        {
            pos[j] = ar[i];
            j++;
        }
        else
        {
            neg[k] = ar[i];
            k++;
        }
    }
}

int main()
{
    int array[] = {1, -7, -12, 14, -16, 20, -23, 25, -28, 30};
    int n_ar = 10;

    int *pos = nullptr;
    int *neg = nullptr;

    int n_pos = 0, n_neg = 0;

    getPosNeg(array, n_ar, pos, n_pos, neg, n_neg);

    cout << "Positive values: " << endl;
    for (int i = 0; i < n_pos; i++)
    {
        cout << pos[i] << " ";
    }
    cout << endl;

    cout << "Negative values: " << endl;
    for (int i = 0; i < n_neg; i++)
    {
        cout << neg[i] << " ";
    }
    cout << endl;

    delete [] pos;
    delete [] neg;


    return 0;
}
