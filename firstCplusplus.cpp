#include <iostream>

using namespace std;

const double mileToKm = 1.609; 

inline double convert (int miles) { 
    return (double) (miles * mileToKm); 
}

int main(int argc, char const *argv[])
{

    int miles = 1; 
    while(miles != 0){  
        cin >> miles; 
        cout << "The miles you entered " << miles << " is converted to " << convert(miles) << " km " << endl;
    }

    return 0;
}
