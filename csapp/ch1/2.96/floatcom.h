typedef unsigned float_bits;

float u2f(unsigned x);
unsigned f2u(float f);
int is_float_equal(float_bits f1,float f2);
int is_int_equal(int i1,int i2);
int is_nan(float_bits fb);
int is_inf(float_bits fb);
int testFun(float_bits(*fun1)(float_bits),float(*fun2)(float));
int testFunInt(int(*fun1)(float_bits),int(*fun2)(float));
