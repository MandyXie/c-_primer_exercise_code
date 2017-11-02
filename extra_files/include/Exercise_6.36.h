string (&func(string (&arr_str)[10]))[10]

using arrT = string[10];
arrT& func1(arrT &arr);

auto func2(arrT &arr) -> string(&)[10];

string arrS[10];
decltype(arrS)& func3(ArrT &arr)；


