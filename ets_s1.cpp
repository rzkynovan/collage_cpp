#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int i, j, k, max;
    int n, nx = 0, ny = 0;
    cout << "Masukkan banyaknya data : ";
    cin >> n;
    int array[n];
    for (i = 0; i < n; i++)
    {
        cout << "data ke - " << i + 1 << " : ";
        cin >> array[i];
    }

    int X[n], Y[n];

    for (i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            nx += 1;
            X[nx] = array[i];
        }
        else
        {
            ny += 1;
            Y[ny] = array[i];
        }
    }

    cout << endl
         << "Data X : ";
    for (i = 1; i <= nx; i++)
    {
        cout << X[i] << " ";
    }

    cout << endl
         << "Data Y : ";
    for (i = 1; i <= ny; i++)
    {
        cout << Y[i] << " ";
    }

    for (i = 1; i <= nx; i++)
    {
        for (j = 1; j <= nx; j++)
        {
            if (X[j] > X[i])
            {
                max = X[j];
                X[j] = X[i];
                X[i] = max;
            }
        }
    }
    for (i = 1; i <= ny; i++)
    {
        for (j = 1; j <= ny; j++)
        {
            if (Y[j] > Y[i])
            {
                max = Y[j];
                Y[j] = Y[i];
                Y[i] = max;
            }
        }
    }
    cout << endl;
    cout << "Data X urut : ";
    for (i = 1; i <= nx; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
    cout << "Data Y urut : ";
    for (i = 1; i <= ny; i++)
    {
        cout << Y[i] << " ";
    }

    float b, w;
    int a;
    w = ((float)(nx) + 1) / 4;
    a = trunc(w);
    b = w - a;

    cout << endl;
    cout << "Kuartil 1 dari X : " << X[a] + (b * (X[a + 1] - X[a])) << endl;

    w = (3 * ((float)(ny) + 1)) / 4;
    a = trunc(w);
    b = w - a;
    cout << "Kuartil 3 dari Y : " << Y[a] + (b * (Y[a + 1] - Y[a])) << endl;

    float sumx = 0, sumy = 0, xbar, ybar, m;
    if (nx - ny == 1)
    {
        m = nx - 1;
    }
    else
    {
        m = ny - 1;
    }

    for (i = 1; i <= m; i++)
    {
        sumx = sumx + X[i];
        sumy = sumy + Y[i];
    }
    xbar = sumx / m;
    ybar = sumy / m;
    cout << "Rata-rata ";
    cout << "X : " << xbar << " dan Y : " << ybar;

    float stdevx, stdevy, pembilangx, pembilangy;
    for (i = 1; i <= m; i++)
    {
        pembilangx = pembilangx + ((X[i] - xbar) * (X[i] - xbar));
        pembilangy = pembilangy + ((Y[i] - ybar) * (Y[i] - ybar));
    }

    stdevx = sqrt(pembilangx / (m - 1));
    stdevy = sqrt(pembilangy / (m - 1));

    cout << endl;
    cout << "Standar deviasi X : " << stdevx << " dan "
         << "Y : " << stdevy;

    float cor, pembilang, penyebut;
    for (i = 1; i <= m; i++)
    {
        pembilang = pembilang + ((X[i] - xbar) * (Y[i] - ybar));
    }
    penyebut = (m - 1) * stdevx * stdevy;
    cor = pembilang / penyebut;
    cout << endl;
    cout << "korelasi antara X dan Y sebesar : " << cor;

    return 0;
}
