#include <iostream>
#include <vector>

template<typename Iter>
double arithMean(Iter begin, Iter end) {
    double sum{0};
    int n{0};

    while(begin != end) {
        sum += *begin++;
        ++n;
    }

    return sum / n;
}

template<typename vector_type>
vector_type arithMean2 (std::vector<vector_type> vec) {
    vector_type sum{0};
    int n{0};
    for(size_t i{0}; i < vec.size(); i++) {
        sum = sum + vec[i];
        n++;
    }
    sum = sum / n;
    return sum;
}

template <typename Coord>
class Dot {

public:
    Coord xVal{0};
    Coord yVal{0};
    Dot() {
        this->xVal = 0;
        this->yVal = 0;
    }
    Dot(Coord val) {
        this->xVal = val;
        this->yVal = val;
    }
    Dot(Coord xVal, Coord yVal) {
        this->xVal = xVal;
        this->yVal = yVal;
    }

    Dot operator+(const Dot rhs) {
        Coord xSum = this->xVal + rhs.xVal;
        Coord ySum = this->yVal + rhs.yVal;
        Dot newDot{xSum, ySum};
        return  newDot;
    }

    Dot operator=(Coord value) {
        this->xVal = value;
        this->yVal = value;
//        Dot newDot{value, value};
//        return newDot;
    }
    Dot operator/(Coord value) {

        Dot newDot;
        newDot.xVal = this->xVal / value;
        newDot.yVal = this->yVal / value;
        return newDot;
    }
};


int main()
{
    std::vector<float> vF{0, 13.5136, 643.346, 743.4};
    std::vector<int> vI{1, 2, 3, 4, 5};

    std::vector<Dot<double>> vec_of_dots = {{3.4, 5.6}, {6.14, 6.56}, {-4.37, 1.53}};


//    std::cout<<"answer1: " <<arithMean(vF.begin(), vF.end())<<std::endl;
//    std::cout<<"answer2: " <<arithMean(vI.begin(), vI.end())<<std::endl;

    std::cout<<"answer3: " <<arithMean2(vF)<<std::endl;
    std::cout<<"answer4: " <<arithMean2(vI)<<std::endl;

    Dot<double> midDot =  arithMean2(vec_of_dots);

    std::cout<<"answer vec_of_dots: ("<<midDot.xVal<<", "<<midDot.yVal<<")."<<std::endl;

    return 0;
}
