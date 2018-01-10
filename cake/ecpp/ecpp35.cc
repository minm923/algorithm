#include <iostream>

// virtual function
class Charactor
{
public:
    virtual int healthValue() const
    {
        std::cout << "charactor" << std::endl;
    }
};

class BaShen : public Charactor
{
public:
    virtual int healthValue() const
    {
        std::cout << "BaShen" << std::endl;
    }

};

// Non-Virtual Interface
class GameChatactor
{
public:    
    int healthValue () const
    {
        // do something before
        int retVal = doHealthValue();
        // do something after
        return retVal;
    }

private:    
    virtual int doHealthValue() const
    {
        std::cout << "GameChatactor doHealthValue" << std::endl;
    }

};

class Mike : public GameChatactor
{
private:
    virtual int doHealthValue() const
    {
        std::cout << "Mike doHealthValue" << std::endl;
        return 0;
    }
};

// Function Pointer -> Strategy
class MovieCharactor;

int CalcMovieCharactorHealth(const MovieCharactor& c)
{
    std::cout << "CalcMovieCharactorHealth" << std::endl;
}

class MovieCharactor
{
public:    
    typedef int (*HealthCalcFunc) (const MovieCharactor&);
    explicit MovieCharactor(HealthCalcFunc hcf = CalcMovieCharactorHealth)
        : healthFunc(hcf)
    {

    }

    int healthValue() const
    {
        healthFunc(*this);
        return 0;
    }

private:    
    HealthCalcFunc healthFunc;
};

// boost::function -> Strategy
#include <boost/function.hpp>
#include <boost/bind.hpp>

class VideoCharactor;

int CalVideoCharactorHealth(const VideoCharactor& c)
{
    std::cout << "CalVideoCharactorHealth" << std::endl;
}

class VideoCharactor
{
public:
    typedef boost::function<int (const VideoCharactor&)> HealthFunc;
    explicit VideoCharactor(HealthFunc hfc = CalVideoCharactorHealth)
        : healthFunc(hfc)
    {
    }

    int healthValue() const
    {
        healthFunc(*this);
        return 0;
    }

private:    
    HealthFunc  healthFunc;
};

int main(int argc, char* argv[])
{
    GameChatactor* pp = new Mike;
    pp->healthValue();

    Mike p1;
    p1.healthValue();

    MovieCharactor mm(CalcMovieCharactorHealth);
    mm.healthValue();

    VideoCharactor vv;
    vv.healthValue();

    return 0;
}
