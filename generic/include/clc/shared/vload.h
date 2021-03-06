#define _CLC_VLOAD_DECL(PRIM_TYPE, VEC_TYPE, WIDTH, ADDR_SPACE) \
  _CLC_OVERLOAD _CLC_DECL VEC_TYPE vload##WIDTH(size_t offset, const ADDR_SPACE PRIM_TYPE *x);

#define _CLC_VECTOR_VLOAD_DECL(PRIM_TYPE, ADDR_SPACE) \
  _CLC_VLOAD_DECL(PRIM_TYPE, PRIM_TYPE##2, 2, ADDR_SPACE) \
  _CLC_VLOAD_DECL(PRIM_TYPE, PRIM_TYPE##3, 3, ADDR_SPACE) \
  _CLC_VLOAD_DECL(PRIM_TYPE, PRIM_TYPE##4, 4, ADDR_SPACE) \
  _CLC_VLOAD_DECL(PRIM_TYPE, PRIM_TYPE##8, 8, ADDR_SPACE) \
  _CLC_VLOAD_DECL(PRIM_TYPE, PRIM_TYPE##16, 16, ADDR_SPACE)

#define _CLC_VECTOR_VLOAD_PRIM1(PRIM_TYPE) \
  _CLC_VECTOR_VLOAD_DECL(PRIM_TYPE, __private) \
  _CLC_VECTOR_VLOAD_DECL(PRIM_TYPE, __local) \
  _CLC_VECTOR_VLOAD_DECL(PRIM_TYPE, __constant) \
  _CLC_VECTOR_VLOAD_DECL(PRIM_TYPE, __global) \

#define _CLC_VECTOR_VLOAD_PRIM() \
    _CLC_VECTOR_VLOAD_PRIM1(char) \
    _CLC_VECTOR_VLOAD_PRIM1(uchar) \
    _CLC_VECTOR_VLOAD_PRIM1(short) \
    _CLC_VECTOR_VLOAD_PRIM1(ushort) \
    _CLC_VECTOR_VLOAD_PRIM1(int) \
    _CLC_VECTOR_VLOAD_PRIM1(uint) \
    _CLC_VECTOR_VLOAD_PRIM1(long) \
    _CLC_VECTOR_VLOAD_PRIM1(ulong) \
    _CLC_VECTOR_VLOAD_PRIM1(float) \
        
#ifdef cl_khr_fp64
#define _CLC_VECTOR_VLOAD() \
  _CLC_VECTOR_VLOAD_PRIM1(double) \
  _CLC_VECTOR_VLOAD_PRIM()
#else
#define _CLC_VECTOR_VLOAD() \
  _CLC_VECTOR_VLOAD_PRIM()
#endif

_CLC_VECTOR_VLOAD()
