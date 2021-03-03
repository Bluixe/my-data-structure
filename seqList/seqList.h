#ifndef SEQLIST_H
#define SEQLIST_H
template<class T> 
class list
{
public:
    virtual void insert(int i, const T& x)=0;
    virtual void remove(int i)=0;
    virtual T visit(int i)const=0;
    virtual int find(const T& x)const=0;
    virtual void clear()=0;
    virtual int length()const=0;
    template<class VST>
    virtual void traverse(VST& visit)const=0;
    virtual ~list()=0;
};

class spaceError{};
class outBound{};

template<class T>
class seqList
{
private:
    T *data = nullptr;
    int maxSize = 0;
    int currentLength = 0;
public:
    seqList()
    {
        data = new T[5];
        if(data == nullptr) throw spaceError();
        maxSize = 5;
        currentLength = 0;
    }
    void insert(int i, const T& x)
    {
        if(i<0||i>currentLength) throw outBound();
        if(currentLength+1>maxSize) doubleSpace();
        for(int j=currentLength; j>i; j--)
        {
            data[j] = data[j-1];
        }
        data[i] = x;
        currentLength++;
    }
    void remove(int i)
    {
        if(i<0||i>currentLength) throw outBound();
        for(int j=i; j<currentLength-1; j++)
        {
            data[j] = data[j+1];
        }
        currentLength--;
    }
    T visit(int i)const
    {
        if(i<0||i>currentLength) throw outBound();
        return data[i];
    }
    int find(const T& x)const
    {
        if(i<0||i>=currentLength) throw outBound();
        
    }
    void clear()
    {
        currentLength = 0;
    }
    int length()const
    {
        return currentLength;
    }
    void doubleSpace()
    {
        T *temp = new T[maxSize*2];
        if(temp == nullptr) throw spaceError();
        for(int i=0; i<currentLength; i++)
        {
            temp[i] = data[i];
        }
        delete [] temp;
        maxSize*=2;
    }
    template<class VST>
    void traverse(VST& visit)const
    {
        for(int i=0; i<currentLength; i++)
        {
            visit(data[i]);
        }
    }
    ~seqList()
    {
        delete [] data;
    }
    
};
#endif