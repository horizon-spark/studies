#include <iostream>
#include <vector>
#include <memory>

// int main()
// {
//     int n,i=1;
//     std::cout << "Insert size of the vector: ";
//     std::cin >> n;
//     std::vector<int> vector(n);
    
//     for (auto iter = vector.begin();iter != vector.end();iter++)
//     {
//         std::cout << "Insert element number " << i << ":";
//         std::cin >> *iter;
//         i++;
//     }
//     for (int j=0;j<n;j++)
//     {
//         std::cout << vector[n-j-1] << "\t";
//     }
// }

// int main()
// {
//     unsigned size{},sum{0};
//     std::cout << "Insert vector size: ";
//     std::cin >> size;
//     auto ptr{std::make_unique<std::vector<int>>(size)};
//     for (int i=0;i<size;i++)
//     {
//         (*ptr)[i] = i * i;
//         sum += (*ptr)[i];
//     }
//     std::cout << "Total sum of the elements: " << sum << std::endl;
// }

int main()
{
    int m,n;
    std::cin >> m >> n; 
    std::vector<std::vector<int>> main_vec(m,std::vector<int>(n));
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            std::cin >> main_vec[i][j];
        }
    }

    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            std::cout << main_vec[i][j] << "\t";
            if (i==m-1) 
            {
                std::cout << std::endl;
            }
        }
    }

}