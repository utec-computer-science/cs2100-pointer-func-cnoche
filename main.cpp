#include <iostream>
using namespace std;

void * _bubblesort_(
	void * _array_, 
	void (*_puntero_) (void *, int _i, int _k),
	int _tam_
){
	for (int i = 0; i < _tam_ ; i ++)
		for(int k = 0; k < _tam_-1; k++)
			_puntero_(_array_,k,k+1);
	return _array_;
}

void  _b_int_ (void * _vector_, int _i,int _k){
    int *data = reinterpret_cast<int*>(_vector_);
    if (data[_i]>data[_k])
    {
        swap(data[_i],data[_k]);
    }
}

void  _b_float_ (void * _vector_, int _i,int _k){
    float *data = reinterpret_cast<float*>(_vector_);
    if (data[_i]>data[_k])
    {
        swap(data[_i],data[_k]);
    }
}

void  _b_double_ (void * _vector_, int _i,int _k){
    double *data = reinterpret_cast<double*>(_vector_);
    if (data[_i]>data[_k])
    {
        swap(data[_i],data[_k]);
    }
}

void  _b_char_ (void * _vector_, int _i,int _k){
    char *data = reinterpret_cast<char*>(_vector_);
    if (data[_i]>data[_k])
    {
        swap(data[_i],data[_k]);
    }
}

template <typename T>
void print_arr(T arr, int size)
{
    for (auto i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


int main(){
	int i = 0;
	int _array_1 [5] = {2,20,7,108,9}; // RANDOMS
	float _array_2 [5] = {4.4,5.4,9.1,7.4,2.2};
	double _array_3 [5] = {3.0,8.0,2.0,4.0,15.0};
	char _array_4 [6] = {'k','a','r','l','o','s'};

	_bubblesort_(_array_1,_b_int_,5);	
    print_arr(_array_1,5);
	_bubblesort_(_array_2,_b_float_,5);
	print_arr(_array_2,5);
	_bubblesort_(_array_3,_b_double_,5);
	print_arr(_array_3,5);
	_bubblesort_(_array_4,_b_char_,6);
	print_arr(_array_4,6);

    return 0;
}