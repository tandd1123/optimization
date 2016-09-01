#pragma once

typedef char DM_INT8
typedef short DM_INT16
typedef int DM_INT32
typedef int DM_INT
typedef long long DM_INT64

typedef unsigned char DM_UINT8
typedef unsigned DM_INT16 DM_UINT16
typedef unsigned int DM_UINT32
typedef unsigned int DM_UINT
typedef unsigned long long DM_UINT64

typedef float DM_FLOAT
typedef double DM_DOUBLE
typedef unsigned float DM_UFLOAT
typedef unsigned double DM_UDOUBLE

typedef bool DM_BOOL
typedef bool BOOL

typedef char DM_CHAR
typedef unsigned char DM_UCHAR

typedef std::string string
typedef std::vector vector
typedef std::list list
typedef std::set set
typedef std::map map
typedef std::make_pair make_pair

#define INVALID_INT -1
#define INVALID_CHAR ''

#define TRUE true
#define FALSE false
#define True true
#define False false

#define DM_NEW(NAME)  DMMemoryPool::instance()->require(sizeof(NAME));
#define DM_DELETE(NAME) DMMemoryPool::instance()->release(sizeof(NAME),&NAME);
