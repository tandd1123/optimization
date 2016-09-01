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

	DM_UINT init_memory_pool(DM_UINT size);

	DM_CHAR* require(DM_UINT size);

	void release(DM_UINT size,DM_CHAR* block);

private:
	void init_page();

	DM_CHAR* alloc_memory(DM_UINT size);

private:
	DM_UINT _size;
	DM_BOOL _unused;
	DM_CHAR* _head;
	DM_CHAR* _free;
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

	DM_CHAR* require();

	void release(DM_CHAR* block);

private:
	DM_UINT _block_size;
	vector<DMMemoryBlock*> _block;
};

class DMMemoryBlock
{
public:
	DMMemoryBlock();

	DM_CHAR* require(DM_UINT size);

	DM_BOOL release(DM_CHAR* block);

	DM_BOOL get_block_state();

private:
	void make_block(DM_UINT size);
	
private:
	DM_BOOL _used;
	DM_CHAR* _block;
};
