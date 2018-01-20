#include <iostream>
#include <string>
#include <string.h>

char GetOneChar()
{
    char a = 'a';
    return a;
}

class TextBlock
{
public:    
    explicit TextBlock(const std::string& sText)
        :sText_(sText)
    {

    }

    const int GetLength() const
    {
        return sText_.size();
    }

    int GetLength()
    {
        return static_cast<const TextBlock&>(*this).GetLength();
    }

    const char& operator[] (const size_t i) const
    {
        return sText_[i];
    }

    char& operator[] (const size_t i)
    {
        return const_cast<char&>(static_cast<const TextBlock&>(*this)[i]);
    }

private:    
    std::string sText_;
};

class TextBlock2
{
public:
    explicit TextBlock2(char const * const src, size_t iLen)
        : pc_(NULL),
          iLen_(iLen)
    {
        pc_ = new char[iLen];
        memcpy(pc_, src, iLen);
    }

    // rule of three
    TextBlock2(const TextBlock2& that)
    {
        if (this != &that)
        {
            pc_   = new char[that.iLen_];
            iLen_ = that.iLen_;
            memcpy(pc_, that.pc_, that.iLen_);
        }
    }

    TextBlock2& operator=(const TextBlock2& that)
    {
        TextBlock2 tmp(that);
        char * pTmp = NULL;
        size_t iTmp = 0;

        pTmp   = tmp.pc_;
        tmp.pc = pc_;
        pc_    = pTmp;

        iTmp      = tmp.iLen_;
        tmp.iLen_ = iLen_;
        iLen_     = iTmp;
    }

    ~TextBlock2()
    {
        delete[] pc;
    }

private:
    char * pc_;
    size_t iLen_;
};

int main(int argc, char* argv[])
{
    // 返回内置类型赋值非法
    //GetOneChar() = 'c';
    std::string s("sfasdfadfasdfadf");

    TextBlock book(s);
    std::cout << "Book Length : "   << book.GetLength() << std::endl;

    std::cout << "Book Character: " << book[2] << std::endl;

    return 0;
}

