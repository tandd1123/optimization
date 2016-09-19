//=============================================================================
/* 
*  File: DMMemoryPool.h
*
*  Author: bing
*
*  Date: 2016-08-12
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

#pragma once

/*
*-------------------*
|					|
|					|        *----------*		 *----------*
|	  memorypool	|------->|memorypage|------->|memorypage|-------> ... + sizeof(DM_UINT) = 4 byte
|					|		 |----------|		 |----------|
|					|		 |		    |		 |		    |
*-------------------*		 |		    |		 |		    |
							 | 8 - byte |		 | 12 - byte|
	*--------------*		 |		    |		 |		    |
	|			   |		 |		    |		 |		    |
	|     block	   |<------- |		    |		 |		    |
	|			   |		 |		    |		 |		    |
	*--------------*		 *----------*		 *----------*
*/
#include "DMaker.h"

class DMMemoryPage;
class DMMemoryBlock;

class DMMemoryPool
{
	friend class DMMemoryBlock;
public:
	static DMMemoryPool* instance();
    
    DMMemoryPool();
    
	DM_UINT init_memory_pool(DM_UINT size);

    template<typename T>
	T** require(T** src,DM_UINT size);
    
    template<typename T>
	void release(T** block, DM_UINT size);

    DM_UINT get_max_block(){return _max_block_size;};

private:
	void init_page();

	DM_CHAR** alloc_memory(DM_UINT size);

private:
	DM_UINT _size;
	DM_UINT _unused;
	DM_CHAR** _head;
	DM_CHAR** _free;
    DM_UINT _max_block_size;
	vector<DMMemoryPage*> _page;
	static DMMemoryPool* _instance;
	static ACE_Thread_Mutex _lock;
	ACE_Thread_Mutex _mutex_lock;
};

class DMMemoryPage
{
public:
	DMMemoryPage();

	void set_block_size(DM_UINT size);

	DM_UINT get_block_size();

	DM_CHAR** require();

	DM_BOOL release(DM_CHAR** block);

private:
	DM_UINT _block_size;
	vector<DMMemoryBlock*> _block;
};

class DMMemoryBlock
{
public:
	DMMemoryBlock();

	DM_CHAR** require(DM_UINT size);

	DM_BOOL release(DM_CHAR** block);

	DM_BOOL get_block_state();

private:
	void make_block(DM_UINT size);
	
private:
	DM_BOOL _used;
	DM_CHAR** _block;
};

#include "DMMemoryPool.inl"

#define DM_NEW(SRC,LENGTH)  DMMemoryPool::instance()->require(&SRC,LENGTH)
#define DM_DELETE(SRC,LENGTH) DMMemoryPool::instance()->release(&SRC,LENGTH)
#define DM_MAX_MEMORY_BLOCK DMMemoryPool::instance()->get_max_block()
 
