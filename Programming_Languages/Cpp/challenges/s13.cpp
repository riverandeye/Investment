#include <iostream>
#include <string>

using namespace std;

class Movie
{
private:
    static int total_num;
    string name;
    int rating;
    long int watched;
    friend class Movies;
};

class Movies{
private:
    static int Movie;

}
