#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename Func>

void iter(T *arr, size_t len, Func f){
	for (size_t i = 0; i < len; i++){
		f(arr[i]);
	}
}

#endif